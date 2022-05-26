//with extra space
class Solution {
public:

    void RecurPermute(vector<int>& nums, int freq[], vector<int> &ds, vector<vector<int>> &ans){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(!freq[i]){
                ds.push_back(nums[i]);
                freq[i]=1;
                RecurPermute(nums,freq, ds,ans);
                freq[i]=0;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int freq[nums.size()];
        for(int i=0;i<nums.size();i++){
            freq[i]=0;
        }
        RecurPermute(nums,freq, ds,ans);
        return ans;
    }
};

//Time Complexity ==> O(n!*n)
//space complexity ==> O(n)+O(n) + O(n!)+O(n)


//without extra space
class Solution {
private:

    void RecurPermute(int ind, vector<int>& nums, vector<vector<int>> &ans){
        if(ind>=nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i=ind;i<nums.size();i++){
            swap(nums[ind],nums[i]);
            RecurPermute(ind+1,nums,ans);
            swap(nums[ind],nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;

        RecurPermute(0,nums,ans);
        return ans;
    }
};

//Time Complexity ==> O(n!*n)
//space complexity ==> O(n!)+O(n)

