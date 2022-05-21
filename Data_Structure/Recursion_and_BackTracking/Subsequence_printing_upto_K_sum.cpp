#include<iostream>
#include<vector>
using namespace std;


void fn(int arr[], vector<int>&lst, int i, int n, int K,int sum){

    if(i>=n){
        if(sum==K){
            for(auto i:lst){
                cout<<i<<" ";
            }
            cout<<endl;
        }
        return;
    }
    //take
    lst.push_back(arr[i]);
    sum+=arr[i];
    fn(arr,lst,i+1,n,K,sum);

    //Not-take
    lst.pop_back();
    sum-=arr[i];
    fn(arr,lst,i+1,n,K,sum);
}
int main(){
    int n,K;
    cin>>n>>K;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Sub-sequences upto K sum :"<<endl;
    vector<int>lst;
    int sum=0;
    fn(arr,lst,0,n,K,sum);

    return 0;
}



