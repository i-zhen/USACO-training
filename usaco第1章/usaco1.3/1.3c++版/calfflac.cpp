/*
ID: silentf1
PROG: calfflac
LANG: C++
*/
#include<cstring>
#include<cctype>
#include<fstream>
using namespace std;
ofstream fout ("calfflac.out",ios::out);
ifstream fin ("calfflac.in",ios::in);
char a;
string s="";
int maxn=-1,front=-1,last=-1,len=0,i=0,x,y,z=0;
bool istrue(char a,char b)//判断函数
{
	if(a==b) return true;
	if(a+32==b) return true;
	if(a-32==b) return true;
	return false;
}
void work()
{
	while((x>=0)&&(y<len))//未超界
		{
			if (istrue(s[x],s[y])) {if (z>maxn) {maxn=z;front=x;last=y;}
				  if((x-1>=0)&&(y+1)<len) {x--;y++;z+=2;} else break;}
			else break;//累加
			//隔过不是字母的数字.
			while(!isalpha(s[x])&&(x>0)) {x--;}
			while(!isalpha(s[y])&&(y+1<len)) {y++;}
		}
}
int main()
{
   	 while (!fin.eof())
	{
         a=fin.get();
         if (!fin.eof()) {s+=a;len++;}
	}//初始化
	len--;
        while (i<len)
	{
		while(!isalpha(s[i])&&(i+1<len)) {i++;}//init;隔过不是字母的字符(下同)
		x=i;y=i;z=1;//odd,z为单位扩展长度
		work();
		x=i;y=i+1;z=2;//even
		while(!isalpha(s[y])&&(y+1<len)) {y++;}//init;
		if (istrue(s[x],s[y])) work();//两个相同证明有扩展的必要
		i++;//下移指针
	}
	fout<<maxn<<endl;
	for(int j=front;j<=last;j++)
		fout<<s[j];
	fout<<endl;
    return 0;
}
