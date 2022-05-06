class Solution {
public:

    bool Cycle(int src, vector<bool> &visited, vector<bool> &curr_visited, vector<int>adj_list[] ){

        visited[src]=true;
        curr_visited[src]=true;

        for(auto x: adj_list[src]){
            if(!visited[x]){
                if(Cycle(x,visited,curr_visited,adj_list)){
                    return true;
                }
            }
            else if(visited[x]==true && curr_visited[x]==true){
                return true;
            }
        }

        curr_visited[src]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        int n=numCourses;
        vector<int>adj_list[n];

        vector<bool>visited(n,false),curr_visited(n,false);

        for(auto x:prerequisites){
            vector<int>data=x;
            int a = data[0];
            int b = data[1];
            adj_list[a].push_back(b);
        }

        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(Cycle(i,visited,curr_visited,adj_list)){
                    return false;
                }
            }

        }
        return  true;
    }
};
