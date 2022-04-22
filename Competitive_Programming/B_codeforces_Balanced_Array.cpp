#include<bits/stdc++.h>
#include <iostream>
using namespace std;


int main(){
    int t;
    cin>>t;

    while(t--){
        int n;cin>>n;
        vector<int>num1;
        vector<int>num2;
        int sum1=0,sum2=0;
        if(n%2==0 && n!=2){

            for(int i=1;i<=(n-2);i++){
                if(i%2==0){
                    num1.push_back(i);
                    sum1+=i;
                    num2.push_back(i-1);
                    sum2+=i-1;
                }
            }
            num1.push_back(n);
            sum1+=n;
            num2.push_back(n+((n/2)-1));
            sum2+=n+((n/2)-1);

            int flag=1;
            for(int i=0;i<n/2;i++){
                    if(num1[i]%2==0 && num2[i]%2!=0){
                        flag=1;
                        }
                    else{
                        flag=0;
                        break;
                    }
                    }

            if(sum1==sum2 && flag==1){

                cout<<"YES"<<endl;
                for(int j=0;j<n/2;j++){
                    cout<<num1[j]<<" ";
                }
                for(int j=0;j<n/2;j++){
                    cout<<num2[j]<<" ";
                }
                cout<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }


        }
        else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}



