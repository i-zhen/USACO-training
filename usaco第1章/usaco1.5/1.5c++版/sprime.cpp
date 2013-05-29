/*
ID: silentf1
PROG: sprime
LANG: C++
*/
#include <fstream>
#include<cmath>
using namespace std;
ofstream fout ("sprime.out",ios::out);
ifstream fin ("sprime.in",ios::in);
int n,sum[9],ju[2][4]={{2,3,5,7},{1,3,7,9}};
bool prime(int a) //素数检查
{

for(int i=2;i<=sqrt(a);i++)
   if (a%i==0) return false;
return true;
}
int dfs(int temp,int ad)
{
int pos=0,ad2=ad;//ad2记录当前状态.
if (temp>n)//记录层次
{
   fout<<ad<<endl;
   return 0;
}
if(temp==1) pos=0;//判断首尾
   else pos=1;
for(int k=0;k<4;k++)
{
   sum[temp]=ju[pos][k];
   ad=ad*10+sum[temp];//构造状态
   if(temp!=1)
   if (!prime(ad)||((sum[temp-1]==7)&&(sum[temp==7]))) {ad=ad2;continue;}//剪枝
    else
     dfs(temp+1,ad);
   else
   {
    ad=sum[temp];
    dfs(temp+1,ad);
   }
   ad=ad2;//回溯
}
}
int main()
{
    fin>>n;
    dfs(1,0);
    return 0;
}

