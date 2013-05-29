/*
PROG: scavhunt
LANG: C++
ID: silentf1
*/
#include<fstream>
using namespace std;
ifstream fin("scavhunt.in");
ofstream fout("scavhunt.out");
long p,q,py[6001],qy[6001],lenp,lenq;
int main(){
    fin>>p>>q;
    for(int i=1;i<=p;i++)
        if(p%i==0) py[++lenp]=i;
    for(int i=1;i<=q;i++)
        if(q%i==0) qy[++lenq]=i;
    for(int i=1;i<=lenp;i++)
        for(int j=1;j<=lenq;j++)
            fout<<py[i]<<' '<<qy[j]<<endl;
    return 0;
}
