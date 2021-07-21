

#include<bits/stdc++.h>
// #define ll long long
#define int long long
#define mod 1000000007
using namespace std;


bool isCyclic(vector<int> adj[] , vector<int>& vis , vector<int>& inCallStack , int node , bool &ans){

        vis[node] = 1;
        inCallStack[node] = 1;

        for(auto child:adj[node]){
            if(inCallStack[child]){
                ans = true;
                return ans;
            }

            if(!vis[child]){
                isCyclic(adj , vis, inCallStack , child , ans);
            }
        }
    inCallStack[node] = 0;
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
    }


    //detect cycle
    bool ans = false;

    vector<int> vis(nodes+1 , 0);
    vector<int> inCallStack(nodes+1 , 0);


    for(int i=1;i<=nodes;i++){
        if(!vis[i]){
            isCyclic(adj , vis ,inCallStack , i , ans);
        }
    }

    if(ans) cout<<"Yeah cycle found";
    else cout<<"Nope no cycle found";
}

int32_t main(){

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }

}



