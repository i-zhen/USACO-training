/*
ID: silentf1
PROG: range
LANG: C++
*/
#include<fstream>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define MIN(a,b,c) (Min(Min(a,b),c))
using namespace std;
ofstream fout ("range.out",ios::out);
ifstream fin ("range.in",ios::in);
char map[251][251];
long n,square[251],dp[251][251],lens=0;
int main()
{
    fin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            fin>>map[i][j];
            if(map[i][j]=='0') dp[i][j]=0;
            else dp[i][j]=1;
        }
    for(int i=2;i<=n;i++)
        for(int j=2;j<=n;j++)
        if(map[i][j]=='1'){
            dp[i][j]=MIN(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1;
            if(dp[i][j]>=2) square[dp[i][j]]++; //一边DP一边累加,降低时间复杂度
            lens=MAX(lens,dp[i][j]);
        }
    for(int i=lens-1;i>=2;i--)
        square[i]+=square[i+1]; //将包含的情况累加上
    for(int i=2;i<=lens;i++)
        fout<<i<<' '<<square[i]<<endl;
    return 0;
}
