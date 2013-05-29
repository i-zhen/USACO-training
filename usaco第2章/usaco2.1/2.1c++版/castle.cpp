/*
ID: silentf1
PROG: castle
LANG: C++
*/
#include <fstream>
using namespace std;
ofstream fout ("castle.out",ios::out);
ifstream fin ("castle.in",ios::in);
int n,m,map[51][51],tmap[51][51],xmap[2501],smax=0,num=0,fx[4]={1,2,4,8},tt;
char p;
int floodfill(int x,int y)
{
	tt++;
	tmap[x][y]=num;
	if((15-map[x][y])>0) map[x][y]=15-map[x][y];
		else return 0;
	for(int k=3;k>=0;k--)//从大到小可以过滤掉所有情况.
	{
		if ((map[x][y]-fx[k])>=0) map[x][y]-=fx[k];
			else continue;
		switch (k)//floodfill
		{
			case(0):if( tmap[x][y-1]==0) floodfill(x,y-1);break;
			case(1):if( tmap[x-1][y]==0) floodfill(x-1,y);break;
			case(2):if( tmap[x][y+1]==0) floodfill(x,y+1);break;
			case(3):if( tmap[x+1][y]==0) floodfill(x+1,y);break;
		}
		if (map[x][y]==0) break;
	}
}
int main()
{
	fin>>m>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			fin>>map[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		if (map[i][j]!=0)
		{
			num++;
			tt=0;
			floodfill(i,j);
			xmap[num]=tt;//记录num号房间的面积
			if (tt>smax) smax=tt;
		}
	fout<<num<<endl<<smax<<endl;//输出房间总数和最大面积
	int x=0,y=0;
	for(int j=1;j<=m;j++)
		for(int i=n;i>=1;i--)
		{
			//N
			if ((i-1>0)&&(tmap[i][j]!=tmap[i-1][j])&&((xmap[tmap[i][j]]+xmap[tmap[i-1][j]])>smax))
			{
				x=i;y=j;p='N';
				smax=xmap[tmap[i][j]]+xmap[tmap[i-1][j]];
			}
			//E
			if ((j<m)&&(tmap[i][j]!=tmap[i][j+1])&&((xmap[tmap[i][j]]+xmap[tmap[i][j+1]])>smax))
			{
				x=i;y=j;p='E';
				smax=xmap[tmap[i][j]]+xmap[tmap[i][j+1]];
			}
		}
	fout<<smax<<endl<<x<<' '<<y<<' '<<p<<endl;
	return 0;
}
