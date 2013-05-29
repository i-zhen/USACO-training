/*
ID: silentf1
PROG: ride
LANG: C++
*/
#include <iostream>
using namespace std;
char a[7],b[7];
int hash(char *c)//带指针,使用指针表示数组.
{
	int temp=1;
	while (*c)//仅当有字符存在时进行计算.
	{
		temp*=*c-64;//转换为数字
		temp%=47;//每次取mod可以使数字不会超界.
		c++;
	}
	return temp;
}
int main()
{
    freopen("ride.out","w",stdout);
    freopen("ride.in","r",stdin);
    cin>>a>>b;
    if (hash(a)==hash(b))
		cout<<"GO"<<endl;
	else
		cout<<"STAY"<<endl;
    return 0;
}
