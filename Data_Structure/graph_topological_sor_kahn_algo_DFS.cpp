#include<iostream>
#include<vector>
#include<stack>


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


void DFSRec(int s, stack<int>&st, vector<bool>&visited, vector<int> adj[]){
	    visited[s] = true;

	    vector<int>data = adj[s];
	    for(auto v: data){
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
int main(){

    int ver,n;
    vector<int> res;
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
