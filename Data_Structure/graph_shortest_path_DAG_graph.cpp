#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<queue>

#define inf INT_MAX;
using namespace std;

stack<int>st;
void addEdge(vector<int>adj[],int u,int v,vector<int>weight[],int wt) {
    adj[u].push_back(v);
    weight[u].push_back(v) = wt;
}

void printGraph(vector<int>adj_list[],int v){
    for(int i=0;i<v;i++){
        for(auto x:adj_list[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}

void DFSrec(vector<int> adj, int u, vector<bool> &visited, stack<int>& stk)
{
   visited[u] = true;
   for( auto i : adj[u])
   {
     if(visited[i] == false)
       {
         DFSrec(adj,i,visited,stk)
       }
    }
    stk.push(u);
 }


void topological(vector<int> adj[], int v)
{
  vector<bool> visited(v,false);
  stack<int> stk;
  for(int i=0;i<v;i++)
  {
    if(visited[i]==false)
      {
        DFSrec(adj,i,visited,stk);
      }
   }
}

vector<int> shortestpath(vector<int> adj, stack<int>& stk, int source)
{
  int v = adj.size();
  vector<int> dist(v,INT_MAX);
  dist[source] = 0;

  while(stk.empty() != true)
  {
    int u = stk.top();
    stk.pop();
    for(auto i: adj[u])
    {
      if(dist[i] > dist[u]+weight(u,i))
        dist[i] = dist[u] + weight(u,i);
    }
}

return dist;
}


int main(){

    int ver,n;
    vector<int>res;
    cout<<"Enter the number of vertex : ";
    cin>>ver;
    cout<<"Enter the number of Edges : ";
    cin>>n;
    int u,v,wt;
    vector<int>adj_list[ver];
    vector<int>weight[ver];
    for(int i=0;i<n;i++){
        cin>>u>>v>>wt;
        addEdge(adj_list,u,v,weight,wt);
    }
    cout<<"Adjacency list : ";
    printGraph(adj_list,ver);
    cout<<"Topological Sort : "<<endl;
    topoSort(adj_list,ver);


return 0;
}

