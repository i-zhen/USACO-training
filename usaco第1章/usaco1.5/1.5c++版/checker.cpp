/*
ID: silentf1
PROG: checker
LANG: C++
*/
#include <fstream>
using namespace std;
ofstream fout ("checker.out",ios::out);
ifstream fin ("checker.in",ios::in);
long n,tot[14],total=0,last=0;
int dfs(int lev)
{
	if(total>=3) return 0;
	if (lev>n) 
	{
		total++;
		for(int j=1;j<n;j++)
			fout<<tot[j]<<' ';
		fout<<tot[n]<<endl;
		return 0;
	}
	for(int j=1;j<=n;j++)
	{
		tot[lev]=j;
		bool f=false;
		for(int i=1;i<lev;i++)
		if ((abs(lev-i)==abs(tot[i]-tot[lev]))||(tot[lev]==tot[i])) 
		{
			f=true;
			break;
		}
		if (!f) dfs(lev+1);
	}
	return 0;
}
int dfsbit(long bit,long left,long right)
{
	int temp=0,tt=0;
	if (bit==last) total++;
	else
	{
		temp=last&(~(bit|left|right));//检查空位
		while(temp!=0)//有可行解
		{
			tt=temp&(temp^(temp-1));//取出最右边的1.
			temp-=tt;//去掉最右边的1
			if(tt!=0) dfsbit(bit+tt,(left+tt)<<1,(right+tt)>>1);//移位迭代
		}
	}
	return 0;
}
int main()
{
	fin>>n;
	dfs(1); //正常的搜索,用来显示结果
	if (total!=0) 
	{
		total=0;
		last=(1<<n)-1;//最终的状态
		dfsbit(0,0,0);//搜索所有的可行方案
	}
	fout<<total<<endl;
    return 0;
}
