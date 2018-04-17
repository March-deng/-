/*
百练POJ1390，用动态规划Dp解决*/
#include<cstdio>  
#include<cstring>  
#include<algorithm>  
#include<iostream>  
using namespace std;  
const int maxn=200+50;  
  
int t,col[maxn],len[maxn],d[maxn][maxn][maxn],n,cnt;  
  
int dp(int L,int R,int k)  
{  
        if(d[L][R][k]) return d[L][R][k];  
        if (L == R)        return (len[L]+k)*(len[L]+k);  
        d[L][R][k]= dp(L,R-1,0)+(len[R]+k)*(len[R]+k);  
        for(int i=L;i<R;i++)  
        {  
        if(col[i]==col[R])  
        d[L][R][k]=max(d[L][R][k],dp(L,i,len[R]+k)+dp(i+1,R-1,0));  
        }  
        return  d[L][R][k];  
}  
  
int main()  
{  
        int casen=0;  
        scanf("%d",&t);  
        while(t--)  
        {  
                memset(d,0,sizeof(d));  
                memset(len,0,sizeof(len));  
                scanf("%d",&n);  
                int tmp;  
                scanf("%d",&col[1]);  
                len[1]++;  
                cnt=1;  
                for(int i=1,j=1;i<n;i++)  
                {  
                scanf("%d",&tmp);  
                if(col[j]==tmp) len[j]++;  
                else {j++;cnt=j;col[j]=tmp;len[j]++;}  
                }  
                printf("Case %d: %d\n",++casen,dp(1,cnt,0));  
        }  
        return 0;  
}  