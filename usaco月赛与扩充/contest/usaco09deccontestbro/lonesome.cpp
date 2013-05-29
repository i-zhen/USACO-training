/*
PROG: lonesome
LANG: C++
ID: silentf1
*/
#include<cmath>
#include<fstream>
using namespace std;
ifstream fin("lonesome.in");
ofstream fout("lonesome.out");
long n,sum[501][2],x,y;
double dis[501][501],MAX=0;
int main()
{
    fin>>n;
    for(int i=1;i<=n;i++)
      fin>>sum[i][0]>>sum[i][1];
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
      if(i!=j)
        dis[i][j]=(double)sqrt(pow((double)sum[i][0]-sum[j][0],2.0)+pow((double)sum[i][1]-sum[j][1],2.0));
    for(int i=1;i<n;i++)
      for(int j=i+1;j<=n;j++)
      {
        if(dis[i][j]-MAX>0) 
        {MAX=dis[i][j];x=i;y=j;}
      }
    if(x<y) fout<<x<<' '<<y<<endl;
    else fout<<y<<' '<<x<<endl;
    return 0;
}
