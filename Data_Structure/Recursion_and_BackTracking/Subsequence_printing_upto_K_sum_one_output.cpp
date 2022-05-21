#include<iostream>
#include<vector>
using namespace std;


bool fn(int arr[], vector<int>&lst, int i, int n, int K,int sum){

    if(i>=n){
        if(sum==K){
            for(auto i:lst){
                cout<<i<<" ";
            }
            cout<<endl;
            return true;
        }
        else return false;
    }
    //take
    lst.push_back(arr[i]);
    sum+=arr[i];
    if(fn(arr,lst,i+1,n,K,sum) == true){
        return true;
    }

    //Not-take
    lst.pop_back();
    sum-=arr[i];
    if(fn(arr,lst,i+1,n,K,sum)== true){
        return true;
    }
    return false;
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



