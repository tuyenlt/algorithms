#include<bits/stdc++.h>

using namespace std;
#define ll long long




void solve(){
    ll n,m;
    cin>>n>>m;
    ll a[n+1];
    for(ll i=1;i<=n;i++)cin>>a[i];
    ll b[n+1];
    b[0]=0;
    unordered_map<ll,ll> c;
    for(ll i=1;i<=n;i++){
        b[i]=(b[i-1]+a[i])%m;
        c[b[i]]++;
    }
    ll ans=c[0];
    //cout<<ans;
    for(auto x:c){
        ans+=(x.second-1)*(x.second)/2;
    }
    cout<<ans;
}

int main(){
    
    //freopen("/mnt/d/code/cpp/test/input.txt", "r", stdin);
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    ll t=1;
    //  cin>>t;
    while(t--){
        //cout<<tong("131231231231324124","100");
        solve();
        //cout<<endl;
    }   
}