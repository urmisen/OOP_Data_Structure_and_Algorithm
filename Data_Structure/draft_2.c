#include <iostream>
#define N 1005

using namespace std;

main() {
//    freopen("990.inp", "r", stdin); freopen("990.out", "w", stdout);
    int i, j, End = 0;
    int n, t,w, wt[35], v[35], d[35], dp[35][N];
    while (cin >> t >> w) {
        cin >> n;
        for (i=1; i<=n; i++) {
            scanf("%d %d", &d[i], &v[i]);
            w[i] = 3*d[i]*w;
        }

        for (j=0; j<=t; j++)
            dp[0][j] = 0;
        for (i=1; i<=n; i++)
            for (j=0; j<=t; j++)
                if (wt[i]<=j)
                    dp[i][j] = max(dp[i-1][j], v[i]+dp[i-1][j-wt[i]]);
                else
                    dp[i][j] = dp[i-1][j];
        if (End) cout << endl; End=1;

        int ans[35], k=0, sum=0;
        while (n>0) {
            if (dp[n][t]!=dp[n-1][t]) {
                ans[k++] = n;
                t -= wt[n];
                sum += v[n];
            }
            n--;
        }
        printf("%d\n", sum);
        printf("%d\n", k);
        for (i=k-1; i>=0; i--)
            printf("%d %d\n", d[ans[i]], v[ans[i]]);
    }
}
