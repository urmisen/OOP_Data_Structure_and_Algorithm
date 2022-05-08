#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<stack>

#define inf INT_MAX;
using namespace std;


void addEdge(vector<int>adj[],int u,int v,vector<int>weight[],int wt) {
    adj[u].push_back(v);
    weight[u][v] = wt;
}

void printGraph(vector<int>adj_list[],int v){
    for(int i=0;i<v;i++){
        for(auto x:adj_list[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}

void DFSRec(int s, stack<int>&st, vector<bool>&visited, vector<int> adj[]){
	    visited[s] = true;

	    for(auto v: adj[s]){
	        if(!visited[v]){
	            DFSRec(v, st, visited, adj);
	        }
	    }

	    st.push(s);
	}


vector<int> topoSort(int V, vector<int> adj[])
	{
	    // code here
	    stack<int>st;
	    vector<bool>visited(V, false);

	    for(int i=0; i<V; i++){
	        if(!visited[i]){
	            DFSRec(i, st, visited, adj);
	        }
	    }

	    vector<int>ans;
	    while(!st.empty()){
	        int x = st.top();
	        st.pop();
	        ans.push_back(x);
	    }

	    return ans;

	}

vector<int> shortestpath(vector<int> adj, int source,int V)
{
  int v = adj.size();
  vector<int> dist(v,INT_MAX);
  dist[source] = 0;

  stack<int>st;
  vector<bool>visited(V, false);

  for(int i=0; i<V; i++){
     if(!visited[i]){
         DFSRec(i, st, visited, adj);
	        }
	    }

  while(st.empty() != true)
  {
    int u = st.top();
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
    vector<vector<int>> weight;
    stack<int>st;
    for(int i=0;i<ver;i++){
        for(int j=0;j<ver;j++){
            weight[i]]j]=0;
        }
    }

    for(int i=0;i<n;i++){
        cin>>u>>v>>wt;
        addEdge(adj_list,u,v,weight,wt);
    }
    cout<<"Adjacency list : ";
    printGraph(adj_list,ver);
    cout<<"Topological Sort : "<<endl;
    shortestpath(adj_list,0,ver);

    //shortestpath(adj_list,stk,0);

return 0;
}

