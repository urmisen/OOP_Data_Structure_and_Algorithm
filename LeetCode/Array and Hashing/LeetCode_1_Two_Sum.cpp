#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> Bruteforse(vector<int>& nums, int target) {
        const int size = nums.size();
        vector<int> twoSums;
        for (int i = 0 ; i < size - 1; i++ )
            for (int j = i+1; j < size; j++)
                if(nums[i] + nums[j] == target)
                {
                    twoSums.push_back(i);
                    twoSums.push_back(j);
                    return twoSums;
                }
        return twoSums;
    }

//time complexity ==> O(n2)
//space complexity ==> O(1)

vector<int> Hashmap(vector<int>& nums, int target) {
        vector<int>twoSum;
        unordered_map<int,int> map;
        const int size = nums.size();

        for(int i=0;i<size;i++){
            if(map.count(target-nums[i])){
                twoSum.push_back(map[target-nums[i]]);
                twoSum.push_back(i);
                break;
            }
            else{
                map[nums[i]]=i;
            }
        }
        return twoSum;
    }

//time complexity ==> O(n)
//space complexity ==> O(n)

int main ()
{
	vector<int> v;
     v={1,6,3,2,5};
     vector<int> result= Hashmap (v, 11);
     for(int i: result)
     {
          cout<<i<<" ";
     }

	return 0;
}


