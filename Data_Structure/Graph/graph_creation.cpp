#include<iostream>
#include<vector>
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

    printGraph(adj_list,ver);

return 0;
}
