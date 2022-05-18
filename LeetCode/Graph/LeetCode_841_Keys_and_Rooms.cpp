class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        queue<int>q;
        vector<bool>visited(n,false);

        q.push(0);
        visited[0]=true;
        while(!q.empty()){
            int room= q.front();
            q.pop();
            for(auto x:rooms[room]){
                if(!visited[x]){
                    q.push(x);
                    visited[x]=true;
                }
            }
        }

        for(auto x:visited){
            if(!x) return false;
        }
        return true;
    }
};
