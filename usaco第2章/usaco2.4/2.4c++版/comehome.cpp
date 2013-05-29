/*
ID: silentf1
PROG: comehome
LANG: C++
*/
#include<fstream>
#include<cctype>
using namespace std;
ofstream fout ("comehome.out",ios::out);
ifstream fin ("comehome.in",ios::in);
long zm[53][2],f[53][53],n,te,m=0,dis=100000000;
int main()
{
	char a,b,t;
	int p,q;
	fin>>n;
	for(int i=1;i<=n;i++) //init
	{
		fin>>a>>b>>te;
		if(isupper(a)) p=a-64;else p=a-70;
		if(isupper(b)) q=b-64;else q=b-70;
		if(zm[p][0]==0) {m++;zm[p][0]=m;zm[p][1]=(p<27?0:1);}
		if(zm[q][0]==0) {m++;zm[q][0]=m;zm[q][1]=(q<27?0:1);}
		if((f[zm[p][0]][zm[q][0]]==0)||(f[zm[p][0]][zm[q][0]]>te)) 
		{
			f[zm[p][0]][zm[q][0]]=te;
			f[zm[q][0]][zm[p][0]]=te;
		}
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
		if(f[i][j]==0) f[i][j]=100000000;
	for(int k=1;k<=m;k++)
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
			if(i!=j)	f[i][j]=((f[i][j]>(f[i][k]+f[k][j]))?f[i][k]+f[k][j]:f[i][j]);
	for(int i=1;i<26;i++)
	if((zm[i][0]!=0)&&(zm[i][1]==0))
		if(dis>f[zm[i][0]][zm[26][0]]) {dis=f[zm[i][0]][zm[26][0]];t=i+64;}
	fout<<t<<' '<<dis<<endl;
	return 0;
}
