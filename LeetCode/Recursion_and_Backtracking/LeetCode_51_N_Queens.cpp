class Solution {
public:

    bool isSafe(int row,int col, vector<string> &board, int n){
        //check upper diagonal
        int duprow=row;
        int dupcol=col;

        while(row>=0 && col>=0){
            if(board[row][co]=='Q') return false;
            row--;
            col--;
        }

        //check leftRow
        row = duprow;
        col=dupcol;
        while(col>=0){
            if(board[row][co]=='Q') return false;
            col--;
        }

        //check lower diagonal
        row = duprow;
        col=dupcol;

        while(row<n && col>=0){
            if(board[row][co]=='Q') return false;
            row++;
            col--;
        }

        return true;
    }

    void solve(int col, vector<string> &board, int n, vector<vector<string>> &ans){

        if(col>=n){
            ans.push_back(board);
            return;
        }

        for(int row=0;row<n;row++){
            if(isSafe(row, col, board, n)){
            board[row][col]='Q';
            solve(col+1,board,n,ans);
            board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }

        solve(0,board,n,ans);

        return ans;
    }
};

//time Complexity ==> actual+O(n)+O(n)+O(n)+O(n)

class Solution {
public:

    void solve(int col, vector<string> &board, int n, vector<vector<string>> &ans, vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal){

        if(col>=n){
            ans.push_back(board);
            return;
        }

        for(int row=0;row<n;row++){
            if(leftRow[row]==0 && upperDiagonal[row+col]==0 && lowerDiagonal[(n-1)+(col-row)]==0){
                board[row][col]='Q';
                leftRow[row] = 1;
                upperDiagonal[row+col] = 1;
                lowerDiagonal[(n-1)+(col-row)] = 1;

                solve(col+1,board,n,ans,leftRow,upperDiagonal,lowerDiagonal);

                board[row][col]='.';
                leftRow[row] = 0;
                upperDiagonal[row+col] = 0;
                lowerDiagonal[(n-1)+(col-row)] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        vector<int> leftRow(n,0), upperDiagonal(2*n - 1, 0), lowerDiagonal(2*n - 1, 0);

        solve(0,board,n,ans,leftRow,upperDiagonal,lowerDiagonal);

        return ans;
    }
};

//time Complexity ==> actual+O(n)+O(1)
