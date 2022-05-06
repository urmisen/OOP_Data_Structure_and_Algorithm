
#include<iostream>
#include<vector>
using namespace std;

void addEdge(vector<int>adj_list[],int u,int v){
    adj_list[u].push_back(v);
}

void  printGraph(vector<int>adj_list[],int v){
    for(int i=0;i<v;i++){
        for(auto  x: adj_list[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }

}
bool cycle(int s, vector<bool>&visited, vector<bool>&currVisited, vector<int> adj[]){
        visited[s] = true;
        currVisited[s] = true;

        for(auto x: adj[s]){
            if(!visited[x]){
                if(cycle(x, visited, currVisited, adj))
                    return true;
            }
            else if(visited[x] == true && currVisited[x] == true){
                return true;
            }
        }

        currVisited[s] = false;
        return false;
    }

    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool>visited(V, false), currVisited(V, false);
        for(int i=0; i<V; i++){
            if(!visited[i]){
                if(cycle(i, visited, currVisited, adj))
                    return true;
            }
        }

        return false;
    }
int main(){

    int ver,u,v,src,n;
    cout<<"Enter the number of vertex :";
    cin>>ver;
    vector<int>adj_list[ver];
    cout<<"Enter the number of edges :";
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>u>>v;
        addEdge(adj_list,u,v);
    }
    cout<<"Adjacent list :"<<endl;
    printGraph(adj_list,ver);

    cout<<"Enter the source vertex :";
    cin>>src;

    int ans=isCyclic(ver, adj_list);

    cout<<ans<<endl;

return 0;
}
