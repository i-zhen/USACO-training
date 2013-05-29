/*
ID: silentf1
PROG: frac1
LANG: C++
*/
#include <fstream>
using namespace std;
ofstream fout ("frac1.out",ios::out);
ifstream fin ("frac1.in",ios::in);
int n;
int dfs(int a,int b,int c,int d)
{
	if((b+d)>n) return 0;
	dfs(a,b,c+a,b+d);
	fout<<a+c<<'/'<<b+d<<endl;
	dfs(a+c,b+d,c,d);
}
int main()
{
	fin>>n;
	fout<<"0/1"<<endl;
	dfs(0,1,1,1);
	fout<<"1/1"<<endl;
    return 0;
}
