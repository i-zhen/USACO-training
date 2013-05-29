/*
ID: silentf1
PROG: range
LANG: C++
*/
#include <fstream>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
ofstream fout ("range.out",ios::out);
ifstream fin ("range.in",ios::in);
char map[251][251];
long sum[251][251],n,lens,square[251];
int main()
{
    fin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            fin>>map[i][j];
            if(map[i][j]=='1') sum[i][j]=1;
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            sum[i][j]=sum[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=2;k<=MIN(n-i+1,n-j+1);k++)
                if(sum[i+k-1][j+k-1]-sum[i-1][j+k-1]-sum[i+k-1][j-1]+sum[i-1][j-1]==k*k){
                    square[k]++;
                    lens=MAX(lens,k);}
                else break;
    for(int i=2;i<=lens;i++)
        fout<<i<<' '<<square[i]<<endl;
    return 0;
}
