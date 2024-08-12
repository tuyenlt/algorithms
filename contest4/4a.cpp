#include<bits/stdc++.h>

using namespace std;
#define ll long long


void solve(){   
    pair<int,int>a[3];
    for(int i=0;i<3;i++){
        cin>>a[i].first>>a[i].second;
        if(a[i].first<a[i].second)swap(a[i].first,a[i].second);
    }
    sort(a,a+3);
    if(a[0].first==a[1].first&&a[1].first==a[2].first&&a[0].first==a[0].second+a[1].second+a[2].second){
        cout<<(ll)a[2].first*a[2].first;
        return;
    }
    if((a[0].first==a[1].first&&a[0].second+a[1].second==a[2].first&&a[2].first==a[2].second+a[0].first)){
        cout<<(ll)a[2].first*a[2].first;
        return;
    }
    if((a[0].first==a[1].second&&a[0].second+a[1].first==a[2].first&&a[2].first==a[2].second+a[0].first)){
        cout<<(ll)a[2].first*a[2].first;
        return;
    }
    if((a[0].second==a[1].first&&a[0].first+a[1].second==a[2].first&&a[2].first==a[2].second+a[0].second)){
        cout<<(ll)a[2].first*a[2].first;
        return;
    }
    if((a[0].second==a[1].second&&a[0].first+a[1].first==a[2].first&&a[2].first==a[2].second+a[0].second)){
        cout<<(ll)a[2].first*a[2].first;
        return;
    }
    cout<<0;
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