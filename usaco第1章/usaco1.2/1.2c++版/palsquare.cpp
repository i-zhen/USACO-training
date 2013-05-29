/*
ID: silentf1
PROG: palsquare
LANG: C++
*/
#include<iostream>
#include <fstream>
#include<cstring>
using namespace std;
ofstream fout ("palsquare.out",ios::out);
ifstream fin ("palsquare.in",ios::in);
char te[10];int le=0;
void zhuanhuan(int a,int n);
bool panduan(char *b)
{
	for(unsigned int i=0;i<strlen(b)/2;i++)
		if (b[i]!=b[strlen(b)-i-1]) return false;
	return true;
}
int main()
{
	int num=0;
	fin>>num;
	for(int i=1;i<=300;i++)
	{
		zhuanhuan(i*i,num);
		if (panduan(te))
		{
			zhuanhuan(i,num);
			for(int p=le;p>=0;p--)
				fout<<te[p];
			fout<<' ';
			zhuanhuan(i*i,num);
			fout<<te<<endl;
		}
	}
    return 0;
}
void zhuanhuan(int a,int n)//数制转换函数
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
