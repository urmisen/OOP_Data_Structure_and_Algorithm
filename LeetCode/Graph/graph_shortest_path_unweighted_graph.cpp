#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void addEdge(vector<int> adj_list[],int u,int v){
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
}

void printGraph(vector<int>adj_list[], int v){
    for(int i=0;i<v;i++){
        for(auto x:adj_list[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }

}

void bfs_Rec(vector<int>adj_list[],int src, vector<bool>&visited,vector<int>&dist){

    queue<int>q;
    visited[src]=true;
    q.push(src);
    while(!q.empty()){
        int node=q.front();
        q.pop();

        for(int nbr : adj_list[node]){
            if(!visited[nbr]){
                visited[nbr]=true;
                dist[nbr]=dist[src]+1;
                q.push(nbr);
            }
        }
    }


}

vector<int> bfs(vector<int>adj_list[],int src,int v){

    vector<bool>visited(v+1,false);
    vector<int>dist(v,0);
    for(int i=0;i<v;i++){
        if(!visited[i]){
            bfs_Rec(adj_list,i,visited,dist);
        }
    }

    for(int i=0;i<dist.size();i++){
        cout<<dist[i]<< " ";
    }
}

int main(){
    int ver,u,v;
    cout<<"Enter the number of vertices : ";
    cin>>ver;
    vector<int>adj_list[ver];
    int n;
    cout<<"Enter tyhe no of edges : ";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>u>>v;
        addEdge(adj_list,u,v);
    }
    cout<<"\nAdjacensy List :"<<endl;
    printGraph(adj_list,ver);

    int src;
    cout<<"Enter  the source :";
    cin>>src;
    bfs(adj_list,src,ver);

return 0;
}
