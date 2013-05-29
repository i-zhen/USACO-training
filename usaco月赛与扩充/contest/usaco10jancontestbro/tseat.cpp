/*
PROG: tseat
LANG: C++
ID: silentf1
*/
#include<fstream>
#include<cmath>
using namespace std;
ifstream fin("tseat.in");
ofstream fout("tseat.out");
struct node{
    int x,y;
    long dis;
}num[5100];
inline bool isbig(node a,node b)
{
  if(a.dis>b.dis) return true;
  if(a.dis==b.dis){ if(a.x<b.x) return true;
                else if(a.y>b.y && a.x==b.x) return true;}
  return false;
}
inline bool islit(node a,node b)
{
	if(a.dis<b.dis) return true;
	if(a.dis==b.dis){ if(a.x>b.x) return true;
                else if(a.y<b.y && a.x==b.x) return true;}
  return false;
}
void qsort(int l,int r)
{
    int i=l,j=r;
    node x,temp=num[(l+r)>>1];
    do
    {
        while(islit(num[i],temp)) i++;
        while(isbig(num[j],temp)) j--;
        if(i<=j)
        {
            x=num[i];
            num[i]=num[j];
            num[j]=x;
            i++;
            j--;
        }
    }
    while(i<=j);
	if(l<j) qsort(l,j);
    if(i<r) qsort(i,r);
}
int w,r,x,y,n=0,mat[51][103];
int main()
{
    fin>>w>>r;
    x=r;y=(1+w)/2;
    for(int i=1;i<=r;i++)
        for(int j=1;j<=w;j++)
        {
            n++;
            num[n].x=i;num[n].y=j;
            num[n].dis=(long)(pow(i-x,2.0)+pow(j-y,2.0));
        }
    qsort(1,n);
    for(int i=1;i<=n;i++)
        mat[num[i].x][num[i].y]=i;
    for(int i=1;i<=r;i++){
        for(int j=1;j<w;j++)
           fout<<mat[i][j]<<' ';
        fout<<mat[i][w]<<endl;
    }
    return 0;
}
