#include<bits/stdc++.h>
#include<sys/time.h>


using namespace std;
 
#define endl '\n'
// #define int long long
const int MOD = 1e9 + 7;
const int mxn = 2e5 + 1;
// #define ONLINE_JUDGE "off"
// const int SIZE = 200001;

//
//.
//...
// .............................................................................................................................
//...
//.
//



void pre_process(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
}

bool exits[1025] = {0};
bool has_degree[1025] = {0};
bool visited[1025] = {0};

void topologicalSortUtil(int v, vector<int> *adj,
                         vector<bool>& visited,
                         stack<int>& Stack)
{
    // Mark the current node as visited
    visited[v] = true;

    // Recur for all adjacent vertices
    for (int i : adj[v]) {
        if (!visited[i])
            topologicalSortUtil(i, adj, visited, Stack);
    }

    // Push current vertex to stack which stores the result
    Stack.push(v);
}

// Function to perform Topological Sort
vector<int> topologicalSort(vector<int> *adj, int V)
{   
    vector<int> ans;
    stack<int> Stack; // Stack to store the result
    vector<bool> visited(V, false);

    // Call the recursive helper function to store
    // Topological Sort starting from all vertices one by
    // one
    for (int i = 0; i < V; i++) {
        if (!visited[i] && exits[i] && !has_degree[i])
            topologicalSortUtil(i, adj, visited, Stack);
    }

    // Print contents of stack
    while (!Stack.empty()) {
        ans.push_back(Stack.top());
        Stack.pop();
    }
    return ans;
}


int n,m;

bool is_child(int a,int b){
    return (a | b) == a;
}

int bin_to_int(string b){
    int ans = 0;
    for(int i=0;i<n;i++){
        if(b[i] == '1'){
            ans += (1 << (n-i-1));
        }
    }
    return ans;
}
vector<int> topo;

int find_child(int node){
    for(auto it : topo){
        if(visited[it])continue;
        if(is_child(node,it)){
            return it;
        }
    }
    return -1;
}

int get_res(){
    memset(visited,0,1025*(sizeof(bool)));
    int ans = 0;
    for(auto it : topo){
        if(visited[it])continue;
        // cout << it << " ";
        visited[it] = true;
        int tmp = find_child(it);
        while(tmp != -1){
            cout << tmp << " ";
            visited[tmp] = true;
            tmp = find_child(tmp);
        }
        ans += __builtin_popcount(it) + 1;
    }
    return ans - 1;
}

void solve(){
    cin >> n >> m;
    vector<int> a;
    for(int i=0;i<m;i++){
        string s;
        cin >> s;
        int t = bin_to_int(s);
        exits[t] = 1;
        a.push_back(t);
    }
    vector<int> v[1025];
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            if(i == j)continue;
            if(is_child(a[i],a[j])){
                v[a[i]].push_back(a[j]);
                has_degree[j] = true;
            }
        }
    }
    topo =  topologicalSort(v,(1<<(n+1)));
    for(auto it : topo) cout  << it << " ";
    cout << endl;
    cout << get_res() << endl;
}


 
signed main(){
    
#ifndef ONLINE_JUDGE    
    freopen("/home/tuyenlt/C++/Algorthims/input.txt", "r", stdin);
    // freopen("/home/tuyenlt/C++/Algorthims/gen_input.txt", "r", stdin);
    freopen("/home/tuyenlt/C++/Algorthims/output.txt","w",stdout);
     struct timeval start, end;
    gettimeofday(&start, NULL);
#endif
    pre_process();
    bool loop = 0;
    if(loop){
        int t;
        cin >> t;
        cin.ignore();
        while(t--){
            solve();
        }
    }
    else solve();
#ifndef ONLINE_JUDGE
    gettimeofday(&end, NULL);
    // Calculating total time taken by the program.
    double time_taken;
    time_taken = (end.tv_sec - start.tv_sec) * 1e6;
    time_taken = (time_taken + (end.tv_usec -
                              start.tv_usec)) * 1e-6;
    cout << "\nTime taken by program is : " << fixed
         << time_taken << setprecision(6);
    cout << " sec" << endl;
#endif
    return 0;
}