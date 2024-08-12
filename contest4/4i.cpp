#include<bits/stdc++.h>

using namespace std;
#define ll long long


void solve(){   
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll p=0,q=0;
    for(ll i=0;i<n;i++){
        if(s[i]=='+')p++;
        else q++;
    }
    ll qp=q-p;
    ll m;
    //cout<<qp;
    cin>>m;
    while(m--){
        ll a,b;
        cin>>a>>b;
        if(a==b){
            if(qp==0){
                cout<<"YES";
            }else cout<<"NO";
            cout<<endl;
            continue;
        }
        if(a<b)swap(a,b);
        if((qp*b)%(a-b)!=0){
            cout<<"NO"<<endl;
            continue;
        }else{
            ll r=qp*b/(a-b);
            if(p+r<0||r>q){
                cout<<"NO"<<endl;
            }else cout<<"YES"<<endl;
        }
    }

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