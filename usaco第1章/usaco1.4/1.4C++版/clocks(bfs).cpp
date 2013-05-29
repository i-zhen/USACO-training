/*
ID: silentf1
PROG: clocks
LANG: C++
*/
#include <fstream>
const int state[9][9]= {{3,3,0,3,3,0,0,0,0},
									{3,3,3,0,0,0,0,0,0},
									{0,3,3,0,3,3,0,0,0},
									{3,0,0,3,0,0,3,0,0},
									{0,3,0,3,3,3,0,3,0},
									{0,0,3,0,0,3,0,0,3},
									{0,0,0,3,3,0,3,3,0},
									{0,0,0,0,0,0,3,3,3},
									{0,0,0,0,3,3,0,3,3}};
using namespace std;
ofstream fout ("clocks.out",ios::out);
ifstream fin ("clocks.in",ios::in);
int  dl[265000][10],jl[265000][10],head,tail;
void bfs()
{
	head=0;
	tail=1;
	jl[1][0]=1;
	while (head<tail)
	{
		head++;
		//expand
		for(int i=jl[head][0];i<=9;i++)
		if (jl[head][i]<3)//最多三次
		{
			tail++;
			for(int j=1;j<=9;j++)//更新状态
			{
				dl[tail][j]=(dl[head][j]+state[i-1][j-1])%12;//记录当前的表的状态
				dl[tail][0]+=dl[tail][j];
			}
			for(int k=1;k<=9;k++)
				jl[tail][k]=jl[head][k];//从上一个状态扩展得到
			jl[tail][i]++;//记录次数
			jl[tail][0]=i;//非递减扩展
			if(dl[tail][0]==0)
			{
				head=tail;
				break;
			}
		}
	}
	head=0;
	for(int i=1;i<=9;i++)
		if(jl[tail][i]!=0) head+=jl[tail][i];//输出记录,用以记录是否输出完全
	for(int i=1;i<=9;i++)//输出
		for(int j=1;j<=jl[tail][i];j++)
		{
			if (head>1)
				fout<<i<<' ';
			else
				fout<<i;
			head--;//记录剩余输出
		}
	fout<<endl;
}
int main()
{
	for(int i=1;i<=9;i++)
	{
		fin>>dl[1][i];
		dl[1][0]+=(dl[1][i]%12);
	}
	bfs();
    return 0;
}
