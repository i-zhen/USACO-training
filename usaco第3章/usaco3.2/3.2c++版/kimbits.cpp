/*
ID: silentf1
PROG: kimbits
LANG: C++
*/
#include <fstream>
using namespace std;
ofstream fout ("kimbits.out",ios::out);
ifstream fin ("kimbits.in",ios::in);
long long n,l,i,dp[32][32]={0};
int main()
{
    fin>>n>>l>>i;
    for(int p=0;p<=n;p++) dp[0][p]=dp[p][0]=1;
    for(int p=1;p<=n;p++)
        for(int q=1;q<=l;q++)
        if(p>=q) dp[p][q]=dp[p-1][q-1]+dp[p-1][q];
        else dp[p][q]=dp[p][q-1];//继承上一个
    for(int p=n-1;p>=0;p--)
        if(dp[p][l]<i){
            fout<<1;
            i-=dp[p][l];//refresh
            l--;//已经输出了一个1
        }
        else fout<<0;
    fout<<endl;
    return 0;
}
