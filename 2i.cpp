#include<bits/stdc++.h>
#include<sys/time.h>


using namespace std;
 
#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int mxn = 2e5 + 1;
// #define ONLINE_JUDGE "off"
const int SIZE = 200001;

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

unordered_map<int,bool> cp;

int componant = 0;

int link_to[SIZE];
int group_size[SIZE];
int find(int x){
    while(x != link_to[x])x=link_to[x];
    return x;
}
bool same(int a,int b){
    return find(a) == find(b);
}
void unite(int c,int d){
    int a = find(c);
    int b = find(d);
    if(group_size[a] < group_size[b])swap(a,b);
    group_size[a] += group_size[b];
    link_to[b] = a;
    cp[b] = false;
    cp[a] = true;
}
void unionSetValue(int n){
    for(int i=1;i<=n;i++){
        link_to[i] = i;
        group_size[i] = 1;
    }
}


void solve(){
    int n,m;
    cin >> n >> m;
    unionSetValue(n);
    vector<int> v[n+1];
    int a,b;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int c[n];
    for(int i=0;i<n;i++){
        cin >> c[i];
    }
    vector<string> ans;
    for(int i=n - 1;i >=0;i--){
        bool connected = false;      
        int cnt = 0;  
        for(int e : v[c[i]]){
            if(cp[find(e)] && !same(e,c[i])){
                unite(c[i],e);
                connected = true;
                cnt++;
            }
        }
        if(cnt > 1)componant -= (cnt-1);
        if(!connected){
            componant++;
            cp[c[i]] = true;
        }
        if(componant == 1)ans.push_back("YES");
        else ans.push_back("NO");
    }
    for(int i=ans.size()-1;i>=0;i--){
        cout << ans[i] << endl;
    }
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