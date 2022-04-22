#include<iostream>
#include <vector>

using namespace std;

int isPrime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

void build(int ans[1121][15],vector<int> prime,int Pt) {
    ans[0][0] = 1;
    int i, j, k;
    for(i = 0; i < Pt; i++) {
        for(j = 1120; j >= prime[i]; j--) {
            for(k = 14; k >= 1; k--)
                ans[j][k] += ans[j-prime[i]][k-1];
        }
    }
}
int main(){
    int n, k;
    while(scanf("%d %d", &n, &k)) {
        int ans[1121][15] = {},Pt;
        vector< int > prime;
        if(n == 0 && k == 0)
            break;

        for(int i=2;i<=n;i++){
            if(isPrime(i)){
                prime.push_back(i);
            }
        }
        Pt=prime.size();

        build(ans,prime,Pt);
        printf("%d\n", ans[n][k]);
    }
    return 0;
}
