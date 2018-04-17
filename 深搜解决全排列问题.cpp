/*
使用深度优先搜索来解决一定范围的数字内的全排列问题
*/
#include <iostream>
using namespace std;
int n;
int book[10];//用于标记牌的数字的位置，标记为0表示对应位置上的数字仍未放入
int a[10];//用以表示位置状态
void dfs(int step){
    if(step==n+1){
        for(int i=1;i<n+1;i++)
            cout<<a[i]<<" ";
        cout<<endl;
        return;
    }
    for(int i=1;i<n+1;i++){
        if(book[i]==0){
            a[step]=i;
            book[i]=1;
            dfs(step+1);
            book[i]=0;
        }
    }
    return;
}
int main()
{
    cin>>n;
    dfs(1);
    return 0;
}
