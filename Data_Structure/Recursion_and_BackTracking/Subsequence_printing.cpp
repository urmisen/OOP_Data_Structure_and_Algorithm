#include<iostream>
#include<vector>
using namespace std;


void fn(int arr[], vector<int>&lst, int i, int n){

    if(i>=n){
        for(auto i:lst){
            cout<<i<<" ";
        }
        if(lst.size() == 0){
            cout<<"{}";
        }
        cout<<endl;
        return;
    }

    lst.push_back(arr[i]);
    fn(arr,lst,i+1,n);
    lst.pop_back();
    fn(arr,lst,i+1,n);
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Sub-sequences :"<<endl;
    vector<int>lst;
    fn(arr,lst,0,n);

    return 0;
}


