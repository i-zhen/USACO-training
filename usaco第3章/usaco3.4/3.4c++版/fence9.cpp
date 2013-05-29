/*
ID: silentf1
PROG: fence9
LANG: C++
*/
#include<fstream>
#include<cmath>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
ofstream fout ("fence9.out",ios::out);
ifstream fin ("fence9.in",ios::in);
const double JD = 0.000001;
double n,m,p,pick;
inline long function(double k,double b,long start,long end){//·½³ÌÕÒµã
    long total=0;//important
    double y=0.0;
    for(int i=start;i<=end;i++){
        y=k*i+b;
        if(fabs(y-(long)y)-JD<0) total++;
    }
    return total;
}
int main()
{
    fin>>n>>m>>p;
    if(n==0) pick+=m+1;
    else pick+=function(m/n,0.0,0,(long)n);
    fout<<pick<<endl;
    if(n-p==0) pick+=m+1;
    else pick+=function(m/(n-p),(m*p)/fabs(n-p),(long)MIN(n,p),(long)MAX(n,p));
    fout<<pick<<endl;
    pick+=p-2;
    fout<<(long)(p*m/2-pick/2+1)<<endl;
    return 0;
}
