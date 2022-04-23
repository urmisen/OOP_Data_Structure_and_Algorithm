#include<bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
        map<int, int> count;
        for(int i=0;i<nums.size();i++){
            if(count[nums[i]]){
                return true;
            }
            count[nums[i]]++;
        }
        return false;
    }

int main ()
{
	vector <int> arr;
	int value=0,n;
	cin>>n;
	for(int i=0;i<n;i++){
        cin>>value;
        arr.push_back(value);
	}
	if (containsDuplicate(arr))
        cout << "True";
    else
        cout << "False";

	return 0;
}

//time complexity ==> O(n)
//space complexity ==> O(n)

