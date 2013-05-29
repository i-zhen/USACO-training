/*
PROG: boost
LANG: C++
ID: silentf1
*/
#include<fstream>
#include<cstring>
#define BIG 25
using namespace std;
ifstream fin("boost.in");
ofstream fout("boost.out");
double MAXN,f,m,F,M,num[BIG][2];
int n,choose[BIG],outp[BIG];
void dfs(int lev){
    if(lev>n){
        F=f;M=m;
        for(int i=1;i<=n;i++) if(choose[i]) F+=num[i][0];
        for(int i=1;i<=n;i++) if(choose[i]) M+=num[i][1];
        if(F/M-MAXN>0){
            MAXN=F/M;
            memcpy(outp,choose,sizeof(choose));
        }
        return ;
    }
    for(int i=0;i<=1;i++){
        choose[lev]=i;
        dfs(lev+1);
    }
}
int main(){
    fin>>f>>m>>n;
    for(int i=1;i<=n;i++) fin>>num[i][0]>>num[i][1];
    dfs(1);
    for(int i=1;i<=n;i++)
        if(outp[i]) fout<<i<<endl;
    return 0;
}
