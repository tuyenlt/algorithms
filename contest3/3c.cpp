#include<bits/stdc++.h>

using namespace std;
#define ll long long




void solve(){
    int n;
    cin>>n;
    int m=n/7;
    for(int i=0;i<=m;i++){
        if((n-i*7)%4==0){
            cout<<"Yes";
            return;
        }
    }
    cout<<"No";
}

int main(){
    
    //freopen("/mnt/d/code/cpp/test/input.txt", "r", stdin);
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--){
        //cout<<tong("131231231231324124","100");
        solve();
        //cout<<endl;
    }   
}