#include<iostream>
using namespace std;


int N,visited_all;
int dist[13][13];
int xpos[13],ypos[13];
int dp[1<<12][13];
const int Inf = 1e9;

int GetBestCost(int mask,int pos){

    if(mask == visited_all){
        return dist[pos][0];
    }

    if(dp[mask][pos] != -1){
        return dp[mask][pos];
    }
    int ans = Inf;
    for(int beeper=0;beeper<N;beeper++){
        if((mask & (1<<beeper))== 0){
            int newans= dist[pos][beeper] + GetBestCost(mask|(1<<beeper),beeper);
            ans = min(ans,newans);
        }
    }

    return  dp[mask][pos]=ans;

}


int main(){
    int T;
    cin>>T;

    while(T--){
        int R,C;
        cin>>R>>C;

        cin>>xpos[0]>>ypos[0];
        cin>>N;

        for(int i=1;i<=N;i++){
            cin>>xpos[i]>>ypos[i];
            for(int j=0;j<i;j++){
                dist[i][j]= dist[j][i] = abs(xpos[i] - xpos[j]) + abs(ypos[i] - ypos[j]);
            }
        }
        visited_all=(1<<N)-1;

        for(int i=0;i<visited_all;i++){
            for(int j=0;j<N;j++){
                dp[i][j]=-1;
            }
        }

        cout<< "The shortest path has length "<<GetBestCost(0,0)<<"\n";
    }

return 0;
}
