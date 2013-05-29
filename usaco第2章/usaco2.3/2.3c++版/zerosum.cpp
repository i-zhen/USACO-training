/*
ID: silentf1
PROG: zerosum
LANG: C++
*/
#include <fstream>
using namespace std;
ofstream fout ("zerosum.out",ios::out);
ifstream fin ("zerosum.in",ios::in);
int n,total=0,dl[10],tot[1000][10];
int compute()
{
	long long endt=1,temp,i=1,k,te,j;
	while(i<n) //惰性计算技术
	{
		temp=endt;
		for(j=i;j<n;j++) //module 1
		if(dl[j]==1)
			if(dl[j-1]!=1) temp=j*11+1;
				else temp=temp*10+j+1;
		else break;
		i=j;//迭代指针
		te=temp;
		k=i;//计算指针
		temp=i+1;
		for(j=i+1;j<n;j++)//module 2
		if(dl[j]==1)
			if(dl[j-1]!=1) temp=j*11+1;
				else temp=temp*10+j+1;
		else break;
		if(dl[k]==2) endt=te+temp; //延迟计算
		if(dl[k]==3) endt=te-temp; //延迟计算
		i=j-1;//j-1未计算
		i++;
	}
	if(endt==0) 
	{
		total++;
		for(int i=1;i<n;i++)
			tot[total][i]=dl[i];
	}
}
int dfs(int lev)
{
	if(lev==n)
	{
		compute();
		return 0;
	}
	for(int i=1;i<=3;i++)
	{
		dl[lev]=i;
		dfs(lev+1);
	}
}
int main()
{
	fin>>n;
	dfs(1);
	for(int i=1;i<=total;i++)
	{
		fout<<1;
		for(int j=1;j<n;j++)
		{
			if (tot[i][j]==1) fout<<' ';
			if (tot[i][j]==2) fout<<'+';
			if (tot[i][j]==3) fout<<'-';
			fout<<j+1;
		}
		fout<<endl;
	}
    return 0;
}
