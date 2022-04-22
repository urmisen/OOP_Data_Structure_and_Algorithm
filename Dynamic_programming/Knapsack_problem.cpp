#include<iostream>
#include<stdio.h>

using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int KnapSack(int W,  int wt[], int p[], int n){
    int i,w;
    int k[n+1][W+1];

    for(i=0;i<=n;i++){
        for(w=0;w<=W;w++){
            if(i==0 || w==0){
                k[i][w]=0;
            }
            else if(wt[i-1]<=w){
                k[i][w]=max(p[i-1]+k[i-1][w-wt[i-1]], k[i-1][w]);

            }
            else
                k[i][w] = k[i-1][w];
        }
    }
    //minimum number of object
    for(i=n;i>=0;i--){
        for(w=W;w>=0;w--){
            if(k[i][w]==k[i-1][w]){
                cout<<i<<"=0"<<endl;
            }
            else{
                cout<<i<<"=1"<<endl;
                w=w-wt[i];
            }
        }
    }
    return k[n][W];
}

int main(){
    int wt[]={2,3,4,5};
    int p[]={1,2,5,6};
    int W = 8;

    int n = sizeof(wt)/sizeof(wt[0]);
    cout<<KnapSack(W,wt,p,n);

return 0;
}
