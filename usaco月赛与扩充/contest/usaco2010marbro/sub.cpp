/*
PROG: sub
LANG: C++
ID: silentf1
*/
#include<fstream>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define BIG 200
using namespace std;
ifstream fin("sub.in");
ofstream fout("sub.out");
int MAXN,n,m,num1[BIG],num2[BIG],dp[BIG][BIG];
int main(){
    fin>>m>>n;
    for(int i=1;i<=m;i++) fin>>num1[i];
    for(int i=1;i<=n;i++) fin>>num2[i];
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            if(num1[i]==num2[j]){
                dp[i][j]=dp[i-1][j-1]+1;
                MAXN=MAX(MAXN,dp[i][j]);
			}
    fout<<MAXN<<endl;
    return 0;
}
