class Solution {
public:
    void func(int ind, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans) {
        ans.push_back(ds);

        for(int i=ind;i<arr.size();i++){
            if(i!=ind && arr[i]==arr[i-1]) continue;
            ds.push_back(arr[i]);
            func(i+1,arr,ds,ans);
            ds.pop_back();

        }
    }
    vector<vector<int>> subsetSumsWithDup(vector<int> arr)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(arr.begin(), arr.end());
        func(0, arr, ds, ans);
        return ans;
    }
};
