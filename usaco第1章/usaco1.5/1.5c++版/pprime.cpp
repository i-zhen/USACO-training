/*
ID: silentf1
PROG: pprime
LANG: C++
*/
#include <fstream>
#include<cmath>
using namespace std;
ofstream fout ("pprime.out",ios::out);
ifstream fin ("pprime.in",ios::in);
long a,b,head=0,tail=10,tw[10]={0,1,2,3,4,5,6,7,8,9},gz=0,dl[100000]={0,0,1,2,3,4,5,6,7,8,9},dl2[100000]={0,1,1,1,1,1,1,1,1,1,1};
//dl是记录回文数,dl2记录当前长度.
bool prime(long c)
{
	double l=sqrt(c);
	for(int i=2;i<=l;i++)
		if(c%i==0) return false;
	return true;
}
int cheng(int a1,int b1)
{
	for(int i=1;i<=b1-1;i++)
		a1*=10;
	return a1;
}
int main()
{
	fin>>a>>b;
	if((5>=a)&&(5<=b)) fout<<5<<endl;
	if((7>=a)&&(7<=b)) fout<<7<<endl;
	if((11>=a)&&(11<=b)) fout<<11<<endl;//特殊处理
	int temp=tail,tt=1;
	while(gz<=b)//无限BFS
	{
		head=tt;
		for(int i=0;i<10;i++)
		{
			for(int j=head;j<=tail;j++)
			{
				temp++;
				gz=cheng(10,dl2[j]+1)*tw[i]+dl[j]*10+tw[i];//计算当前的式子
				if (gz>b) return 0;//结束条件
				else
				{
					dl2[temp]=dl2[j]+2;//数位长度
					dl[temp]=gz;
					if(prime(gz)&&(gz>=a)) fout<<gz<<endl;
				}
			}
		}
		tt=tail+1;
		tail=temp;
	}
	return 0;
}
