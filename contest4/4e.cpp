#include<bits/stdc++.h>

using namespace std;
#define ll long long


void solve(){   
    ll n,k;
    cin>>n>>k;
    if(k==0){
        cout<<(ll)n*n;
        return;
    }
    ll ans=0;

    for(ll b=k+1;b<=n;b++){
        ll r=n/b*b;
        ll l=(k/b+(k%b!=0))*b;
        ans+=(r-l)/b*(b-k);
        ans+=b-k;
        ll p=r+k;
        if(n>=p)ans+=(n-p+1);
        //cout<<b<<" "<<ans<<endl;
    }
    cout<<ans;
}   

int main(){

    //freopen("/mnt/d/code/cpp/test/input.txt", "r", stdin);
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    ll t=1;
    // cin>>t;
    while(t--){
        //cout<<tong("131231231231324124","100");
        solve();
        cout<<endl;
    }   
}