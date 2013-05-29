/*
PROG: mmind
LANG: C++
ID: silentf1
*/
#include<fstream>
#include<string>
#include<cstring>
#define BIG 105
using namespace std;
ifstream fin("mmind.in");
ofstream fout("mmind.out");
int n,c[BIG],w[BIG],zc,zw;
char g[BIG][5],work[5];
bool pp[10],okay1[10],okay2[10],flag;
inline bool cmp(char *a,char *b,int now){
    memset(okay1,0,sizeof(okay1));
    memset(okay2,0,sizeof(okay2));
    memset(pp,0,sizeof(pp));
    zc=zw=0;
    for(int i=1;i<=4;i++){
        if(a[i]==b[i-1]) {zc++;pp[a[i]-48]=1;}
        okay1[a[i]-48]=1;
        okay2[b[i-1]-48]=1;
    }
    if(zc!=c[now]) return false;
    for(int i=0;i<=9;i++)
        if(!pp[i] &&(okay1[i]&okay2[i])) zw++;
    if(zw!=w[now]) return false;
    return true;
}
int main(){
    fin>>n;
    for(int i=1;i<=n;i++) fin>>g[i]>>c[i]>>w[i];
    for(int i=1000;i<=9999;i++){
        int zh=i,j=0;
        while(zh){
            work[5-(++j)]=zh%10+48;
            zh/=10;
        }
        flag=true;
        for(int k=1;k<=n;k++)
            if(!cmp(work,g[k],k)) {flag=false;break;}
        if(flag) {fout<<i<<endl;return 0;}
    }
    fout<<"NONE"<<endl;
    return 0;
}
