#include <iostream>
#include <string.h>
#include<cstdio>
#include<stdio.h>

using namespace std;

int n,a[210][210];
int rs;

void Enter() {
    getchar();
    int i,j; char s[210];
    for (i=1;i<=n;i++) {
        cin>>s;
        for (j=1;j<=n;j++)
            if (s[j-1]=='w') a[i][j] = 1;       //White=1   Black=0
            else a[i][j] = 0;
    }
    rs = 0;
}

void DFS(int u, int v) {
    if (!rs && u>=1 && u<=n && v>=1 && v<=n && a[u][v]==1) {
        if (v==n) {
            rs=1; return;
        }
        a[u][v]=-1;
        DFS(u-1,v-1); DFS(u-1,v);
        DFS(u,v-1); DFS(u,v+1);
        DFS(u+1,v); DFS(u+1,v+1);
    }
}

int main() {
    int i, index=0;
    while (cin >> n) {
        if (n==0) break;
        Enter();
        for (i=1;i<=n && !rs;i++)
            if (a[i][1]==1) DFS(i,1);
        cout << ++index << " ";
        if (rs) cout << 'W';
        else cout << 'B';
        cout << endl;
    }
}
