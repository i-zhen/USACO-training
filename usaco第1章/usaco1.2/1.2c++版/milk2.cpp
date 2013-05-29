/*
ID: silentf1
PROG: milk2
LANG: C++
*/
#include <fstream>
using namespace std;
struct farmer
{
	unsigned int sta,end;//表示开始时间以及结尾时间
};
ofstream fout ("milk2.out",ios::out);
ifstream fin ("milk2.in",ios::in);
farmer nm[5001];
int n;
void init()
{
	fin>>n;
	for(int i=1;i<=n;i++)
		fin>>nm[i].sta>>nm[i].end;
}
void sort(int l,int r);
void work()
{
	int i=1,h=1;
	unsigned int min=0,max=0,t=nm[h].end;//初始化首个结束时间
	for(;i<=n;i++)//采用线性扫描,O(nlogn+n)=O(nlogn)
	{
		if (nm[i].sta<=t)//可以扩展
		{
			if (nm[i].end-nm[h].sta>max) max=nm[i].end-nm[h].sta;
			if (nm[i].end>t) t=nm[i].end; //更新结尾
		}
		else//更新最大空闲时间
		{
			h=i;
			if(nm[i].sta-t>min) min=nm[i].sta-t;
			if (nm[i].end>t) t=nm[i].end;//更新结尾
		}
	}
	fout<<max<<' '<<min<<endl;
}
int main()
{
	init();
	sort(1,n);//离散化
	work();
    return 0;
}
void sort(int l,int r)
{
	int i=l,j=r;
	unsigned int x=nm[(l+r)/2].sta,y;
	do
	{
		while(nm[i].sta<x) ++i;
		while(nm[j].sta>x) --j;
		if (i<=j)
		{
			y=nm[i].sta;
			nm[i].sta=nm[j].sta;
			nm[j].sta=y;
			y=nm[i].end;
			nm[i].end=nm[j].end;
			nm[j].end=y;
			++i;
			--j;
		}
	}
	while(i<=j);
	if (i<r) sort(i,r);
	if (l<j) sort(l,j);
}
