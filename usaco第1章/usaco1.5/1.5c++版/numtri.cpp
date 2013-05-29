/*
ID: silentf1
PROG: numtri
LANG: C++
*/
#include <fstream>
using namespace std;
ofstream fout ("numtri.out",ios::out);
ifstream fin ("numtri.in",ios::in);
long tri[1001][1001],n,tot=0;
int main()
{
	fin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			fin>>tri[i][j];
	for(int i=2;i<=n;i++)
		for(int j=1;j<=i;j++)//dp[i][j]=max{dp[i-1][j-1],dp[i-1][j]}+dp[i][j]
		{
			if(j==1) tri[i][j]+=tri[i-1][j];
			if(j==i) tri[i][j]+=tri[i-1][j-1];
			if((j!=1)&&(i!=j)) 
				if (tri[i-1][j]>tri[i-1][j-1]) tri[i][j]+=tri[i-1][j];
				else tri[i][j]+=tri[i-1][j-1];
		}
	for(int i=1;i<=n;i++)
		if(tri[n][i]>tot) tot=tri[n][i];
	fout<<tot<<endl;
	return 0;
}
