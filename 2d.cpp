#include<bits/stdc++.h>
#include<sys/time.h>


using namespace std;
 
#define endl '\n'
#define int long long
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

vector<string> a;
unordered_map<string,bool> mp;
unordered_map<string,int> num1;
int n,m;

int count_1(string s){
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(s[i] == '1')cnt++;
    }
    return cnt;
}



bool cmp(string a,string b){
    return num1[a] < num1[b];
}

string find_child(string s){
    for(int i=a.size()-1;i>=0;i--){
        if(mp[a[i]])continue;
        bool is_child = true;
        for(int j=0;j<n;j++){
            if(s[j] == '0' && a[i][j] == '1'){
                is_child = false;
                break;
            }    
        }
        if(is_child){
            return a[i];
        }
    }
    return "NONE";
}

void remove_child(string s){
    mp[s] = true;
    string tmp = find_child(s);
    while(tmp != "NONE"){
        mp[tmp] = true;
        tmp = find_child(tmp);
    }
}

void solve(){
    cin >> n >> m;
    string tmp;
    for(int i=0;i<m;i++){
        cin >> tmp;
        a.push_back(tmp);
        num1[tmp] = count_1(tmp);
    }
    sort(a.begin(),a.end(),cmp);
    for(auto it : a){
        cout << it << endl;
    }
    int ans = 0;
    for(int i=a.size()-1;i>=0;i--){
        if(mp[a[i]])continue;   
        ans += num1[a[i]] + 1;
        remove_child(a[i]);
    }
    cout << ans - 1 << endl;
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