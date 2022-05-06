class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        int k =0;

        while(low<=high){
            int mid = (low+high)/2;
            int hours = 0;
            for(auto p : piles){
                hours += ((p-1)/mid) + 1;
            }

            if(hours<=h){
                k = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return k;
    }
};
