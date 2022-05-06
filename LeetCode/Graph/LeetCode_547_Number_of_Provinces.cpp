class Solution {
public:

    void dfs_Rec(vector<int> adj[], int src, vector<bool> &visited){

        visited[src]=true;
        for(auto x:adj[src]){
            if(!visited[x]){
                dfs_Rec(adj,x,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<bool>visited(v,false);

        //creating adjacency list for each node
        vector<int>adj[v];
        for(int i=0;i<v;i++){               //for node 1
            for(int j=0;j<v;j++){           //given data 1 1 0
                if(isConnected[i][j]==1){   //if connected add it to the adjacency list
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int count =0;
        for(int i=0;i<v;i++){
            if(!visited[i]){
                dfs_Rec(adj,i,visited);
                count++;
            }
        }
        return count;
    }
};
