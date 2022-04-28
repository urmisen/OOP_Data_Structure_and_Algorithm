
#include<iostream>
#include<map>
#include<list>
#include<queue>

using namespace std;


// using vector

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


void bfs(vector<int>adj_list[],int src,vector<bool> &visited){

    queue<int> q;

    q.push(src);
    visited[src]=true;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<" ";
        for(int nbr : adj_list[node]){
            if(!visited[nbr]){
                q.push(nbr);
                //mark that neighbor as visited
                visited[nbr] = true;
            }
        }
    }
}

void BFS_dist(vector<int>adj_list[],int v, int src){
    vector<bool> visited(v+1,false);
    int cnt=0;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            bfs(adj_list,i,visited);
            cnt+=1;
        }
    }
    cout<<"\nNo of Dis-continuous graphs :"<<cnt<<endl;

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
    BFS_dist(adj_list,ver,src);


return 0;
}
