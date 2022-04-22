#include<iostream>
using namespace std;

#define INT_MAX 999999

int n=4;
int dist[10][10]={
    {0,20,42,25},
    {20,0,30,34},
    {42,30,0,10},
    {25,34,10,0}
};

int visited_all=(1<<n)-1;
int dp[16][4];

int tsp(int mask,int pos){
    int ans=INT_MAX;
    if(mask == visited_all){
        return dist[pos][0];
    }

    if(dp[mask][pos]!= -1){
        return dp[mask][pos];
    }

    for(int city=0;city<n;city++){
        if((mask & (1<<city)) == 0){
            int newans = dist[pos][city] + tsp(mask|(1<<city),city);
            ans = min(ans,newans);
            }
        }

    return dp[mask][pos]=ans;
}


int main(){
    int i,j;
    for(i=0;i<(1<<n);i++){
        for(j=0;j<n;j++){
            dp[i][j]=-1;
        }
    }

    cout<<tsp(1,0)<<endl;
    return 0;

}
