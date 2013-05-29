/*
PROG: toyshop
LANG: C++
ID: silentf1
*/
#include<fstream>
using namespace std;
ifstream fin("toyshop.in");
ofstream fout("toyshop.out");
const long MAX =25001,Max = 999999;
long n;
double val[MAX],joy[MAX],price[MAX];
long num[MAX],total;
inline void change(double &a,double &b){
    double k=a;
    a=b;b=k;
}
inline void change2(long &a,long &b){
    long k=a;
    a=b;b=k;
}
void qsort(long l,long r){
    long i=l,j=r;
    double x=val[(i+j)/2];
    do{
        while(val[i]-x<0) i++;
        while(val[j]-x>0) j--;
        if(i<=j){
            change(val[i],val[j]);
            change2(num[i],num[j]);
            i++;
            j--;
        }
    }while(i<j);
    if(i<r) qsort(i,r);
    if(l<j) qsort(l,j);
}
int main(){
    fin>>n;
    for(int i=1;i<=n;i++){
        fin>>joy[i]>>price[i];
        if(price!=0) val[i]=joy[i]/price[i];
        else val[i]=Max;
        num[i]=i;
    }
    qsort(1,n);
    for(int i=n;i>=n-2;i--)
        total+=(long)price[num[i]];
    fout<<total<<endl;
    for(int i=n;i>=n-2;i--)
        fout<<num[i]<<endl;
    return 0;
}
