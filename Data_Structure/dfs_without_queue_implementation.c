#include<stdio.h>

int a[20][20],q[20],visited[20],n;

void dfs(int v){
    int i;
    for(i=0;i<n;i++){
        if(!visited[i] && a[v][i]==1){
            visited[i]=1;
            printf("%d ",i);
            dfs(i);
        }
    }
}

int main(){
    int v,i,j;
    printf("\n Enter the number of vertices :");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        visited[i]=0;
    }

    printf("Enter the adjacency matrix :\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter the starting vertex :");
    scanf("%d",&v);
    printf("\n DFS traversal is  :\n");
    visited[v]=1;
    printf("%d ",v);
    dfs(v);


    return 0;
}
