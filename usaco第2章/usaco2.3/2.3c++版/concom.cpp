/*
ID: silentf1
PROG: concom
LANG: C++
*/
#include <fstream>
using namespace std;
ofstream fout ("concom.out",ios::out);
ifstream fin ("concom.in",ios::in);
int n,h,com[101][101],temp[101];
bool vis[101];
void dfs(int pos)
{
	vis[pos]=true;
	for(int i=1;i<=h;i++)
		temp[i]+=com[pos][i];
	for(int j=1;j<=h;j++)
		if((temp[j]>50)&&(!vis[j])) dfs(j);//满足条件就搜索
}
int main()
{
	fin>>n;
	for(int i1=1;i1<=n;i1++)
	{
		int i,j,p;
		fin>>i>>j>>p;
		com[i][j]=p;
		if(i>h) h=i;
		if(j>h) h=j;
	}
	for(int k=1;k<=h;k++)
	{
		for(int p=1;p<=h;p++) //搜索初始化
		{
			vis[p]=false;//记录已访问点
			temp[p]=0; //记录股份
		}
		dfs(k);
		for(int q=1;q<=h;q++)
			if((temp[q]>50)&&(q!=k)) 
				fout<<k<<' '<<q<<endl;
	}
    return 0;
}
