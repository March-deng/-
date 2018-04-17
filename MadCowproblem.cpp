/*
描述
A numeric sequence of ai is ordered if a1 < a2 < ... < aN. Let the subsequence of the given numeric sequence (a1, a2, ..., aN) be any sequence (ai1, ai2, ..., aiK), where 1 <= i1 < i2 < ... < iK <= N. For example, sequence (1, 7, 3, 5, 9, 4, 8) has ordered subsequences, e. g., (1, 7), (3, 4, 8) and many others. All longest ordered subsequences are of length 4, e. g., (1, 3, 5, 8).

Your program, when given the numeric sequence, must find the length of its longest ordered subsequence.
输入
The first line of input file contains the length of sequence N. The second line contains the elements of sequence - N integers in the range from 0 to 10000 each, separated by spaces. 1 <= N <= 1000
输出
Output file must contain a single integer - the length of the longest ordered subsequence of the given sequence.
*/
#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <iostream>  
using namespace std;  
const int N = 1e6+10;  
int a[N],n,m;  
bool judge(int k)//枚举间距k，看能否使任意两相邻牛  
{  
    int cnt = a[0], num = 1;//num为1表示已经第一头牛放在a[0]牛栏中  
    for(int i = 1; i < n; i ++)//枚举剩下的牛栏  
    {  
        if(a[i] - cnt >= k)//a[i]这个牛栏和上一个牛栏间距大于等于k，表示可以再放进牛  
        {  
            cnt = a[i];  
            num ++;//又放进了一头牛  
        }  
        if(num >= m) return true;//所有牛都放完了  
    }  
    return false;  
}  
void solve()  
{  
    int l = 1, r = a[n-1] - a[0];//最小距离为1，最大距离为牛栏编号最大的减去编号最小的  
    while(l < r)  
    {  
        int mid = (l+r) >> 1;  
        if(judge(mid)) l = mid + 1;  
        else r = mid;  
    }  
    printf("%d\n",r-1);  
}  
int main()  
{  
    int i;  
    while(~scanf("%d%d",&n,&m))  
    {  
        for(i = 0; i < n; i ++)  
            scanf("%d",&a[i]);  
        sort(a, a+n);//对牛栏排序  
        solve();  
    }  
    return 0;  
}  
