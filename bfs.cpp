

#include<bits/stdc++.h>
// #define ll long long
// #define int long long
#define mod 1000000007
using namespace std;



void solve(){

    int n , m;
    cin>>n>>m;

    int vis[n+1];
    vector<int> adj[n+1];
    memset(vis , 0 , sizeof(vis));



    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //BFS

    vector<int> dist(n+1 , 0);


    queue<int> q;
    q.push(1);
    vis[1] = 1;



    while( !q.empty() ){

        int f = q.front(); q.pop();
        cout<<f<<" ";
        for(int i=0;i<adj[f].size();i++){
            int node = adj[f][i];
            if( !vis[node] ){
                vis[node] = 1;
                q.push(node);
                dist[node] = dist[f]+1;
            }
        }
    }


    cout<<"\nDistances : ";
    for (int i = 1; i <= n; ++i)
    {
        cout<<dist[i]<<" ";
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



