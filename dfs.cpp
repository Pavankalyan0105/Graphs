

#include<bits/stdc++.h>
// #define ll long long
// #define int long long
#define mod 1000000007
using namespace std;


const int N  = 1000;
int vis[N];
vector<int> adj[N];



void dfs(int u){

    vis[u] = 1;

    cout<<u<<"\n";

    for(int i=0;i<adj[u].size();i++){
        if( !vis[adj[u][i]])
            dfs(adj[u][i]);
    }

}

void solve(){

    int n , m;
    cin>>n>>m;

    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1;i<=m;i++){
        if(!vis[i])
            dfs(i);
    }

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



