#include<iostream>
#include<unordered_map>
#include<map>
#include<list>
#include<queue>
using namespace std;
map<int,list<int>> l;

bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        unordered_map<int,vector<int>>umap;
        for(auto x:edges){
            vector<int>temp = x;

            int u = temp[0];
            int v = temp[1];

            umap[u].push_back(v);
            umap[v].push_back(u);
        }

        vector<bool>visited(n+1,false);

        queue<int>q;
        q.push(source);
        visited[source]=true;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto nbr:umap[node]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr]=true;
                }
            }
        }
        cout<< visited[destination];
    }



void printGraph(int v){
    for(int i=0;i<v;i++){
        for(auto x:l[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}


int main(){
    int n,src,des;
    vector<vector<int>> edges;
    edges = {{0,1},
            {0,2},
            {3,5},
            {5,4},
            {4,3}};
    cout<<"Enter the number of Edgers : ";
    cin>>n;

    cout<<"Enter the source and destination : ";
    cin>>src>>des;

    validPath(n,edges,src,des);





return 0;
}
