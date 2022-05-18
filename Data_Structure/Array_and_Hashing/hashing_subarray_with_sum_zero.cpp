#include<iostream>
#include<unordered_set>

using namespace std;
bool subArrayExists(int arr[],int n){
    unordered_set<int> uset;
    int pre_sum =0;
    for(int i=0;i<n;i++){
        pre_sum +=arr[i];
        if(pre_sum == 0){
            return true;
            }
        if(uset.find(pre_sum)!=uset.end()){
            return true;
        }

        uset.insert(pre_sum);
    }
    return false;

}


int main(){
    int arr[]={5,-1,2,-1,3,2};
    int arr_size = sizeof(arr)/sizeof(int);

    if(subArrayExists(arr,arr_size)){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }

return 0;
}

//time complexity ==> O(n)
//space complexity ==> O(n)
