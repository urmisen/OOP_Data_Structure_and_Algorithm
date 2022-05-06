
#include<iostream>
#include<vector>
using namespace std;

void addEdge(vector<int>adj_list[],int u,int v){
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
}

void  printGraph(vector<int>adj_list[],int v){
    for(int i=0;i<v;i++){
        for(auto  x: adj_list[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }

}
bool dfs_rec(vector<int>adj_list[],int src, vector<bool> &visited,int parent){

    visited[src]=true;

    for(auto x:adj_list[src]){
        if(!visited[x]){
            if(dfs_rec(adj_list,x,visited,src)){
                return true;
            }
            if(x!=parent){
                return true;
            }
        }
    }
    return false;


}

bool dfs(vector<int>adj_list[],int v,int src){
    vector<bool>visited(v+1,false);
    for(int i=0;i<v;i++){
        if(!visited[i]){
            if(dfs_rec(adj_list,i,visited,-1)){
               return true;
            }
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

    int ans=dfs(adj_list,ver,src);

    cout<<ans<<endl;

return 0;
}
