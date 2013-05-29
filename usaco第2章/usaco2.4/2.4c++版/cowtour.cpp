/*
ID: silentf1
PROG: cowtour
LANG: C++
*/
#include<fstream>
#include<cmath>
using namespace std;
ofstream fout ("cowtour.out",ios::out);
ifstream fin ("cowtour.in",ios::in);
const double maxn=1000000000;
double map[151][151],pos[151][2],dmap[151],dis=maxn,temp;
long n;
int main()
{
	char te;
	fin>>n;
	for(int i=1;i<=n;i++)	fin>>pos[i][0]>>pos[i][1];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			fin>>te;
			if(te=='1') map[i][j]=sqrt(pow(pos[i][0]-pos[j][0],2)+pow(pos[i][1]-pos[j][1],2));
				else map[i][j]=maxn;
		}
	for(int k=1;k<=n;k++)  //连通图,floyd
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			if(i!=j)	map[i][j]=((map[i][k]+map[k][j]<map[i][j])?map[i][k]+map[k][j]:map[i][j]);
	for(int i=1;i<=n;i++)//自身的最大距离
		for(int j=1;j<=n;j++)
		{
			if ((map[i][j]>dmap[i])&&(map[i][j]<maxn)) dmap[i]=map[i][j];
			if(temp<dmap[i]) temp=dmap[i];
		}
	for(int p=1;p<=n;p++)
		for(int q=1;q<=p;q++)
		if ((map[p][q]==maxn)&&(p!=q))
		{
			map[p][q]=sqrt(pow(pos[p][0]-pos[q][0],2)+pow(pos[p][1]-pos[q][1],2));
			if(dis>(map[p][q]+dmap[p]+dmap[q]))	dis=map[p][q]+dmap[p]+dmap[q];
			map[p][q]=maxn;
		}
	if(dis<temp) dis=temp;//包含关系
	fout.precision(6); //控制精度
	fout.setf(ios::fixed);//输出小数点
	fout<<dis<<endl;
    return 0;
}
