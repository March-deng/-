/*
����
A numeric sequence of ai is ordered if a1 < a2 < ... < aN. Let the subsequence of the given numeric sequence (a1, a2, ..., aN) be any sequence (ai1, ai2, ..., aiK), where 1 <= i1 < i2 < ... < iK <= N. For example, sequence (1, 7, 3, 5, 9, 4, 8) has ordered subsequences, e. g., (1, 7), (3, 4, 8) and many others. All longest ordered subsequences are of length 4, e. g., (1, 3, 5, 8).

Your program, when given the numeric sequence, must find the length of its longest ordered subsequence.
����
The first line of input file contains the length of sequence N. The second line contains the elements of sequence - N integers in the range from 0 to 10000 each, separated by spaces. 1 <= N <= 1000
���
Output file must contain a single integer - the length of the longest ordered subsequence of the given sequence.
*/
#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <iostream>  
using namespace std;  
const int N = 1e6+10;  
int a[N],n,m;  
bool judge(int k)//ö�ټ��k�����ܷ�ʹ����������ţ  
{  
    int cnt = a[0], num = 1;//numΪ1��ʾ�Ѿ���һͷţ����a[0]ţ����  
    for(int i = 1; i < n; i ++)//ö��ʣ�µ�ţ��  
    {  
        if(a[i] - cnt >= k)//a[i]���ţ������һ��ţ�������ڵ���k����ʾ�����ٷŽ�ţ  
        {  
            cnt = a[i];  
            num ++;//�ַŽ���һͷţ  
        }  
        if(num >= m) return true;//����ţ��������  
    }  
    return false;  
}  
void solve()  
{  
    int l = 1, r = a[n-1] - a[0];//��С����Ϊ1��������Ϊţ��������ļ�ȥ�����С��  
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
        sort(a, a+n);//��ţ������  
        solve();  
    }  
    return 0;  
}  
