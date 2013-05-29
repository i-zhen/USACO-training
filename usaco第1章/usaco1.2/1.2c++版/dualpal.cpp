/*
ID: silentf1
PROG: dualpal
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ofstream fout ("dualpal.out",ios::out);
ifstream fin ("dualpal.in",ios::in);
char te[100],le=0;
void zhuanhuan(int a,int n);
bool panduan(char *b,int le)
{
	for(int i=0;i<(le+1)/2;i++)
	{
		if (b[i]!=b[le-i]) return false;
	}
	return true;
}
int main()
{
	int num=0,s=0,ji=0;
	fin>>num>>s;
	while (ji!=num)
	{
		++s;
		int time=0,jinzhi=10;
		while ((time<2)&&(jinzhi>=2))
		{
			zhuanhuan(s,jinzhi);
			if (panduan(te,le)) time++;
			if (time==2) 
			{
				fout<<s<<endl;
				ji++;
			}
			jinzhi--;
		}
	}
    return 0;
}
void zhuanhuan(int a,int n)//任意数制转换函数 
{
	int m,r;
	m=r=-1;
	while (a!=0)
	{
		m=a%n;
		r++;
		if (m<10) te[r]=m+48;
		else te[r]=m+55;
		a=a/n;
	}
	le=r;
}
