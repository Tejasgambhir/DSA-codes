#include <bits/stdc++.h>
using namespace std;

class graph{
    public:
    unordered_map<int,list<int>>adj;
    void AddEdge(int u, int v ,bool direction){
        // direction = 0 ; undirected graph
        adj[u].push_back(v);
        if(!direction){
            adj[v].push_back(u);
        }
    }
    void printGraph(){
        for(auto i : adj){
            cout<<i.first<<"->";
            for(auto j : i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
};
int main()
{
int m ,n;
cout<<"Enter the number of nodes"<<endl;
cin>>m;
cout<<"Enter the number of edges"<<endl;
cin>>n;

graph g;
for(int i = 0 ; i<n;i++){
    int u,v;
    cin>>u >> v;
    g.AddEdge(u,v,1);
}
g.printGraph();

return 0;
}