class Solution {
public:

    bool Cycle(int s, vector<bool>&visited, vector<bool>&curr_visited, vector<vector<int>>& graph, vector<bool> &present_cycle){
        visited[s]=true;
        curr_visited[s]=true;

        for(auto  x: graph[s]){
            if(!visited[x]){
                if(Cycle(x, visited, curr_visited, graph, present_cycle)){
                    return present_cycle[s]=true;
                }
            }
            else if(visited[x]==true && curr_visited[x]==true){
                return present_cycle[s]=true;
            }
        }
        curr_visited[s] = false;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        vector<int> ans;

        int n = graph.size();

        vector<bool>visited(n, false), curr_visited(n, false);
        vector<bool>present_cycle(n,false);

        for(int i=0;i<n;i++){
            if(!visited[i]){
                Cycle(i,visited, curr_visited, graph, present_cycle);
            }
        }

        for(int i=0;i<n;i++){
            if(!present_cycle[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
