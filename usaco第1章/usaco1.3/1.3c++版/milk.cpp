/*
ID: silentf1
PROG: milk
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
typedef long long int64;
int64 a[5000],b[5000];
void init(long l,long r)
{
	long i,j,x,y;
	i=l;j=r;x=a[(i+j)/2];
	do
	{
		while (a[i]<x) ++i;
		while (a[j]>x) --j;
		if (i<=j)
		{
			y=a[i];a[i]=a[j];a[j]=y;
			y=b[i];b[i]=b[j];b[j]=y;
			i++;j--;
		}
	}
	while(i<=j);
	if (i<r) init(i,r);
	if (l<j) init(l,j);
}
int main()
{
	int64 mon=0,m,n;
	ofstream fout ("milk.out",ios::out);
	ifstream fin ("milk.in",ios::in);
	fin>>n>>m;
	for(long i=1;i<=m;i++)
		fin>>a[i]>>b[i];
	init(1,m);//ÅÅÐò 
	long j=0;
	while (n>0)//Ì°ÐÄÑ¡Ôñ
	{
		j++;
		if ((n>0)&&(n-b[j]>=0))
		{
			n=n-b[j];
			mon=mon+a[j]*b[j];
		}
		if ((n>0)&&(n-b[j]<0))
		{
			mon=mon+a[j]*n;
			n=0;
		}
	}
	fout<<mon<<endl;
    return 0;
}
