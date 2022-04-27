#include<iostream>
#include<unordered_map>

using namespace std;
int main(){
    int arr[]={5,-1,2,-1,3,2};
    int arr_size = sizeof(arr)/sizeof(int);
    unordered_map<int , int> umap;
    for(int i=0;i<arr_size;i++){
        int key =arr[i];
        umap[key]++;
    }

    //traverse and checking

    for(int i=0;i<arr_size;i++){
        int key = arr[i];
        auto temp =  umap.find(key);
        if(temp->second == 1){
            cout<< key;
            break;
        }
        else{ cout<<0;}

    }


return 0;
}

//time complexity ==> O(n)
//space complexity ==> O(n)
