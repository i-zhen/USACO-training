/*
ID: silentf1
PROG: money
LANG: C++
*/
#include <fstream>
using namespace std;
ofstream fout ("money.out",ios::out);
ifstream fin ("money.in",ios::in);
int v,n,num[26];
long long f[10001];
int main()
{
	fin>>v>>n;
	for(int i=1;i<=v;i++)
		fin>>num[i];
	f[0]=1;
	for(int i=1;i<=v;i++)
		for(int j=num[i];j<=n;j++)
			f[j]=(num[i]<=j?f[j-num[i]]+f[j]:f[j]);
	fout<<f[n]<<endl;
    return 0;
}
