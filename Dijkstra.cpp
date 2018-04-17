/*
简单的Dijkstra单源最短路径问题。
*/
#include <iostream>
using namespace std;

int main()
{
    int e[10][10],dis[10],book[10];
    int maxNum=99999999;
    int n,m,t1,t2,distance;
    int min,u,v;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)
                e[i][j]=0;
            else
                e[i][j]=maxNum;
        }
    }
    for(int i=1;i<=m;i++){
        cin>>t1>>t2>>distance;
        e[t1][t2]=distance;
    }
    for(int i=1;i<=n;i++)
        dis[i]=e[1][i];
    for(int i=1;i<=n;i++)
        book[i]=0;
    book[1]=1;
    //核心算法模块
    for(int i=1;i<=n-1;i++){
        min=maxNum;
        for(int j=1;j<=n;j++){
            if(book[j]==0&&dis[j]<min){
                min=dis[j];
                u=j;
            }
        }
        book[u]=1;
        for(v=1;v<=n;v++){
            if(e[u][v]<maxNum){
                if(dis[v]>dis[u]+e[u][v])
                    dis[v]=dis[u]+e[u][v];
            }
        }
    }
    for(int i=1;i<=n;i++)
        cout<<dis[i]<<" ";
    cout<<endl;
    return 0;
}
