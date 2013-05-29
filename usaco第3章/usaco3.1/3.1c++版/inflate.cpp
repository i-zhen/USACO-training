/*
ID: silentf1
PROG: inflate
LANG: C++
*/
#include <fstream>
using namespace std;
ofstream fout ("inflate.out",ios::out);
ifstream fin ("inflate.in",ios::in);
int m,n,p[10001],mi[10001],f[10001];
int main()
{
	fin>>m>>n;
	for(int i=1;i<=n;i++) fin>>p[i]>>mi[i];
	for(int i=1;i<=n;i++)
	  for(int j=mi[i];j<=m;j++)
	    f[j]=(f[j]>f[j-mi[i]]+p[i]?f[j]:f[j-mi[i]]+p[i]);
    fout<<f[m]<<endl;
	return 0;
}
