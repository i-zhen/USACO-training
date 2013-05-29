/*
ID: silentf1
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct leixing
{
	char name[15];//名字 
	int own,out;//分别表示拥有和支出 
};
ofstream fout ("gift1.out",ios::out);
ifstream fin ("gift1.in",ios::in);
int np;
leixing abc[11];
void work()
{
	char name1[15],name2[15];
	int a,b;
	while (fin>>name2)
	{
		fin>>a>>b;//读入起始金钱以及要分的人数 
		if (b!=0) 
		{
			for(int i=1;i<=b;i++)
			{
				fin>>name1;//分别读入名字
				for(int j=1;j<=np;j++)//枚举比较谁会得到钱 
					if (strcmp(name1,abc[j].name)==0) abc[j].own=abc[j].own+a/b;
			}
			for(int j=1;j<=np;j++)
				if (strcmp(name2,abc[j].name)==0)//枚举所有支出 
				{
					int c=a/b;
					abc[j].out=a+abc[j].out;
					abc[j].own=a-c*b+abc[j].own;//余下不可分的钱 
				}
		}
	}
	for (int i=1;i<=np;i++)
		fout<<abc[i].name<<' '<<abc[i].own-abc[i].out<<endl;//output
}
int main()
{
	fin>>np;
	for(int i=1;i<=np;i++)
		fin>>abc[i].name;//读入名字 
	work();
	return 0;
}
