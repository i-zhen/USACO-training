/*
ID: silentf1
PROG: nuggets
LANG: C++
*/
#include <fstream>
#define MAX(a,b) ((a)>(b)?(a):(b))
using namespace std;
ofstream fout ("nuggets.out",ios::out);
ifstream fin ("nuggets.in",ios::in);
bool dp[1000001];
long n,v[11],gcd,Max,nonum=0;
long Gcd(long a,long b){
    if(a%b==0) return b;
    else return Gcd(b,a%b);
}
int main()
{
    fin>>n;
    if(n==1) {fout<<0<<endl;return 0;}
    for(int i=1;i<=n;i++) fin>>v[i];
    gcd=Gcd(v[1],v[2]);
    for(int i=3;i<=n;i++) gcd=Gcd(gcd,v[i]);
    if(gcd!=1){fout<<0<<endl;return 0;}
    for(int i=1;i<n;i++) Max=MAX(Max,v[i]);
    dp[0]=true;
    for(int i=1;i<=n;i++)
        for(long j=1;j<=Max*Max;j++)
			if(j-v[i]>=0) dp[j]=dp[j] || dp[j-v[i]];
			else dp[j]=dp[j];
    for(long k=Max*Max;k>=1;k--)
        if(!dp[k]) {nonum=k;break;}
    fout<<nonum<<endl;
    return 0;
}
