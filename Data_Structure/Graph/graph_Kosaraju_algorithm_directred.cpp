#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void addEdges(vector<int>adj_list[],int u,int v){
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

void DFS_Rec(vector<int>adj_list[],int src,stack<int>&st, vector<bool> &visited){
    visited[src] = true;
    for(auto v:adj_list[src]){
        if(!visited[v]){
            DFS_Rec(adj_list,v,st,visited);
        }
    }
    st.push(src);
}

void Rev_DFS_Rec(vector<int>adj_list[],int src, vector<bool> &visited){
    visited[src] = true;
    cout<<src<<" ";
    for(auto v:adj_list[src]){
        if(!visited[v]){
            Rev_DFS_Rec(adj_list,v,visited);
        }
    }
}

int main(){
    int ver,n;
    cout<<"Enter the number of vertices :";
    cin>>ver;
    cout<<"Enter the number of edges :";
    cin>>n;
    vector<int>adj_list[ver];
    int u,v;
    for(int i=0;i<n;i++){
        cin>>u>>v;
        addEdges(adj_list,u,v);
    }

    //printGraph(adj_list,ver);
    //step-1 order the verteices in order of finishing order(topological sort)
    stack<int>st;
    vector<bool>visited(ver,false);
    for(int i=0;i<ver;i++){
        if(!visited[i]){
            DFS_Rec(adj_list,i,st,visited);
        }
    }

    //step-2 reverse the edges

    vector<int>transpose[ver];
    for(int u=0;u<ver;u++){
        visited[u]=false;
        for(auto v:adj_list[u]){
            transpose[v].push_back(u);
        }
    }
    //step-3 do DFS of reverse  graph in the order obtained in step-1
    while(!st.empty()){
        int node=st.top();
        st.pop();
        if(!visited[node]){
            cout<<"SCC : ";
            Rev_DFS_Rec(transpose,node,visited);
            cout<<endl;
        }
    }


return 0;
}
