/*
ID: silentf1
PROG: humble
LANG: C++
*/
#include<fstream>
using namespace std;
ifstream fin("humble.in");
ofstream fout("humble.out");
typedef long long int64;
const long long  MAX=2147483647;
int64 num[100001];
long s[101][2],n,ln,k,minx=0;
int main()
{
    fin>>k>>n;
    for(int i=1;i<=k;i++) 
    {
      fin>>s[i][0];
      s[i][1]=0;//记录当前的指针 
    }
    num[0]=1;
    while(ln<n)
    {
      int64 minx=MAX,temp=0;
      for(long j=1;j<=k;j++)
      {
        if(num[s[j][1]]*s[j][0]>minx) break;//cut 
        for(long p=s[j][1];p<=ln;p++)
        {
          temp=s[j][0]*num[p];
          if(temp>num[ln])
            if(temp<minx) minx=temp;//更新 
              else break;
          else s[j][1]=p;//记录相对位置 
        }
      }
      num[++ln]=minx;//找到当前的最小值 
    }
    fout<<num[n]<<endl;
    return 0;
}
