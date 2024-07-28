#include<bits/stdc++.h>
#include<sys/time.h>


using namespace std;
 
#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int mxn = 2e5 + 1;
// #define ONLINE_JUDGE "off"

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

void solve(){
    int n,m;
    cin >> n >> m;
    map<int,int> mp;
    int max_vote1 = 0;
    int max_vote2 = 0;
    int tmp;
    for(int i=0;i<n;i++){
        cin >> tmp;
        mp[tmp]++;
    }
    for(auto it : mp){
         if(it.second > max_vote1){
            max_vote2 = max_vote1;
            max_vote1 = it.second;
        }
        else if(it.second > max_vote2 && it.second != max_vote1){
            max_vote2 = it.second;
        }
    }
    if(max_vote2 == max_vote1 || max_vote2 == 0){
        cout << "NONE\n";
        return;
    }
    for(auto it : mp){
        if(it.second == max_vote2){
            cout << it.first << endl;
            return ;
        }
    }
    cout << "NONE\n";
   
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