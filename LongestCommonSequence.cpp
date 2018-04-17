/*
描述
A subsequence of a given sequence is the given sequence with some elements (possible none) left out. Given a sequence X = < x1, x2, ..., xm > another sequence Z = < z1, z2, ..., zk > is a subsequence of X if there exists a strictly increasing sequence < i1, i2, ..., ik > of indices of X such that for all j = 1,2,...,k, xij = zj. For example, Z = < a, b, f, c > is a subsequence of X = < a, b, c, f, b, c > with index sequence < 1, 2, 4, 6 >. Given two sequences X and Y the problem is to find the length of the maximum-length common subsequence of X and Y.
输入
The program input is from the std input. Each data set in the input contains two strings representing the given sequences. The sequences are separated by any number of white spaces. The input data are correct.
输出
For each set of data the program prints on the standard output the length of the maximum-length common subsequence from the beginning of a separate line.
*/
#include<iostream>  
#include<cstdio>  
#include<algorithm>  
#include<cstring>  
using namespace std;  
const int maxn=1000+5;  
  
int n,m;  
int dp[maxn][maxn];  
char s1[maxn],s2[maxn];  
  
int main()  
{  
    while(scanf("%s%s",s1,s2)==2)  
    {  
        n=strlen(s1);//s1串长度  
        m=strlen(s2);//s2串长度  
        memset(dp,0,sizeof(dp));  
  
        for(int i=1;i<=n;i++)  
        for(int j=1;j<=m;j++)  
        {  
            if(s1[i-1]==s2[j-1])  
                dp[i][j]=dp[i-1][j-1]+1;  
            else  
                dp[i][j]=max( dp[i-1][j] , dp[i][j-1] );  
        }  
        printf("%d\n",dp[n][m]);  
    }  
    return 0;  
}  