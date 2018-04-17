/*
使用递归解决八皇后问题
*/
#include <iostream>
#include<cmath>
using namespace std;
int q[92][8];
int row[8];
int num=0;
void queen(int i)
{
    int j,k;
    if(i==8)
    {
        for(j=0;j<8;j++)
            q[num][j]=row[j];
        ++num;
        return;
    }
    for(j=1;j<=8;j++)
    {//对[1,8]之间的整数值进行枚举
        for(k=0;k<i;k++)
            if(row[k]==i||abs(k-i)==abs(row[k]-j))
                break;
        if(k==i)
        {
        row[k]=j;
        queen(i+1);
        }
    }
};
int main()
{
    int n;
    int b;
    int i,j;
    std::cin>>n;
    queen(0);
    for(i=0;i<n;i++){
        cin>>b;
        for(j=0;j<8;j++)
            cout<<q[b-1][j];
            cout<<endl;
    }

    return 0;
}
