#include<iostream>
#include<unordered_map>

using namespace std;
int main(){
    int arr[]={1,5,3,4,3,5,6};
    int arr_size = sizeof(arr)/sizeof(int);
    unordered_map<int,int> umap;

    //map creation
    for(int i=0;i<arr_size;i++){
        int key = arr[i];
        umap[key]++;
    }

    //travering and  checking
    for(int i=0;i<arr_size;i++){
        int key = arr[i];
        auto temp = umap.find(key);
        if(temp->second >1){
            cout<<i+1;
            break;
        }
    }


return 0;
}

//time complexity ==> O(n)
//space complexity ==> O(n)
