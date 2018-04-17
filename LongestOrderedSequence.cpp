#include<iostream>  
#include<cstring>  
#include<cstdio>  
using namespace std;  
const int maxn = 1001;  
int a[maxn],m;  
int dp[maxn];  
int LIS()  
{  
    int i,j,temp;  
    temp = 1;  
    for(i=1;i<=m;i++)  
    {  
        dp[i] = 1;  
        for(j=1;j<i;j++)  
        {  
            if(a[j]<a[i] && dp[j] + 1 > dp[i])
            {  
                dp[i] = dp[j] + 1;  
                //cout<<dp[i]<<endl;  
            }  
        }  
        if(dp[i] > temp)  
        {  
            temp = dp[i];  
            //cout<<temp<<endl;  
        }  
    }  
    return temp;  
}  
int main()  
{  
    int i,cnt;  
    //freopen("1.in","r",stdin);  
    while(cin>>m)  
    {  
        for(i=1;i<=m;i++)  
        {  
            cin>>a[i];  
        }  
        cnt = LIS();  
        cout<<cnt<<endl;  
    }  
}  