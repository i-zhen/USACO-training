/*
ID: silentf1
PROG: rockers
LANG: C++
*/
#include <fstream>
#define MAX(a,b) ((a)>(b)?(a):(b))//Ë«ÖØDP
using namespace std;
ofstream fout ("rockers.out",ios::out);
ifstream fin ("rockers.in",ios::in);
long dp[21][21],reg[21][21],pack[21],v[21],n,t,m;
int main()
{
    fin>>n>>t>>m;
    for(int i=1;i<=n;i++) fin>>v[i];
    for(int k=0;k<n;k++)
        for(int K=1;K<=n-k;K++){
            for(int i=K;i<=K+k;i++)
                for(int j=t;j>=1;j--)
                if(j-v[i]>=0) pack[j]=MAX(pack[j],pack[j-v[i]]+1);
                    else pack[j]=pack[j];
            reg[K][K+k]=pack[t];
            for(int p=0;p<=t;p++) pack[p]=0;
        }
    for(int i=1;i<=n;i++) dp[1][i]=reg[1][i];
    for(int k=1;k<=n;k++)
        for(int i=2;i<=m;i++)
            for(int j=1;j<=n;j++)
                dp[i][j]=MAX(dp[i-1][k]+reg[k+1][j],dp[i][j]);

    fout<<dp[m][n]<<endl;
    return 0;
}
