#include<iostream>
#include <cstring>
using namespace std;

int main(){

    int T,N,P[1005],W[1005],G;
    cin>>T;
    while(T--){
        cin>>N;
        for(int i=0;i<N;i++){
            cin>>P[i]>>W[i];
        }

        int dp[35];
        memset(dp,0,sizeof(dp));

        for(int i=0;i<N;i++){
            for(int j=30;j>=0;j--){
                if(W[i]<=j && dp[j]<P[i] + dp[j-W[i]])
                    dp[j]=P[i] + dp[j-W[i]];
            }
        }
        cin>>G;
        int maxPrice=0;
        while(G--){
            int volumn;
            cin>>volumn;
            maxPrice+= dp[volumn];
        }
        cout<<maxPrice<<endl;
    }

return 0;

}
