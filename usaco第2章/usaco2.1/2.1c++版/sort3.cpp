/*
ID: silentf1
PROG: sort3
LANG: C++
*/
#include <fstream>
using namespace std;
ofstream fout ("sort3.out",ios::out);
ifstream fin ("sort3.in",ios::in);
int n,num[1001],tot[4][2],tt=0;
bool flag;
void swap(int &a,int &b)
{
	int c=a;
	a=b;b=c;
}
int main()
{
	fin>>n;
	for(int i=1;i<=n;i++)
	{
		fin>>num[i];
		tot[num[i]][0]++;
	}
	//初始化区间
	tot[1][1]=tot[1][0];
	tot[2][1]=tot[1][0]+tot[2][0];
	tot[3][1]=tot[2][1]+tot[3][0];
	tot[3][0]=tot[2][1]+1;tot[2][0]=tot[1][1]+1;tot[1][0]=1;
	for(int i=1;i<=3;i++)//模拟即可
		for(int j=tot[i][0];j<=tot[i][1];j++)
		{
			flag=false;
			if ((num[j]!=i)&&(i!=3)) //交换一次;
			for(int k=tot[num[j]][0];k<=tot[num[j]][1];k++)
				if (num[k]==i)
				{
					swap(num[k],num[j]);
					tt++;
					flag=true;
					break;
				}
			if((!flag)&&num[j]!=i)//交换2次
			{
				int k,tail;
				if(i<3) { //向下
								k=tot[num[j]+1][0];
								tail=tot[num[j]+1][1];
							}
				else
				{ //向上
					k=1;
					tail=tot[2][1];
				}
				for(k;k<=tail;k++)
				if (num[k]==i)
				{
					swap(num[k],num[j]);
					tt++;
					break;
				}
			}
		}
	fout<<tt<<endl;
    return 0;
}
