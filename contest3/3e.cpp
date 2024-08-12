#include<bits/stdc++.h>

using namespace std;
#define ll long long




void solve(){
    int n;
    cin>>n;
    vector<int>ans;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    vector<int>b(n+1);
    vector<int>c(n+2);
    b[0]=a[1];
    for(int i=1;i<=n;i++){
        b[i]=max(b[i-1],a[i]);
    }
    c[n+1]=INT_MAX;
    for(int i=n;i>=1;i--){
        c[i]=min(c[i+1],a[i]);
    }
    //ans.insert(c[1]);
    for(int i=1;i<=n;i++){
        if(b[i]==c[i])ans.push_back(b[i]);
    }
    cout<<ans.size()<<" ";
    int m=ans.size();
    if(101<m)m=101;
    for(int i=0;i<m;i++)cout<<ans[i]<<" ";
}

int main(){
    
    //freopen("/mnt/d/code/cpp/test/input.txt", "r", stdin);
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    int t=1;
    //  cin>>t;
    while(t--){
        //cout<<tong("131231231231324124","100");
        solve();
        //cout<<endl;
    }   
}