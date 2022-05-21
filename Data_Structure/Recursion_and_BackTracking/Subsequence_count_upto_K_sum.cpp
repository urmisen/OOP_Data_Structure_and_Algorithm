#include<iostream>
#include<vector>
using namespace std;


int fn(int arr[], int i, int n, int K,int sum){

    if(i>=n){
        if(sum==K){
            return 1;
        }
        else return 0;
    }

    //take
    sum+=arr[i];
    int l= fn(arr,i+1,n,K,sum);

    //Not-take
    sum-=arr[i];
    int r = fn(arr,i+1,n,K,sum);
    return (l+r);
}
int main(){
    int n,K;
    cin>>n>>K;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Sub-sequences upto K sum :"<<endl;

    int sum=0;
    cout<<fn(arr,0,n,K,sum);

    return 0;
}



