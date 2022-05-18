#include<iostream>

using namespace std;

// Number of vertices in the graph
const int V=6;

void print_MST(int parent[],int cost[V][V]){
    int minCost = 0;
    cout<<"Edge \t Weight \n";
    for(int i=1;i<V;i++){
        cout<<parent[i]<<"  -  "<<i<<"\t"<<cost[i][parent[i]]<<"\n";
        minCost+=cost[i][parent[i]];
    }
    cout<<"Total cost is : "<<minCost;
}

int min_key(int key[],bool  visited[]){
    int min= INT_MAX,min_index;
    for(int i=0;i<V;i++){
        if(key[i]<min &&  visited[i]==false){
            min=key[i];
            min_index = i;
        }
    }
    return min_index;
}
void find_MST(int cost[V][V]){
    int parent[V],key[V];
    bool visited[V];

    for(int i=0;i<V;i++){
        key[i] = INT_MAX;
        visited[i] =  false;
        parent[i] = -1;
    }

    key[0]=0;

    for(int x =0;x<V-1;x++){
        int u = min_key(key,visited);
        visited[u] =true;

        for(int v=0;v<V;v++){
            if(cost[u][v]!=0 && visited[v]==false && cost[u][v] < key[v]){
                parent[v]=u;
                key[v]=cost[u][v];
            }
        }
    }
    print_MST(parent,cost);
}
int main(){
    cout<<"Enter the vertices for a graph with 6 vetices : \n";

    int cost[V][V];

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cin>>cost[i][j];
        }
    }

    find_MST(cost);

return 0;
}
