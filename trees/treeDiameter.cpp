

#include<bits/stdc++.h>
// #define ll long long
#define int long long
#define mod 1000000007
using namespace std;

vector<int> h(999999 , 0);
int ans=0;

int dfs(vector<int> arr[] , int src  , int parent){

    // cout<<src<<" ";

    int h1=0 ,h2=0 , height=0; 

    for(auto child:arr[src]){
        if(child!=parent){
              height = dfs(arr , child , src);
              if(height > h1){
                    h2 = h1;
                    h1 = height;
              }      
              else if(height > h2) h2 = height;   
            }
        }
        h[src] = h1;
        // cout<<src<<"->"<<h1<<"+"<<h2<<endl;
        ans = max(ans , h1+h2);



        return 1+h[src];
}



void solve(){

    int n , u , v;
    cin>>n;

    vector<int> arr[n+1];
    
    for(int i=1;i<n;i++){
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }


    dfs(arr , 1 , -1);

    // for(int i=1;i<=n;i++) cout<<h[i]<<" ";

    cout<<ans<<" ";

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



