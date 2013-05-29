/*
ID: silentf1
PROG: theme
LANG: C++
*/
#include<fstream>
#define MAXN 5000 + 5
#define Max(a,b) (a>b?a:b)
using namespace std;
ofstream fout ("theme.out",ios::out);
ifstream fin ("theme.in",ios::in);
int num[MAXN],dp[MAXN],n,MAX=-1;
int main()
{
    fin>>n;
    for(int i=1;i<=n;i++)
        fin>>num[i];
    for(int i=n;i>=1;i--)
        for(int j=1;j<=i-1;j++){
            if(num[i]-num[i+1]==num[j]-num[j+1]){
                dp[j]=dp[j+1]+1;
                if(dp[j]>i-j) dp[j]=i-j;//no repeat
            }else
                dp[j]=1;//important
            MAX=Max(MAX,dp[j]);
        }
    fout<<(MAX>=5?MAX:0)<<endl;
	return 0;
}
