#include<stdio.h>

void BFS(int,int);
int graph[10][10],  visited[10],level[10], q,m,n,u,v,s;
int Queue[10],f=-1,r=-1;

int main(){
    int i,j,count=1;
    scanf("%d",&q);

     for(int k=0;k<q;k++){
        scanf("\n%d %d",&n,&m);
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                graph[i][j]=0;
            }
        }
        for(i=1;i<=n;i++){
            visited[i]=0;
        }
        for(i=1;i<=n;i++){
            level[i]=-1;
        }
        for(j=1;j<=m;j++){
            scanf("%d %d",&u,&v);
            graph[u][v]=1;
        }

        scanf("%d",&s);
        f=r=0;

        Queue[r]=s;
        visited[s]=1;
        BFS(s,count);


        for(i=1;i<=n;i++){
            if(i==s)
                continue;
            else
                printf("%d ",level[i]);
        }
        printf("\n");

        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                printf("%d ",graph[i][j]);
            }
            printf("\n");
        }
     }


    return 0;
}

void BFS(int s,int count){
    int j;
    for(j=1;j<=n;j++){

        if(!visited[j] && graph[s][j]==1){
            r=r+1;
            Queue[r]=j;
            visited[j]=1;
            graph[s][j]=count*6;
            level[j]=count*6;
        }
        if(graph[s][j]==1){

            graph[s][j]=count*6;
        }
    }
    f=f+1;
    count=count+1;

    if(f<=r){
        BFS(Queue[f],count);
    }

}

for(i=0;i<n;i++){
            ex[0]=s;
            if(i!=s){
                ex[i]=i+1;}
            if(i == s){
                ex[i]=i+1;
            }
        }
        for(i=0;i<n;i++){
            printf("%d ",ex[i]);
        }
