/*
���͵�Լɪ�����⣬����ʹ������ʵ�֡�
*/
#include<iostream>
int main()
{
    int flag[305]={0};
    int n,m;
    std::cin>>n>>m;
    int temp1;
    int temp2;
    int index=0;//��ǰ���
    int steps=0;//ָʾ�Ѿ��߹��Ĳ���
    for(int i=1;i<n;i++){
        while(steps!=m-1){
            index=(index+1)%6;
            std::cout<<index<<std::endl;
            if(flag[index]==0)
                steps++;
        }
        flag[index]=1;
        temp1=index;
        while(index!=temp1){
            if(flag[(++index)%6]==0){
                temp2=index;
                break;
            }
            else{
                index=(index+1)%6;
            }
        }
        steps=0;
    }

}
