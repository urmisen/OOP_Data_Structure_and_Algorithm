#include<iostream>
#include<map>
#include<list>
#include<queue>

using namespace std;


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
