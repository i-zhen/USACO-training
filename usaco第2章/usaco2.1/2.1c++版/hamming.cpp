/*
ID: silentf1
PROG: hamming
LANG: C++
*/
#include <fstream>
#include <string>
using namespace std;
ofstream fout ("hamming.out",ios::out);
ifstream fin ("hamming.in",ios::in);
int n,b,d,tb[8]={1,3,7,15,31,63,127,255},dl[256],poi;
int main()
{
	fin>>n>>b>>d;
	dl[1]=0;
	poi=1;
	for(int i=1;i<=tb[b-1];i++)
	{
		int jc1,jc2;
		for(int k=1;k<=poi;k++)
		{
			int p=0;
			for(int i1=1;i1<=8;i1++)
			{
				jc1=i>>(i1-1)&1;//提取某位
				jc2=dl[k]>>(i1-1)&1;//提取某位
				if (jc1!=jc2) p++;//累计海明距离
				if(p>=d) break;
			}
			if(p<d) break;
			else if (k==poi)//插入
			{
				poi++;
				dl[poi]=i;
				break;
			}
		}
		if(poi==n) break;
	}
	for(int k=1;k<=poi;k++)
	{
		fout<<dl[k];
        if ((k%10==0)||(k==poi)) fout<<endl;
        else fout<<" ";
		}
    return 0;
}
