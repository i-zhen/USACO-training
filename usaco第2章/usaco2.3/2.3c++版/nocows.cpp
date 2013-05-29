/*
ID: silentf1
PROG: nocows
LANG: C++
*/
#include <fstream>
using namespace std;
ofstream fout ("nocows.out",ios::out);
ifstream fin ("nocows.in",ios::in);
const int m=9901;
long n,k,temp,dp[101][201];
int main()
{
	fin>>n>>k;
	dp[1][1]=1;
	for(int i=2;i<=k;i++)
		for(int j=3;j<=n;j+=2) //结点只能为奇数
		if((i<8)&&(((1<<i)-1)<j)) break; //剪枝
		else
		{
			if (j<(2*i-1)) continue; //剪枝
			for(int p=1;p<i;p++)
				for(int q=2*i-3;q<j;q+=2)
				{
					temp=((p!=i-1)?2*dp[i-1][q]*dp[p][j-q-1]:dp[i-1][q]*dp[p][j-q-1]);
					dp[i][j]=(temp+dp[i][j]>dp[i][j]?(temp+dp[i][j])%m:dp[i][j]);
				}
		}
	fout<<dp[k][n]<<endl;
    return 0;
}
