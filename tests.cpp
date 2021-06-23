#include <bits/stdc++.h>
using namespace std;

void solve(){
    int t;
    cin>>t;
    string s;
    string s1="p" , s2;
    int n1=-1 , n2=-1;
    int n;

    for(int i=0; i<t;i++){
        cin>>s>>n;
        if(n > n1){
             s2 = s1; n2 =n1;
             s1 = s; n1 = n;
        }
        else if(n > n2){
            s2 = s; 
            n2 =n;
        }
    }
    cout<<s2;
}


int main()
{
	int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
}