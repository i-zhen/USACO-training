/*
ID: silentf1
PROG: stamps
LANG: C++
*/
#include <fstream>//第十个点9s,O(n^3)
using namespace std;
ofstream fout ("stamps.out",ios::out);
ifstream fin ("stamps.in",ios::in);
long dp[2][2000001];//滚动数组
long k,n,v[51],maxn,outp=1,gun=1,tem=0;
int main()
{
    fin>>k>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>v[i];
        if(maxn<v[i]) maxn=v[i];
    }
    dp[0][0]=true;
    for(int i=1;i<=k;i++)
	{
        for(int t=1;t<=n;t++)
            for(long j=tem;j<=maxn*k;j++)
            if(!dp[gun][j])//避免状态吞噬
            {
                if(j-v[t]>=0) dp[gun][j]=dp[1-gun][j-v[t]] | dp[1-gun][j];
                else dp[gun][j]=dp[1-gun][j];
            }
        while(dp[0][tem] | dp[1][tem]) tem++;//优化
		gun=1-gun;
	}
    while(dp[0][outp] | dp[1][outp]) outp++;
    fout<<outp-1<<endl;
    return 0;
}
