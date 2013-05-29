/*
ID: silentf1
PROG: transform
LANG: C++
*/
#include <iostream>//本题目就是枚举,完全考察矩阵下标的关系以及数组 
using namespace std;
char word[11][11],tword[11][11];
int n;
void init()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>word[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>tword[i][j];	
}
int flip();
int main()
{
	freopen("transform.in","r",stdin);
	freopen("transform.out","w",stdout);
	init();
	cout<<flip()<<endl;
    return 0;
}
int flip()
{
	bool flag=true;
	//1
	flag=true;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if (word[j][i]!=tword[i][n-j+1])
			{
				flag=false;
				break;
			}
		}
	if (flag==true) return 1;
	//2
	flag=true;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if (word[i][j]!=tword[n-i+1][n-j+1])
			{
				flag=false;
				break;
			}
		}
	if (flag==true) return 2;
	//3
	flag=true;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if (word[j][i]!=tword[n-i+1][j])
			{
				flag=false;
				break;
			}
		}
	if (flag==true) return 3;
	//4
	flag=true;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if (word[i][j]!=tword[i][n-j+1])
			{
				flag=false;
				break;
			}
		}
	if (flag==true) return 4;
	//5
	flag=true;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if (word[j][n-i+1]!=tword[i][n-j+1])
			{
				flag=false;
				break;
			}
		}
	if (flag==true) return 5;
	flag=true;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if (word[i][n-j+1]!=tword[n-i+1][n-j+1])
			{
				flag=false;
				break;
			}
		}
	if (flag==true) return 5;
	flag=true;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if (word[j][n-i+1]!=tword[n-i+1][j])
			{
				flag=false;
				break;
			}
		}
	if (flag==true) return 5;
	//6
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if (word[i][j]!=tword[i][j]) 
			{
				flag=false;
				break;
			}
		}
	if (flag==true) return 6;
	return 7;
}
