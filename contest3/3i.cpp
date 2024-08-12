#include<bits/stdc++.h>

using namespace std;
#define ll long long

bool check[1000001];
vector<int> sont;
void pre(){
    fill(check,check+1000001,false);
    check[0]=true;
    check[1]=true;
    for(int i=2;i<=1001;i++){
        if(!check[i]){
            for(int j=i*i;j<=1000001;j+=i)check[j]=true;
        }
    }
    for(int i=2;i<=1000001;i++)if(!check[i])sont.push_back(i);
}

void solve(){
    int n;
    cin>>n;
    int cnt=0;
    for(auto x:sont){
        if(x+x>n)break;
        if(!check[n-x]){
            cnt++;
        }
    }
    cout<<cnt;
}

int main(){
    
    //freopen("/mnt/d/code/cpp/test/input.txt", "r", stdin);
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    int t=1;
    //cin>>t;
    pre();
    while(t--){
        //cout<<tong("131231231231324124","100");
        solve();
        cout<<endl;
    }   
}