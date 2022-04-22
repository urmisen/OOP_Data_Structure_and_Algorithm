#include<iostream>
using namespace std;
#define maxN 105

const int dx[] = {1, 1, 1, -1, -1, -1, 0, 0};
const int dy[] = {0, -1, 1, 0, -1, 1, -1, 1};
int n, m;
char s[maxN][maxN];

int Visit(int x, int y) {
    if (x<0 || x>=n || y<0 || y>=m || s[x][y]!='*') return 0;
    s[x][y] = '.';
    int Count = 1;
    for(int i=0;i<8;i++){
        Count += Visit(x + dx[i], y + dy[i]);
    }
    return Count;
}

main() {
//    FileIn("test"); FileOut("test");
    while (scanf("%d %d", &n, &m) && (n || m)) {
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>s[i][j];
            }
        }
        int res = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if (s[i][j]=='*') {
                    int Count = Visit(i, j);
                    if (Count==1) res++;
                }
            }
            }
        printf("%d\n", res);
    }
}
