#include<iostream>
#include<unordered_map>

using namespace std;
int main(){
    int arr[]={1,5,3,4,3,5,6};
    int X=11;
    int arr_size = sizeof(arr)/sizeof(int);
    unordered_map<int,int> umap;

    //map creation
    for(int i=0;i<arr_size;i++){
        int key = arr[i];
        umap[key]++;
    }

    //travering and  checking
    for(auto itr = umap.begin();itr!=umap.end();itr++){
        int key = itr->first;
        int val = itr->second;

        int pair = X-key;
        if(pair==key){
            if(val>1){
                cout<<"true"<<endl;
            }
            break;
        }
        else if(umap.find(pair)!=umap.end()){
               cout<<"true"<<endl;
               break;
               }
        else{cout<<"false"<<endl;}

    }





return 0;
}

//time complexity ==> O(n)
//space complexity ==> O(n)

