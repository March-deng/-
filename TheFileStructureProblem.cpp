/*
�ڼ�����Ͽ����ļ�ϵͳ�Ľṹͨ�������á�Microsoft Windows�����"explorer"�������������һ�����ӡ���������ͼ�ν���֮ǰ��û��ͼ�λ��ı�ʾ�����ģ���ʱ����õķ�ʽ�ǰ�Ŀ¼���ļ��Ľṹ��ʾ��һ��"ͼ"�����ӣ�����ʹ�����ŵ���ʽ����ʾĿ¼�Ľṹ�����磺


ROOT
|     dir1
|     file1
|     file2
|     file3
|     dir2
|     dir3
|     file1
file1
file2
���ͼ˵����ROOTĿ¼����������Ŀ¼�������ļ�����һ����Ŀ¼����3���ļ����ڶ�����Ŀ¼�ǿյģ���������Ŀ¼����һ���ļ���

����
���������дһ�������ȡһЩ�������ݡ�ÿ��������ݱ�ʾһ����������ļ��ṹ��ÿ�����������'*'��β�������к��������������'#'��β��һ��������ݰ���һЩ�ļ���Ŀ¼�����֣���Ȼ������������û�и��������������ܼ���ROOTĿ¼��������Ŀ¼������������,��']'��ʾһ��Ŀ¼�����ݵĽ�����Ŀ¼���ֵĵ�һ����ĸ��'d'���ļ����ֵĵ�һ����ĸ��'f'���ļ�����������չ��Ҳ����û�У�����fmyfile.dat��fmyfile�����ļ���Ŀ¼�������ж��������ո�,���ȶ�������30��һ��Ŀ¼�µ���Ŀ¼�������ļ�����֮�Ͳ�����30��
���
����ʾһ��Ŀ¼�����ݵ�ʱ������ʾ���е���Ŀ¼������еĻ�����Ȼ������ʾ�ļ�������еĻ������ļ�Ҫ�������ֵ���ĸ���˳����ʾ��Ŀ¼���ð������ֵ���ĸ��˳����ʾ��ֻ��Ҫ����Ŀ¼���ֵ��Ⱥ���ʾ������ÿһ��������ݣ�����Ҫ�����"DATA SET x:"������x�ǲ������ݵı�ţ���1��ʼ�����������������֮��Ҫ���һ��������������

����Ҫע����ǣ�����ʹ��һ��'|'��5���ո�����ʾ�����ŵĲ�Ρ�
*/
#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int FileStructure(int level,string dir,int nCase)//��level���������ͼ���еĲ��
                                        //����ֵΪint�͵�ԭ���ǿ����÷���ֵ��������������ѭ����
{
    vector<string> v;
    for(int i=1;i<=level;i++)
        std::cout<<"|     ";
    if(level!=0)
        std::cout<<dir<<std::endl;
    //����ݹ�ѭ����
    int t=0;//���Ա�ʾ�Ƿ��ڡ�ROOT����
    while(true)
    {
        string s;
        std::cin>>s;
        if(s[0]=='#')
            return 1;
        if(t==0&&level==0){
            std::cout<<"DATA SET"<<nCase<<":"<<std::endl;
            std::cout<<dir<<std::endl;
            t=1;
        }
        if(s[0]=='*')
            break;
        if(s[0]=='f')
            v.push_back(s);
        if(s[0]=='d')
            FileStructure(level+1,s,nCase);
        if(s[0]==']')
            break;
    }
    sort(v.begin(),v.end());
    vector<string>::iterator it = v.begin();
    for(;it!=v.end();it++){
        for(int i=1;i<=level;i++){
            std::cout<<"|     ";
        }
        std::cout<<*it<<std::endl;
    }
    return 1;
}
int main()
{
    int nCase=0;
    while(true){
        int endn=FileStructure(0,"ROOT",nCase);
        if(endn==0)
            break;
        std::cout<<endl;
    }
    return 0;
}
