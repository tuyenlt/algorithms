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

bool is_sorted(int *a, int n){
    for(int i=2;i<=2*n;i++){
        if(a[i] < a[i-1])return false;
    }
    return true;
}

void swap2(int *a, int n){
    for(int i=1;i<=n;i++){
        swap(a[i],a[n+i]);
    }
}

void swap1(int *a, int n){
    for(int i=1;i<=2*n;i+=2){
        swap(a[i],a[i+1]);
    }
}


void solve(){
    int n;
    cin >> n;
    int a[2*n + 1];
    int b[2*n + 1];
    int first_1 = 0;
    int first_2 = 0;
    for(int i=1;i<=2*n;i++){
        cin >> a[i];

    }
    memcpy(b,a,(2*n + 1)*sizeof(int));
    int time = 2*n;
    while(time--){
        if(is_sorted(a,n)){
            break;
        }
        swap1(a,n);
        first_1++;
        if(is_sorted(a,n)){
            break;
        }
        swap2(a,n);
        first_1++;
    }
    
    time = 2*n;
    while(time--){
        if(is_sorted(b,n)){
            break;
        }
        swap2(b,n);
        first_2++;
        if(is_sorted(b,n)){
            break;
        }
        swap1(b,n);
        first_2++;
    }
    if(first_1 == 4*n && first_2 == 4*n){
        cout << "-1\n";
    }else{
        cout << min(first_1,first_2) << endl;
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