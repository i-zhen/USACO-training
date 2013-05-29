/*
ID: silentf1
PROG: namenum
LANG: C++
*/
#include <fstream>
#include <cstring>
using namespace std;

ofstream fout ("namenum.out",ios::out);
ifstream fin ("namenum.in",ios::in);
ifstream fin2 ("dict.txt",ios::in);
string dict[6000];
char num[14];
int a=0,err=0;

void init();
int search();
int exchange(char te)
{
	switch(te)
	{
		case('A'):case('B'):case('C'):return 50;
		case('D'):case('E'):case('F'):return 51;
		case('G'):case('H'):case('I'):return 52;
		case('J'):case('K'):case('L'):return 53;
		case('M'):case('N'):case('O'):return 54;
		case('P'):case('R'):case('S'):return 55;
		case('T'):case('U'):case('V'):return 56;
		case('W'):case('X'):case('Y'):return 57;
	}
}
int main()//比较基本的反向构造题目
{
	init();
	search();
	if (err==1) fout<<"NONE"<<endl;
    return 0;
}
int search()
{
	bool tuichu=false;//退出开关;
	int lennum=strlen(num);
	for(int i=1;i<=a;i++)
	{
		if (num[0]==exchange(dict[i][0]))
		{
			bool flag=false;
			for(int j=0;j<dict[i].length();j++)
			{
				if (exchange(dict[i][j])!=num[j]) flag=true;
			}
			if ((flag==false)&&(lennum==dict[i].length()))
			{
				fout<<dict[i]<<endl;
				tuichu=true;//退出开关开启.
			}
		}
		else if (tuichu==true) return 0;
	}
	err=1;
}
void init()
{
	string temp;
	while (fin2>>temp)
	{
		a++;
		dict[a]=temp;
	}
	fin2.close();
	fin>>num;
	fin.close();
}
