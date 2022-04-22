#include <iostream>
#define N 1005

using namespace std;

int main() {

    int i, j, End = 0;
    int n, t,w, wt[35], v[35], d[35];
    while (cin >> t >> w) {
        cin >> n;
        for (i=1; i<=n; i++) {
            cin>>d[i]>>v[i];
            wt[i] = 3*d[i]*w;
        }
        int K[n+1][t+1],i,w;

        for(i=0;i<=n;i++){
            for(w=0;w<=t;w++){
                if(i==0 || w==0){
                    K[i][w]=0;
                }
                if(wt[i]<=w){
                    K[i][w] = max(K[i-1][w], v[i] + K[i-1][w-wt[i]]);
                }
                else{
                    K[i][w]=K[i-1][w];
                }
            }
        }
        if (End) cout << endl; End=1;
        int ans[35], k=0, sum=0;
        while (n>0) {
            if (K[n][t]!=K[n-1][t]) {
                ans[k++] = n;
                t -= wt[n];
                sum += v[n];
            }
            n--;
        }
        cout<<sum<<"\n";
        cout<<k<<"\n";
        for (i=k-1; i>=0; i--)
            cout<<d[ans[i]]<<" "<<v[ans[i]]<<"\n";
    }
}
