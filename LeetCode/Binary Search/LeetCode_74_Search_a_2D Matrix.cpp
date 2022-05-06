class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols  = matrix[0].size();

        //binary search across the rows
        int top = 0;
        int bot = rows - 1;

        if(target < matrix[0][0] || target > matrix[rows-1][cols-1]) return false;
        while(top<=bot){
            int mid_row = (top + bot)/2;

            if(target == matrix[mid_row][cols-1]){
                return true;
            }

            else if(target < matrix[mid_row][cols-1]){
                bot = mid_row - 1;
            }
            else{
                top = mid_row + 1;
            }
        }



        int row = top;
        int low=0;
        int high = cols - 1;


        while(low<=high){
            int mid = (low+high)/2;
            if(target == matrix[row][mid]){
                return true;
            }
            else if(target < matrix[row][mid]){
                high = mid-1;
            }
            else{
                low = mid + 1;
            }
        }
        return false;

    }
};
