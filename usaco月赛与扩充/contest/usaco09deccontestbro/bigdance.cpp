/*
PROG: bigdance
LANG: C++
ID: silentf1
*/
#include<fstream>
using namespace std;
ifstream fin("bigdance.in");
ofstream fout("bigdance.out");
long n,sum=0;
long die(long sta,long end)
{
     if(end-sta>=2)
     {
       int lf=(end-sta+2)/2;//²îÁ¿ 
       die(sta,sta+lf-1);
       die(sta+lf,end);
     }
     if(end-sta==0) return 0;//²»ÀÛ¼Æ 
     if(end-sta==1) sum+=sta*end;
}
int main()
{
    fin>>n;
    die(1,n);
    fout<<sum<<endl;
    return 0;
}
