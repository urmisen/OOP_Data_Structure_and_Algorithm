#include<bits/stdc++.h>
#include <iostream>
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,count=0,ans;
        vector<int>round_nums;
        cin>>n;
        if(n%10!=0){
            ans=n%10;
            n-=ans;
            round_nums.push_back(ans);
            count++;
        }
        if(n%100!=0){
            ans=n%100;
            n-=ans;
            round_nums.push_back(ans);
            count++;
        }
        if(n%1000!=0){
            ans=n%1000;
            n-=ans;
            round_nums.push_back(ans);
            count++;
        }
        if(n%10000!=0){
            ans=n%10000;
            n-=ans;
            round_nums.push_back(ans);
            count++;
        }
        if(n>=10000 && n%10000==0){
            round_nums.push_back(n);
            count++;
        }
        cout<<count<<endl;
        for(int i=0;i<round_nums.size();i++){
            cout<<round_nums[i]<<" ";
        }
        cout<<endl;
    }


return 0;

}

