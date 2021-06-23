

#include<bits/stdc++.h>
// #define ll long long
#define int long long
#define pb push_back 
#define mod 1000000007
using namespace std;

vector<int> v[900001];


void dfs(int src , int parent , vector<int> &ans)
{
   // cout<<child<<" ";

   int subords=0;


   for(auto child: v[src]){
      if(child != parent){
        dfs(child , src , ans);
        subords+=(1+ans[child]);
      }
   }

   ans[src] = subords;




}

void solve(){

  int n , num;
  cin>>n;

  vector<int> ans(n+1);

  for(int i=2;i<=n;i++){
      cin>>num;

      v[i].pb(num);
      v[num].pb(i);
  }

  dfs(1 , -1 , ans);

  for(int i=1;i<=n;i++) 
      cout<<ans[i]<<" ";
}

int32_t main(){

//   #ifndef ONLINE_JUDGE
//       freopen("input.txt", "r", stdin);
//       freopen("output.txt", "w", stdout);
//   #endif

    int T=1;
    // cin>>T;
    while(T--){
      solve();
    }

}



