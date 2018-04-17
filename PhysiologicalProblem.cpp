#include<iostream>
using namespace std;
int main()
{
    int m,n;
    cin>>m;
    while(m--)
    {
        cin>>n;
        int s = 0;
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                for(int k=0;k<=n;k++)
                    if((i+j)%2==0 && (j+k)%3==0 && (i+j+k)%5==0)
                        s = max(s,i+j+k);
        cout<<s<<endl;
    }
    return 0;
}
