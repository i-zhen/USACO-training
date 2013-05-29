/*
ID: silentf1
PROG: lamps
LANG: C++
*/
#include <fstream>
#include<bitset>
using namespace std;
ofstream fout ("lamps.out",ios::out);
ifstream fin ("lamps.in",ios::in);
int n,c,k,make[5]={0,63,42,21,36};
bool lon[7],loff[7],alln[65],ishave=false;
int dfs(int lev,int sta,int tot)
{
	int zt=sta;
	bool istrue=true;
	if(lev>5) return 0;//边界
	if(tot<=c)
	{
		for(int i=1;i<=6;i++)
		{
			if (lon[i]) if (!((sta>>(6-i))&1)) {istrue=false;break;}
			if (loff[i]) if ((sta>>(6-i))&1) {istrue=false;break;}
		}
		if(istrue){
						alln[sta]=true;
						ishave=true;
					}
	}
	sta^=make[lev];
	dfs(lev+1,sta,tot+1); //按
	dfs(lev+1,zt,tot); //不按
	return 0;
}
int main()
{
	fin>>n>>c;
	fin>>k;
	while (k!=-1)
	{
		k%=6;
		if(k==0) k=6;//整位判断
		lon[k]=true;
		fin>>k;
	}
	fin>>k;
	while (k!=-1)
	{
		k%=6;
		if(k==0) k=6;
		loff[k]=true;
		fin>>k;
	}
	dfs(1,63,0);
	if (!ishave) fout<<"IMPOSSIBLE"<<endl;
	else {
				for(int i=0;i<=63;i++)
				if(alln[i])
				{
					k=i;
					for(int j=1;j<=(n/6);j++)
					fout<<bitset<6>(i); //bitset不可以用变量
					if(n%6!=0) {
										k>>=(6-(n%6));
										switch (n%6)
										{
											case(1):fout<<bitset<1>(k)<<endl;break;
											case(2):fout<<bitset<2>(k)<<endl;break;
											case(3):fout<<bitset<3>(k)<<endl;break;
											case(4):fout<<bitset<4>(k)<<endl;break;
											case(5):fout<<bitset<5>(k)<<endl;break;
										}
									}
					else fout<<endl;
				}
			}
    return 0;
}
