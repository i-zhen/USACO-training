/*
ID: silentf1
PROG: beads
LANG: C++
*/
#include <fstream>
#include <cstring>
using namespace std;
ofstream fout ("beads.out",ios::out);
ifstream fin ("beads.in",ios::in);
int num,maxn=-1;
char beads[1000];
void work()
{
	for(int i=0;i<num*2;i++)//下标从0开始
	{
		char l=beads[i],r=beads[i+1];//枚举两个扩展端点,一个向左,一个向右
		int nl=0,nr=0,lj=0;//当前扩展长度,lj防止扩展超界
		for(int j=i;j>=0;j--)
			if ((beads[j]==l||beads[j]=='w')&&lj<num)
			{
				if (j-1>=0) if (l=='w') l=beads[j-1];//important,就近扫描法则(独创),先遇到谁,接着就查找谁.
				++nl;
				++lj;//计数
			}
				else break;
		for(int j=i+1;j<num*2;j++)
			if ((beads[j]==r||beads[j]=='w')&&lj<num) 
			{
				if (j+1<num*2) if (r=='w') r=beads[j+1];//important
				++nr;
				++lj;
			}
				else break;
		if (nr+nl>maxn) maxn=nl+nr;//更新
	}
	fout<<maxn<<endl;
}
void init()
{
	fin>>num;
	char beads2[1000];
	fin>>beads2;
	strcpy(beads,beads2);//把bead2赋值到bead.	
	strcat(beads,beads2);//使链变成环状
}
int main()
{
	init();
	work();
	return 0;
}
