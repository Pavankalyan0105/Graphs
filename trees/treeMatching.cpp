

#include<bits/stdc++.h> 
#define pb push_back
// #define ll long long
#define int long long
#define mod 1000000007
using namespace std;

set<int> st;

vector<int> arr[1000000];


void dfs(int child , int parent){

    // cout<<child<<" ";
    for(auto i:arr[child]){
        if(i != parent){
            dfs(i , child);

            //if i and child not in st then insert both

            if(st.find(i) == st.end() && st.find(child) == st.end())
            {
                st.insert(i);
                st.insert(child);
            }

        }

    }
}

void solve(){

    int edges , u, v;
    cin>>edges;

    for(int i=2;i<=edges;i++){
        cin>>u>>v;

        arr[u].pb(v);
        arr[v].pb(u);
    }

    dfs(1 , -1);

    cout<<st.size()/2;

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



