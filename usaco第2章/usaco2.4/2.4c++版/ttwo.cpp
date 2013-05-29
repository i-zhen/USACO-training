/*
ID: silentf1
PROG: ttwo
LANG: C++
*/
#include<fstream>
using namespace std;
ofstream fout ("ttwo.out",ios::out);
ifstream fin ("ttwo.in",ios::in);
char map[11][11];
int i,j,f[2],c[2],tf[4][2]={{-1,0},{0,1},{1,0},{0,-1}},tc[4][2]={{-1,0},{0,1},{1,0},{0,-1}},TIME=0,tmap[11][11];
bool bianjie(int x,int y,int &a)
{
	if(map[x][y]=='*') 
	{
		a=(a+1)%4;
		return true;
	}
	if((x<1)||(x>10)||(y<1)||(y>10)) 
	{
		a=(a+1)%4;
		return true;
	}
	return false;
}
int main()
{
	for(int i=1;i<=10;i++)  //init
		for(int j=1;j<=10;j++)
		{
			fin>>map[i][j];
			if(map[i][j]=='F') {f[0]=i;f[1]=j;}
			if(map[i][j]=='C') {c[0]=i;c[1]=j;}
		}
	i=0;
	j=0;
	while (true)
	{
		if(!bianjie(f[0]+tf[i][0],f[1]+tf[i][1],i))
		{
			f[0]+=tf[i][0];
			f[1]+=tf[i][1];
		}
		tmap[f[0]][f[1]]++;
		if(!bianjie(c[0]+tc[j][0],c[1]+tc[j][1],j))
		{
			c[0]+=tc[j][0];
			c[1]+=tc[j][1];
		}
		tmap[c[0]][c[1]]++;
		TIME++;
		if((f[1]==c[1])&&(f[0]==c[0])) {fout<<TIME<<endl;return 0;}
		if ((tmap[f[0]][f[1]]>200)||(tmap[c[0]][c[1]]>200))break;
	}
	fout<<0<<endl;
    return 0;
}
