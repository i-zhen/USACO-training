/*
ID: silentf1
PROG: friday
LANG: C++
*/
#include <fstream>
using namespace std;
ofstream fout("friday.out",ios::out);
ifstream fin("friday.in",ios::in);
int n;
int day[8]={0,0,0,0,0,0,0,0},mo;
void check(int year,int month)//用以确定每个月有多少日子的函数
{
	switch (month)
	{
		case 1:case 3:case 5:case 7:case 8:case 10:case 12:mo=31;break;
		case 4:case 6:case 9:case 11:mo=30;break;
		default:
			if(year%400==0) mo=29;
				else if ((year%4==0)&&(year%100!=0)) mo=29;
						else mo=28;
	}
}
void work()
{
	int m=0,k=0;
	day[13%7]++;//起始加上,表示1900.1.13
	for(int i=1900;i<=1900+n-1;i++)//逐年枚举
	{
		if (i!=1900+n-1) k=12; else k=11;//对于最后一个月特殊处理
		for(int j=1;j<=k;j++)
		{
			check(i,j);
			m+=mo;
			if ((m+13)%7!=0)        
			//所有都是计算的下一个月的(13+m,m是本月的日子),所以最后一年只要计算前11个月就行了.
				day[(m+13)%7]++;
			else 
				day[7]++;
		}
	}
	fout<<day[6]<<' '<<day[7]<<' '<<day[1]<<' '<<day[2]<<' '<<day[3]<<' '<<day[4]<<' '<<day[5]<<endl;
	fout.close();
}
void init()
{
	fin>>n;
	fin.close();
}
int main()
{
	init();
	work();
    return 0;
}
