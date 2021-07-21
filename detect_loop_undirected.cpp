

#include<bits/stdc++.h>
// #define ll long long
// #define int long long
#define mod 1000000007
using namespace std;


bool isCyclic(vector<int> adj[] ,vector<int>& vis, int src , int parent, bool &ans){
           vis[src] = 1;
           
           for(int i=0;i<adj[src].size();i++){
               
               int child = adj[src][i];
               
               if( (vis[child] == 1 && child!=parent) || child == src ){
                   ans = true;
                   return ans;
               }
               
               if(!vis[child])
                   isCyclic(adj , vis , child , src,ans);
           }
           
           return ans;
    }

void solve(){
    int nodes , edges;

    cin>>nodes>>edges;

    vector<int> adj[nodes+1];

    for(int i=1;i<=nodes;i++){
        int u,v;
        cin>>u>>v;
        //directed
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    //detect cycle
    bool ans = false;

    vector<int> vis(nodes+1 , 0);


        for(int i=0;i<nodes;i++){
            if(!vis[i])
            isCyclic(adj , vis , i , -1, ans);
        }
        

    if(ans) cout<<"Yeah cycle found";
    else cout<<"Nope no cycle found";
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



