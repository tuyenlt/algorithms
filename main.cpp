#include<bits/stdc++.h>
#include<sys/time.h>
#include<cstdlib>

using namespace std;
 
#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int mxn = 2e5 + 1;


//
//.
//...
// .............................................................................................................................
//...
//.
//


const int SIZE = 1000;


void pre_process(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
}


long long min_energy_to_reach_end(int N, int C, const vector<int>& H) {
    vector<long long> dp(N, LLONG_MAX);
    dp[0] = 0;

    deque<int> dq;
    dq.push_back(0);

    for (int i = 1; i < N; ++i) {

        while (dq.size() > 1 && dp[dq[1]] + (long long)(H[i] - H[dq[1]]) * (H[i] - H[dq[1]]) <= dp[dq[0]] + (long long)(H[i] - H[dq[0]]) * (H[i] - H[dq[0]])) {
            dq.pop_front();
        }
        
        dp[i] = dp[dq.front()] + (long long)(H[i] - H[dq.front()]) * (H[i] - H[dq.front()]) + C;

        while (dq.size() > 1 && dp[i] + (long long)(H[i] - H[dq.back()]) * (H[i] - H[dq.back()]) <= dp[dq.back()] + (long long)(H[dq.back()] - H[dq[dq.size() - 2]]) * (H[dq.back()] - H[dq[dq.size() - 2]])) {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    return dp[N - 1];
}

void solve(){
    int n,c;
    cin >> n >> c;
    vector<int> h(n);
    // h[0] = 1;
    // for(int i=1;i<n;i++){
    //     h[i] = h[i-1] + (rand() % 10) + 1;
    // }
    for(int i=0;i<n;i++){
        cin >> h[i];
    }
    cout << min_energy_to_reach_end(n,c,h);
}


 
signed main(){
#ifndef ONLINE_JUDGE    
    freopen("/home/tuyenlt/C++/Algorthims/input.txt", "r", stdin);
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