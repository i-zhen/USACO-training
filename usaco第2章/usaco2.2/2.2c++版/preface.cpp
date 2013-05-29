/*
ID: silentf1
PROG: preface
LANG: C++
*/
#include <fstream>
using namespace std;
ofstream fout ("preface.out",ios::out);
ifstream fin ("preface.in",ios::in);
struct num
{
	int tot,realt;
}lm[8];
int n,m,k,temp,fx[5]={0,10,100,1000,10000};
char cnum[8]={' ','I','V','X','L','C','D','M'};
int main()
{
	fin>>n;
	lm[1].realt=1;lm[2].realt=5;lm[3].realt=10;
	lm[4].realt=50;lm[5].realt=100;lm[6].realt=500;lm[7].realt=1000;//init
	for(int i=n;i>=1;i--) //main
	{
		int m,tm2=i,js=0;
		while (tm2!=0)
		{
			js++;
			m=tm2%fx[js];//筛选数位
			tm2-=m;//隔离
			for(int j=7;j>=1;j--)//从大到小筛选
				if(m!=0) //until m=0
				{
					if(lm[j].realt<=m) //正常的联合数字
					{
						if(m-lm[j].realt>=0) k=1;
						if(m-lm[j].realt*2>=0) k=2;
						if(m-lm[j].realt*3>=0) k=3;
						m-=lm[j].realt*k;//筛去
						lm[j].tot+=k;//累计个数
					}
					else if(j>1) //类似4或9这样的数字.
						{ temp=0;//分为2种情况
							if((j%2==0)&&(lm[j].realt-lm[j-1].realt==m)) temp=1;
							if((j%2!=0)&&(lm[j].realt-lm[j-2].realt==m)) temp=2;
							if (temp!=0)
								{
									m=0;//筛去
									lm[j].tot++;//累计
									lm[j-temp].tot++;//累计
								}
						}
				}
				else break;
		}
	}
	for(int i=1;i<=7;i++)//output
	if(lm[i].tot!=0)
		fout<<cnum[i]<<' '<<lm[i].tot<<endl;
    return 0;
}
