#include<stdio.h>

void BFS(int,int);
int graph[1000][1000],  visited[1000],level[1000], q,m,n,u,v,s;
int Queue[1000],f=-1,r=-1,ex[10];

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

        for(i=1;i<n;i++){
            ex[0]=s;

            if(i<s){
                ex[i]=i;
                }
            if(i >= s){
                ex[i]=i+1;
            }
        }

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
     }



    return 0;
}

void BFS(int sou,int count){
    int j;
    for(j=1;j<=n;j++){

        if(!visited[j] && (graph[sou][j]==1 || graph[j][sou]==1)){

            r=r+1;
            Queue[r]=j;
            visited[j]=1;
            level[j]=count*6;
        }
    }
    f=f+1;
    count=count+1;

    if(f<=r){
        BFS(ex[f],count);

    }


}

