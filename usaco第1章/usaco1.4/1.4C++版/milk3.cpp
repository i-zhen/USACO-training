/*
ID: silentf1
PROG: milk3
LANG: C++
*/
#include <fstream>
using namespace std;
ofstream fout ("milk3.out",ios::out);
ifstream fin ("milk3.in",ios::in);
int all[1000],total=0,a=0,b=0,c=0,temp=0;
bool jilu[21][21][21]={false};//用以记录状态,避免陷入死锁
int dfs(int a1,int b1,int c1)
{
	int ax=a1,bx=b1,cx=c1;
	if (jilu[a1][b1][c1]) return 0;//不再搜索重复的状态
	jilu[a1][b1][c1]=true;//记录本次状态
	if(a1==0)//判断是否成立
	{
		total++;
		all[total]=cx;
	}
	if(a1!=0)
	{
		if(b1!=b) //未满
		if((b-b1)>=a1) {b1+=a1;a1=0;dfs(a1,b1,c1);}
			else {a1-=(b-b1);b1=b;dfs(a1,b1,c1);}
		a1=ax;b1=bx;//回溯
		if(c1!=c) 
		if((c-c1)>=a1) {c1+=a1;a1=0;dfs(a1,b1,c1);}
			else {a1-=(c-c1);c1=c;dfs(a1,b1,c1);}
		a1=ax;c1=cx;//回溯
	}
	if(b1!=0)
	{
		if(a1!=a) 
		if((a-a1)>=b1) {a1+=b1;b1=0;dfs(a1,b1,c1);}
			else {b1-=(a-a1);a1=a;dfs(a1,b1,c1);}
		a1=ax;b1=bx;//回溯
		if(c1!=c) 
		if((c-c1)>=b1) {c1+=b1;b1=0;dfs(a1,b1,c1);}
			else {b1-=(c-c1);c1=c;dfs(a1,b1,c1);}
		c1=cx;b1=bx;//回溯
	}
	if(c1!=0)
	{
		if(a1!=a) 
		if((a-a1)>=c1) {a1+=c1;c1=0;dfs(a1,b1,c1);}
			else {c1-=(a-a1);a1=a;dfs(a1,b1,c1);}
		a1=ax;c1=cx;//回溯
		if(b1!=b) 
		if((b-b1)>=c1) {b1+=c1;c1=0;dfs(a1,b1,c1);}
			else {c1-=(b-b1);b1=b;dfs(a1,b1,c1);}
		b1=bx;c1=cx;//回溯
	}
}
int main()
{
	fin>>a>>b>>c;
	dfs(0,0,c);
	for(int i=1;i<=total-1;i++)//排序并输出
		for(int j=1;j<=total-i;j++)
			if (all[j]>all[j+1])
			{
				temp=all[j];
				all[j]=all[j+1];
				all[j+1]=temp;
			}
	for(int i=1;i<=total-1;i++)
		fout<<all[i]<<' ';
	fout<<all[total]<<endl;
    return 0;
}
