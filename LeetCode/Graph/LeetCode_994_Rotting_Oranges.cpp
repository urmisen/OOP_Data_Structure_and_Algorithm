class Solution {
public:

    bool isValid(int i, int j,int n,  int m,vector<vector<int>>& grid){
        if(i>=0 && i<n && j>=0 && j<m && grid[i][j]==1){
            return true;
        }
        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        int fresh=0,time=0;

        //if there are rotten oranges then push it's coordinates in the queue
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }

        //no fresh oranges there
        if(fresh==0) return 0;

        //Bfs traversal
        while(!q.empty()){
            int size_q=q.size();
            int temp=0;

            while(size_q!=0){

                pair<int,int>p = q.front();
                q.pop();
                int x1=p.first;
                int y1=p.second;

                int dx[]={1,-1,0,0};
                int dy[]={0,0,1,-1};

                for(int i=0;i<4;i++){
                    int x=dx[i]+x1;
                    int y=dy[i]+y1;

                    if(isValid(x,y,n,m,grid)){
                        temp++;
                        grid[x][y]=2;
                        q.push({x,y});
                    }
                }
                size_q--;
            }
            if(temp!=0) time++;
        }

        //check if  any fresh  oranges  are still there
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    time=0;
                    break;
                }
            }
        }
        return (time==0) ? -1 : time ;
    }
};
