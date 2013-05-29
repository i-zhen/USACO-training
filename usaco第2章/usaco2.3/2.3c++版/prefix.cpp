/*
ID: silentf1
PROG: prefix
LANG: C++
*/
#include <fstream>
#include<cstring>
using namespace std;
ofstream fout ("prefix.out",ios::out);
ifstream fin ("prefix.in",ios::in);
long len,maxn=0,lent,dl[201];
char pi[201][11];
string core="",temp;
bool f=false;
int main()
{
	for(len=0;;len++)
	{
		fin>>pi[len];
		if(pi[len][0]=='.') break;
		dl[len]=strlen(pi[len]);
	}
	len--;
	while(fin>>temp)
		core+=temp;
	lent=core.length();
	//main
	for(int i=0;i<lent;i++)
	{
		for(int j=0;j<=len;j++)
			if(i+dl[j]>lent) continue; //超界判断
			else
			//if(dl[j]+i>maxn)
			{
				f=false; 
				for(int k=0;k<dl[j];k++)
					if(core[i+k]!=pi[j][k])  {f=true;break;}
				if (!f) maxn=(dl[j]+i>maxn?dl[j]+i:maxn);  //更新最大值
			}
		if(i+1>maxn) break; //退出条件
	}
	fout<<maxn<<endl;
	return 0;
}
