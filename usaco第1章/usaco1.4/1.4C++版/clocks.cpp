/*
ID: silentf1
PROG: clocks
LANG: C++
*/
#include <fstream>
using namespace std;
const int state[9][9]= {{3,3,0,3,3,0,0,0,0},
                       {3,3,3,0,0,0,0,0,0},
                       {0,3,3,0,3,3,0,0,0},
					   {3,0,0,3,0,0,3,0,0},
					   {0,3,0,3,3,3,0,3,0},
                       {0,0,3,0,0,3,0,0,3},
					   {0,0,0,3,3,0,3,3,0},
					   {0,0,0,0,0,0,3,3,3},
					   {0,0,0,0,3,3,0,3,3}};
                       //构造状态矩阵 
int fir[9],jg[9],s,sz[9];
ofstream fout ("clocks.out",ios::out);
ifstream fin ("clocks.in",ios::in);
void compute(int a,int b)//a是状态的次数,b是哪一种状态 
{
	if (a!=0) s++;
	for(int i=1;i<=a;i++)
		for(int j=0;j<9;j++)
			jg[j]+=state[b][j];
	sz[b]=a;//记录状态 
}
int work()
{
	bool flag=false;
	for(int i=0;i<=3;i++)
		for(int j=0;j<=3;j++)
			for(int k=0;k<=3;k++)
				for(int l=0;l<=3;l++)
					for(int m=0;m<=3;m++)
						for(int n=0;n<=3;n++)
							for(int o=0;o<=3;o++)
								for(int p=0;p<=3;p++)
									for(int q=0;q<=3;q++)//枚举9种状态 
									{
										for(int w=0;w<9;w++) //回溯 
										{
											jg[w]=fir[w];
											sz[w-1]=0;
										}
										s=0;
										compute(i,0);compute(j,1);compute(k,2);
										compute(l,3);compute(m,4);compute(n,5);
										compute(o,6);compute(p,7);compute(q,8);
										flag=true;
										for(int w=0;w<9;w++) //判断是否合法 
											if ((jg[w]%12)!=0) flag=false;
										if(flag==true) //输出 
										{ 
											for(int w=0;w<9;w++)
												if((sz[w]!=0)&&(s>1)) 
												{
													for(int w1=1;w1<=sz[w];w1++)
														fout<<w+1<<' ';
													s--;
												}
												else if((sz[w]!=0)&&(s==1))
												{
													for(int w1=1;w1<=sz[w]-1;w1++)
														fout<<w+1<<' ';
													fout<<w+1<<endl;
													s--;
												}
											return 0;
										}
									}
	return 0;
}
int main()
{
	for(int i=0;i<9;i++)
		fin>>fir[i];
	work();
    return 0;
}
