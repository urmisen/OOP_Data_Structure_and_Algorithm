#include<iostream>
#include<map>
#include<list>
#include<queue>

using namespace std;

//using map
/*
map<int,list<int>> l;

void addEdge(int x,int y){
    l[x].push_back(y);
    l[y].push_back(x);
}

void bfs(int src){
    map<int,int> visited;
    queue<int> q;

    q.push(src);
    visited[src]=true;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<" ";
        for(int nbr : l[node]){
            if(!visited[nbr]){
                q.push(nbr);
                //mark that neighbor as visited
                visited[nbr] = true;
            }
        }
    }
}



int main(){
    int u,v,n;
    cout<<"Enter the no of edges : ";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>u>>v;
        addEdge(u,v);
    }
    int src;
    cout<<"Enter  the source :";
    cin>>src;
    bfs(src);
return 0;
}
*/

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


void bfs(vector<int>adj_list[],int v,int src){
    vector<bool> visited(v+1,false);
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
    bfs(adj_list,ver,src);


return 0;
}
