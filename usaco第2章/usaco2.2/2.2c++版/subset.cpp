/*
ID: silentf1
PROG: subset
LANG: C++
*/
#include <fstream>
using namespace std;
ofstream fout ("subset.out",ios::out);
ifstream fin ("subset.in",ios::in);
long long n,f[40][800];
int main()
{
	fin>>n;
	if(((1+n)*n/2)%2!=0) fout<<0<<endl;
	else
	{
		f[0][0]=1;//±ß½çÌõ¼þ
		for(int i=1;i<=n;i++)
			for(long long j=0;j<=(1+i)*i/2;j++)
			f[i][j]=((j-i>=0)?(f[i-1][j]+f[i-1][j-i]):f[i-1][j]);
		fout<<f[n][(1+n)*n/4]/2<<endl;
	}
    return 0;
}
