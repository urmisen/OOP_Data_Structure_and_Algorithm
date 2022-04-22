#include <cstdio>
#include <cstring>
const int MAX = 2000 + 5;

int dp[MAX][MAX];
int n, w;
int c[MAX], ans[MAX];

int maxValue(int a, int b)
{
	return a>b?a:b;
}


int main()
{
//	freopen("in.txt","r",stdin);
	while(scanf("%d %d", &w, &n)!=EOF)
	{

		for(int i=1; i <= n; i++)
			scanf("%d", &c[i]);

		for(int i=0; i <= n; i++)
		{
			for(int j=0; j <= w; j++)
                if(i==0 || j==0){
                    dp[i][j] =0;
                }
				else if(c[i] <= j)
					dp[i][j] = maxValue(dp[i-1][j], dp[i-1][j-c[i]]+c[i]);
				else
					dp[i][j] = dp[i-1][j];
		}
		int length=0;
		for(int i=n, j=w; i > 0; i--)
		{
			if(c[i]<=j &&
				dp[i][j]==dp[i-1][j-c[i]]+c[i])
				{
					ans[length++] = c[i];
					j -= c[i];
				}
		}
		for(int i=length-1; i>=0; i--)
			printf("%d ", ans[i]);
		printf("sum:%d\n",dp[n][w]);

	}
	return 0;
}
