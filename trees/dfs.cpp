

#include<bits/stdc++.h>
// #define ll long long
// #define int long long
#define pb push_back 
#define mod 1000000007
using namespace std;

vector<int> v[1000];


void dfs(int child , int parent)
{
   cout<<child<<" ";


   for(auto i: v[child]){
      if(i != parent){
        dfs(i , child);
      }
   }

}

void solve(){

  int n , num;

  cin>>n;

  for(int i=2;i<=n+1;i++){
      cin>>num;

      v[i].pb(num);
      v[num].pb(i);
  }

  dfs(1 , -1);
}

int32_t main(){

  #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
  #endif

    int T=1;
    // cin>>T;
    while(T--){
      solve();
    }

}



