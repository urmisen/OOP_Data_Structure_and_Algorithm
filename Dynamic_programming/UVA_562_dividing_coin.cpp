#include<iostream>
using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}


int main(){
    int n ,m, i, j,sum,W;
    int wt[100+5];
    scanf("%d",&n);
    while(n--){
        scanf("%d",&m);
        sum=0;
        for(i=1;i<=m;i++){
            scanf("%d",&wt[i]);
            sum+=wt[i];
        }
    W = sum/2;

    int k[m+1][W+1],i,w;
    for(i=0;i<=m;i++){
        for(w=0;w<=W;w++){
            if(i==0 || w==0){
                k[i][w]=0;
            }
            else if(wt[i]<=w){
                k[i][w]=max(k[i-1][w],wt[i]+k[i-1][w-wt[i]]);
            }
            else{
                k[i][w]=k[i-1][w];
            }
        }
    }

    printf("%d\n",sum - 2*k[m][W]);
    }


return 0;
}
