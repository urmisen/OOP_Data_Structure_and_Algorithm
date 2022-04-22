#include<iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
#define MAXNODE 210

typedef queue <int> qi;
vector< int > g[MAXNODE];
int d[MAXNODE];

int bfs(int n, int src){
    bool color[210];
    bool taken[210];
    for(int i=0;i<n;i++)
        color[i] = false,taken[i]=false;
    int i,u,v;
    qi q;
    q.push(src);

    while(!q.empty()){
        u = q.front();q.pop();
        for(i=0;i<g[u].size();i++)
            {
                v = g[u][i];

                if(taken[v]==false) {
                    color[v] = !color[u];
                    taken[v] = true;
                    q.push(v);
                }
                else if(color[u]==color[v]){printf("NOT ");return 0;}
            }
    }
return 0;
}

int main () {
	int n, e, i, u, v;
        while(scanf("%d",&n) && n!=0){
            scanf("%d",&e);
            for(i = 0; i < n; i++) g[i].clear(); // forget previous info
            for(i = 0; i < e; i++) {
                scanf("%d %d",&u,&v);
                g[u].push_back(v);
                g[v].push_back(u);//if graph is undirected
            }
            bfs(n,0);
            printf("BICOLORABLE.\n");

        }
	return 0;
}
