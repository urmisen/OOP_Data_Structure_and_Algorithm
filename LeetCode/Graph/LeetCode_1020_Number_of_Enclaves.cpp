class Solution {
public:
    int count(vector<vector<int>>& grid,int n, int m){
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    ans++;
                }
            }
        }
        return ans;
    }
    bool isValid(int i,int j, int n, int m,vector<vector<int>>& grid){

        if(i>=0 && i<n && j>=0 && j<m && grid[i][j]==1){
            return true;
        }
        return false;
    }
    void dfs_Rec(int i,int j, int n, int m,vector<vector<int>>& grid){
        grid[i][j]=0;

        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};

        for(int k=0;k<4;k++){
            int nx = i + dx[k];
            int ny = j + dy[k];
            if(isValid(nx,ny,n,m,grid)){
                dfs_Rec(nx,ny,n,m,grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n= grid.size();
        int m = grid[0].size();

        //boundary search
        for(int i=0;i<n;i++){
            int j=0;
            if(grid[i][j]==1){
                dfs_Rec(i,j,n,m,grid);
            }
            j=m-1;
            if(grid[i][j]==1){
                dfs_Rec(i,j,n,m,grid);
            }
        }

        for(int j=0;j<m;j++){
            int i=0;
            if(grid[i][j]==1){
                dfs_Rec(i,j,n,m,grid);
            }
            i=n-1;
            if(grid[i][j]==1){
                dfs_Rec(i,j,n,m,grid);
            }
        }

        return count(grid,n,m);
    }
};
