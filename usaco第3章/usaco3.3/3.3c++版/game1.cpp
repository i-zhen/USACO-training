/*
ID: silentf1
PROG: game1
LANG: C++
*/
#include <fstream>
#define MAX(a,b) ((a)>(b)?(a):(b))
using namespace std;
ofstream fout ("game1.out",ios::out);
ifstream fin ("game1.in",ios::in);
long sum[101],n,dp[101][101];
int main()
{
    fin>>n;
    for(int i=1;i<=n;i++){
        fin>>dp[i][i];
        sum[i]=sum[i-1]+dp[i][i];
    }
    for(int k=0;k<n;k++)
        for(int i=1;i<=n-k;i++)
            for(int j=i;j<=i+k;j++)
                dp[i][j]=MAX(sum[j]-sum[i-1]-dp[i+1][j],sum[j]-sum[i-1]-dp[i][j-1]);
    fout<<dp[1][n]<<' '<<sum[n]-dp[1][n]<<endl;
    return 0;
}
