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

void test_answer(){
    int n,c;
    cin >> n >> c;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int dp[n];
    for(int i=0;i<n;i++){
        dp[i] = LONG_LONG_MAX;
    }
    dp[0] = 0;
    int pre[n];
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int jump_cost = (a[j] - a[i])*(a[j] - a[i]) + c;
            if(jump_cost + dp[i] < dp[j]){
                dp[j] = jump_cost + dp[i];
                pre[j] = i;
            }
        }
    }
    cout << dp[n-1] << endl;
    int tmp = n-1;
    while (pre[tmp] != 0)
    {   
        cout << tmp << " ";
        tmp = pre[tmp];
        /* code */
    }
    cout << 0 << endl;
    
}


void solve(){
    test_answer();
}


 
signed main(){
    
#ifndef ONLINE_JUDGE    
    // freopen("/home/tuyenlt/C++/Algorthims/input.txt", "r", stdin);
    freopen("/home/tuyenlt/C++/Algorthims/gen_input.txt", "r", stdin);
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