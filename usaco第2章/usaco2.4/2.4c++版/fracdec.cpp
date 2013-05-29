/*
ID: sacredf1
PROG: fracdec
LANG: C++
*/
#include<fstream>
using namespace std;
ofstream fout ("fracdec.out",ios::out);
ifstream fin ("fracdec.in",ios::in);
int n,d,integer,point=0,decn[1000000],tail,head,y=0;
char deci[100000];
bool f=false;//退出指令
bool check(int n,int a,int b)
{
	if(a==0) return false;//之前没有出现过这个余数
	f=true;
	head=a;
	tail=b;
	if(deci[head]==deci[tail]) tail--;  //是否含有前缀
	else head++;
	return true;
}
int main()
{
	fin>>n>>d;
	if(n>=d) 	integer=n/d;//整数部分处理
	else integer=0;
	for(int i=1;i<=1000000;i*=10) //测试整数部分位数
		if(integer>=i) y++;
		else break;
	if(integer==0) y=1; //首字为0占一位的情况;
	y+=2;//包含括号以及小数点.
	n=(n-(n/d)*d)*10; //余数预处理
	while(n!=0)
	{
		point++;
		while(n<d) //补0
		{
			n*=10;
			deci[point]='0'; //商数补0
			if(check(n,decn[n],point)) break;
			decn[n]=point;//保存位置
			point++;
		}
		if(f) break; //important
		deci[point]=n/d+'0';  //商数
		n=n%d; //余数(事实上存储的是下一位的余数)
		if(check(n,decn[n],point)) break; //检查
		decn[n]=point; //保存位置
		n*=10; //若两个数字只差一位是不用补0的
	}
	fout<<integer<<'.';//输出整数部分和小数点
	if(point==0) fout<<'0';
	if(!f) //可以整除
	{
		for(int i=1;i<=point;i++)
			fout<<deci[i];
		fout<<endl;
		return 0;
	}
	for(int i=1;i<tail;i++)
	{
		if(head==i) fout<<'('<<deci[i];
			else	fout<<deci[i];
		if(((y+i)%76==0)&&(i<76)) fout<<endl;
		if((i>76)&&((i-(76-y))%76==0)) fout<<endl;
	}
	if(head==tail) fout<<'(';
	fout<<deci[tail]<<')'<<endl;
	return 0;
}
