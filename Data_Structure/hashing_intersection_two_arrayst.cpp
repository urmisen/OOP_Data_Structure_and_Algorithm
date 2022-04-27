#include<iostream>
#include<unordered_set>

using namespace std;
int main(){
    int arr1[]={5,-1,2,-1,3,2};
    int arr2[]={5,9,2,6};
    int arr_size1 = sizeof(arr1)/sizeof(int);
    int arr_size2 = sizeof(arr2)/sizeof(int);

    unordered_set<int> uset;
    for(int i=0;i<arr_size1;i++){
        int key = arr1[i];
        uset.insert(key);
    }
    int cnt=0;
    for(int i=0;i<arr_size2;i++){
        int key=arr2[i];
        if(uset.find(key)!=uset.end()){
            cnt++;
            uset.erase(key);
        }
    }
    cout<<cnt<<endl;

return 0;
}

//time complexity ==> O(n)
//space complexity ==> O(n)
