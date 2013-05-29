/*
ID: silentf1
PROG: ariprog
LANG: C++
*/
#include <fstream>
using namespace std;
ofstream fout ("ariprog.out",ios::out);
ifstream fin ("ariprog.in",ios::in);
int n,m,sq[125000],a[20000],b[20000];
bool squ[125000]={false};//用以判断是否存在这个数字
void qsort(int l,int r)
{
	int i,j,x,y;
	i=l;
	j=r;
	x=sq[(i+j)/2];
	do
	{
		while(sq[i]<x) i++;
		while(sq[j]>x) j--;
		if(i<=j)
		{
			y=sq[i];
			sq[i]=sq[j];
			sq[j]=y;
			i++;
			j--;
		}
	}
	while(i<=j);
	if (i<r) qsort(i,r);
	if (l<j) qsort(l,j);
}
void work()
{
	//create
	int temp=-1,zt;
	for(int i=0;i<=m;i++)//构造双平方数字
		for(int j=0;j<=m;j++)
		{
			zt=i*i+j*j;//compute
			if (!squ[zt]) {temp++;sq[temp]=zt;}
			squ[zt]=true;
		}
	qsort(0,temp);//排序
	int max=2*m*m,gcmax=0,pointer=0;//max为最大可行平方数字
	bool son=false;
	//main
	for(int i=0;i<=(temp-n+1);i++)//头指针
	{
		gcmax=(max-sq[i])/(n-1);//最大的可能公差
		for(int j=1;j<=gcmax;j++)//枚举判断
		{
			bool flag=true;
			for(int k=1;k<n;k++)
				if(!squ[sq[i]+k*j]) 
				{
					flag=false;
					break;
				}
			if(flag) 
			{
				son=true;//有可行数字
				pointer++;
				a[pointer]=sq[i];
				b[pointer]=j;
			}
		}
	}
	int x=0;
	if(son)//使用泡沫排序b,比较稳定,不会打乱a;
	{
		for(int i=1;i<=pointer-1;i++)
			for(int j=1;j<=pointer-i;j++)
				if (b[j]>b[j+1])
				{
					x=a[j];a[j]=a[j+1];a[j+1]=x;
					x=b[j];b[j]=b[j+1];b[j+1]=x;
				}
		for(int i=1;i<=pointer;i++)
			fout<<a[i]<<' '<<b[i]<<endl;
	}
	if(!son) fout<<"NONE"<<endl;
}
int main()
{
	fin>>n>>m;
	work();
    return 0;
}
