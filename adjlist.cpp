#include <iostream>
#include <unordered_map>
#include <list>
#include <string>
using namespace std;

template <typename T>

class Graph{
    public:
        unordered_map<T , list< pair<T , int >>> adj;

        //we have edge that has node(u) and neighbour(V)  and bidirectional(optional )
        void addEdge(T  u , T v  , int wt ,bool bidirectional = true){
            adj[u].push_back(make_pair(v, wt));

            if(bidirectional)
                adj[v].push_back( make_pair(u , wt) );
        }

        void print(){
            for(auto row : adj){
                cout<<row.first<<" :=  ";

                for(auto neighbour : row.second){
                    cout<<"("<<neighbour.first<<" ,"<<neighbour.second<<") -> ";
                }
                cout<<endl;
            }

        }


};


int main()
{
    Graph<string> g;
    g.addEdge("DC" , "RCB" , 40, false);
    g.addEdge("MI" , "CSK" , 40 , false);
    g.addEdge("SRH" , "PK" , 40 , false);
    g.addEdge("KKR" , "RCB" ,40 , false);
    g.addEdge("MI" , "DC" ,  40 , false);
    g.addEdge("DC" , "KKR" , 40 , false);
    g.print();
}