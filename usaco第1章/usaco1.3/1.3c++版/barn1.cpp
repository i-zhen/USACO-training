/*
ID: silentf1
PROG: barn1
LANG: C++
*/
#include<fstream>
using namespace std;
ofstream fout("barn1.out",ios::out);
ifstream fin("barn1.in",ios::in);
int m,s,c,le;
int a[201]={0},k[201]={0};
void change(int &a,int &b)
{
  int t=0;t=a;a=b;b=t;
}
void init()
{
     int y=0;
    for(int i=1;i<=c;i++)
      for(int j=1;j<=c-i;j++)
      if(a[j]>a[j+1]) change(a[j],a[j+1]);
    le=a[c]-a[1]+1;//总长度
    for(int i=1;i<c;i++) k[i]=a[i+1]-a[i]-1;//每个单独区间的长度
    for(int i=1;i<c;i++)
      for(int j=1;j<c-i;j++)
      if(k[j]>k[j+1]) change(k[j],k[j+1]);//为区间排序
}
int main()
{   
    fin>>m>>s>>c;
    for(int i=1;i<=c;i++) fin>>a[i];
    init();
    if(m>c) m=c;
    for(int j=c-1;j>=c-m+1;j--) le-=k[j];//贪心
    fout<<le<<endl;
    return 0;
}
