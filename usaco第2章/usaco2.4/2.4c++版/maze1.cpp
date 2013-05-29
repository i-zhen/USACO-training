/*
ID: silentf1
PROG: maze1
LANG: C++
*/
#include<fstream>
using namespace std;
ofstream fout ("maze1.out",ios::out);
ifstream fin ("maze1.in",ios::in);
int w,h,xmin[210][100],dl[20000][2],tail=0,fx[4][2]={{-2,0},{0,2},{2,0},{0,-2}},fy[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
char map[210][100];
void  bfs(int head)
{
	int total=0,x,y,p,q;
	xmin[dl[1][0]][dl[1][1]]=1;
	xmin[dl[2][0]][dl[2][1]]=1;
	if((dl[tail][1]==dl[tail-1][1])&&(dl[tail-1][0]==dl[tail][0])) tail--;//相同地点只扩展一个
	while(head<=tail)
	{
		head++;
		x=dl[head][0];
		y=dl[head][1];
		for(int i=0;i<=3;i++)
		{
			p=x+fx[i][0];q=y+fx[i][1];
			if((p>0)&&(p<h)&&(q>0)&&(q<w)&&(map[x+fy[i][0]][y+fy[i][1]]==' '))  //边界条件
			if((xmin[p][q]==0)||(xmin[p][q]>(xmin[x][y]+1)))  //扩展条件
			{
				tail++;
				dl[tail][0]=p;
				dl[tail][1]=q;
				xmin[p][q]=xmin[x][y]+1;
			}
		}
	}
	for(int i=1;i<=h;i++) 
		for(int j=1;j<=w;j++)
			total=(xmin[i][j]>total?xmin[i][j]:total);
	fout<<total<<endl;
}
int main()
{
	fin>>w>>h;
	h=2*h+1;
	w=2*w+1;
	for(int i=1;i<=h;i++)
	{
		fin.get();	//读回车
		for(int j=1;j<=w;j++)
		{
			map[i][j]=fin.get();
			if((i==1)&&(map[i][j]==' ')) {tail++;dl[tail][0]=i+1;dl[tail][1]=j;}
			if((i==h)&&(map[i][j]==' ')) {tail++;dl[tail][0]=i-1;dl[tail][1]=j;}
			if((j==1)&&(map[i][j]==' ')) {tail++;dl[tail][0]=i;dl[tail][1]=j+1;}
			if((j==w)&&(map[i][j]==' ')) {tail++;dl[tail][0]=i;dl[tail][1]=j-1;}
		}
	}
	bfs(0);
    return 0;
}
