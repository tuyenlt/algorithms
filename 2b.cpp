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

vector<int> all;
int curr = 0;

void gen(int k,int i,int first,int second){
    if(i == k){
        all.push_back(curr);
        return;
    }    
    if(first == -1){
        for(int j=1;j<10;j++){
            curr = j;
            gen(k,i+1,j,-1);
            curr /= 10;
        }
        return ;
    }
    if(second == -1){
        for(int j=0;j<10;j++){
            curr = curr * 10 + j;
            if(j == first){
                gen(k,i+1,first,-1);
            }else{
                gen(k,i+1,first,j);
            }
            curr /= 10;
        }
    }else{
        curr = curr * 10 + first;
        gen(k,i+1,first,second);
        curr /= 10;
        curr = curr * 10 + second;
        gen(k,i+1,first,second);
        curr /= 10;
    }
}

// int bin_search(int val){
//     int l=0,r=all.size() -1,mid;
//     while(l <= r){
//         mid = (l + r) / 2;
//         if(all[mid] < val){
//             l = mid + 1;
//         }
//         if(all[mid] > val){
//             r = mid -1;
//         }
//         if(all[mid] == val)return mid;
//     }
//     return mid;
// }

void solve(){
    int n;
    cin >> n;
    for(int i=3;i<=10;i++){
        gen(i,0,-1,-1);
    }
    if(n <= 100){
        cout << n;
        return;
    }
    // for(auto it : all)cout << it << endl;
    sort(all.begin(),all.end());
    auto it = lower_bound(all.begin(),all.end(),n);
    if(*it == n){
        cout << it - all.begin() + 1 + 99;
    }else{
        cout << it - all.begin() + 99;
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