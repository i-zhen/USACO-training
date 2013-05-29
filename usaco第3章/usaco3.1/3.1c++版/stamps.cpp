/*
ID: silentf1
PROG: stamps
LANG: C++
*/
#include <fstream>
#define max(a,b) (a>b?a:b)
using namespace std;
ofstream fout ("stamps.out",ios::out);
ifstream fin ("stamps.in",ios::in);
long dp[2000002],k,n,v[51],maxn;
int main()
{
    fin>>k>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>v[i];
        maxn=max(maxn,v[i]);
    }
    for(long i=1;i<=maxn*k;i++) dp[i]=999999;
    for(long i=1;i<=maxn*k;i++)
    {
        for(int j=1;j<=n;j++)
            if(i-v[j]>=0) dp[i]=(dp[i]<dp[i-v[j]]+1?dp[i]:dp[i-v[j]]+1);
        if(dp[i]>k)//²»Âú×ãÌõ¼þ
        {
            fout<<i-1<<endl;
            return 0;
        }
    }
    fout<<maxn*k<<endl;
    return 0;
}
