/*
PROG: snotes
LANG: C++
ID: silentf1
*/
#include<fstream>
using namespace std;
ifstream fin("snotes.in");
ofstream fout("snotes.out");
long jg[1200009];
int main()
{
    long i=0,j=0,k,n,te=0;
    fin>>n>>k;
    for(j=1;j<=n;j++)
    {
       long u;
       fin>>u;
       for(i=1;i<=u;i++)
         jg[te++]=j;
    }
    for(long i=1;i<=k;i++)
    {
      long u;
      fin>>u;
      fout<<jg[u]<<'\n';
    }
    return 0;
}
