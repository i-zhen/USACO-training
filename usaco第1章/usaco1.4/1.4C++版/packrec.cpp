/*
PROG: packrec
LANG: C++
*/
#include <fstream>
using namespace std;
ofstream fout ("packrec.out",ios::out);
ifstream fin ("packrec.in",ios::in);
int num[4][2],minx=20000,s[5000][2],len=-1;
int isbig(int a,int b)
{
	if (b>=a) return b;
		else return a;
}
void takein(int p,int q) //插入最优结果
{
	int temp=0;
	if(p>q)//保证边的顺序
	{
		temp=p;
		p=q;
		q=temp;
	}
	if((p*q)<minx)//refresh
	{
		len=-1;
		len++;
		s[len][0]=p;
		s[len][1]=q;
	}
	if((p*q)==minx)//插入相同的
	{
		temp=0;
		while((p>s[temp][0])&&(temp<=len)) temp++;
		if(p!=s[temp][0])//判重
		{
		if(temp<=len){//边插入边排序.
		for(int i=len+1;i>temp;i--)
			{
				s[i][0]=s[i-1][0];
				s[i][1]=s[i-1][1];
			}
			s[temp][0]=p;
			s[temp][1]=q;
			len++;}
		else
		{
			len++;
			s[temp][0]=p;
			s[temp][1]=q;
		}
		}
	}
	if (p*q<minx) minx=p*q; //不判断会出错
}
void work()
{
	int p=0,q=0;
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
		if (i!=j) //判重
			for(int k=0;k<4;k++)
			if((k!=j)&&(i!=k))//判重
				for(int l=0;l<4;l++)
				if((i!=l)&&(j!=l)&&(k!=l))//判重
					for(int i1=0;i1<=1;i1++)
						for(int j1=0;j1<=1;j1++)
							for(int k1=0;k1<=1;k1++)
								for(int l1=0;l1<=1;l1++) //枚举方向
								{
								    //1
									p=0;q=0;
									p=isbig(num[i][i1],isbig(num[j][j1],isbig(num[k][k1],num[l][l1])));
									q=num[i][1-i1]+num[j][1-j1]+num[k][1-k1]+num[l][1-l1];
									takein(p,q);
									//2
									p=0;q=0;
									p=isbig(num[i][i1],isbig(num[k][k1],num[j][j1]))+num[l][1-l1];
									q=isbig(num[i][1-i1]+num[j][1-j1]+num[k][1-k1],num[l][l1]);
									takein(p,q);
									//3
									p=0;q=0;
									p=isbig(isbig(num[i][i1],num[j][j1])+num[l][1-l1],num[k][k1]);
									q=isbig(num[l][l1],num[i][1-i1]+num[j][1-j1])+num[k][1-k1];
									takein(p,q);
									//4&5
									p=0;q=0;
									p=isbig(num[i][i1],isbig(num[j][j1]+num[k][k1],num[l][l1]));
									q=num[i][1-i1]+num[l][1-l1]+isbig(num[j][1-j1],num[k][1-k1]);
									takein(p,q);
									//6
									p=0;q=0;
									p=isbig(num[i][i1]+num[j][j1],num[k][k1]+num[l][l1]);//先固定一端
									//取当前最大的q,需要交叉匹配
									q=isbig(num[j][1-j1]+num[l][1-l1],num[k][1-k1]+num[j][1-j1]);
									q=isbig(q,num[i][1-i1]+num[l][1-l1]);
									q=isbig(q,num[i][1-i1]+num[k][1-k1]);
									//判断是否可以嵌套
									if((num[k][k1]>num[i][i1])&&(num[i][1-i1]>num[j][1-j1]))
											q=isbig(num[i][1-i1]+num[k][1-k1],num[j][1-j1]+num[l][1-l1]);
									takein(p,q);
								}
	fout<<minx<<endl;
	for(int i=0;i<=len;i++)
		fout<<s[i][0]<<' '<<s[i][1]<<endl;
}
int main()
{
	for(int i=0;i<4;i++)
		fin>>num[i][0]>>num[i][1];
	work();
	return 0;
}
