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
    int n,k;
    cin >> n >> k;
    int a[n];
    int min_num = LONG_LONG_MAX;
    for(int i=0;i<n;i++){
        cin >> a[i];
        min_num = min(min_num,a[i]);
    }
    vector<int> space;
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(a[i] == min_num){
            if(cnt > 0){
                space.push_back(cnt);
                cnt = 0;
            }
        }else{
            cnt++;
        }
    }
    if(cnt > 0){
        space.push_back(cnt);
    }
    int ans = 0;
    for(auto sp : space){
        ans += sp / (k-1) + (sp % (k-1) != 0);
    }
    cout << ans << endl;
    
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