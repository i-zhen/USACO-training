/*
ID: silentf1
PROG: holstein
LANG: C++
*/
#include <fstream>
using namespace std;
ofstream fout ("holstein.out",ios::out);
ifstream fin ("holstein.in",ios::in);
long v,g,num[18][26],total=15;
bool temp[16],tt[16];
int dfs(int lev,int tot)
{
	bool f=false;
	if (lev>g+1) return 0;
	for(int i=1;i<=v;i++)
		if(num[17][i]<num[0][i])//不满足要求
		{
			f=true;
			break;
		}
	if((tot<total)&&(!f))//满足
	{
		total=tot;//更新
		for(int i=1;i<=g;i++)//更新
			tt[i]=temp[i];
		return 0;
	}
	//选择
	tot++;
	temp[lev]=true;
	for(int i=1;i<=v;i++)
		num[17][i]+=num[lev][i];
	dfs(lev+1,tot);
	//不选
	tot--;
	temp[lev]=false;
	for(int i=1;i<=v;i++)
		num[17][i]-=num[lev][i];
	dfs(lev+1,tot);
}
int main()
{
	fin>>v;
	for(int i=1;i<=v;i++)
		fin>>num[0][i];
	fin>>g;
	for(int i=1;i<=g;i++)
		for(int j=1;j<=v;j++)
		fin>>num[i][j];
	dfs(1,0);
	fout<<total<<' ';
	for(int i=1;i<=g;i++)
	if(tt[i])
	{
		total--;
		if(total>0) fout<<i<<' ';
			else fout<<i<<endl;
	}
    return 0;
}
