#include<iostream>
#include<vector>
#include<queue>

using namespace std;
void addEdge(vector<int> adj_list[],int u,int v){
    adj_list[u].push_back(v);
}

void printGraph(vector<int>adj_list[],int v){
    for(int i=0;i<v;i++){
        for(auto x:adj_list[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}


vector<int> topoSort(int V, vector<int> adj[])
	{
	    // code here
	    vector<int> ans;
	    queue<int>q;

	    vector<int> indegree(V, 0);
	    for(int i=0; i<V; i++){
	        for(auto x: adj[i]){

	            indegree[x]++;
	        }
	    }

	    for(int i=0; i<V; i++){
	        if(indegree[i] == 0)
	            q.push(i);
	    }

	    while(! q.empty()){
	        int u = q.front();
	        q.pop();
	        ans.push_back(u);

	        for(auto v: adj[u]){
	            indegree[v]--;
	            if(indegree[v] == 0)
	                q.push(v);
	        }
	    }

	    return ans;
	}
int main(){

    int ver,n;
    vector<int>res;
    cout<<"Enter the number of vertex : ";
    cin>>ver;
    cout<<"Enter the number of Edges : ";
    cin>>n;
    int u,v;
    vector<int>adj_list[ver];
    for(int i=0;i<n;i++){
        cin>>u>>v;
        addEdge(adj_list,u,v);
    }
    cout<<"Adjacency list : ";
    printGraph(adj_list,ver);
    cout<<"Topological Sort : "<<endl;
    res = topoSort(ver,adj_list);
    for(int i=0;i<ver;i++){
        cout<<res[i]<<" ";
    }

return 0;
}
