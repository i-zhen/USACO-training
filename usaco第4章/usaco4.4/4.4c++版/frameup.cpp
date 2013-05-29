/*
ID: silentf1
PROG: frameup
LANG: C++
*/
#include<fstream>
#include<cstring>
#include<cstdlib>
#define BIG1 27
#define BIG2 10005
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
const long MAXN=99999;
ofstream fout ("frameup.out",ios::out);
ifstream fin ("frameup.in",ios::in);
char map[35][35],ans[BIG1],outp[BIG2][BIG1];
int m,n,MAP[BIG1][BIG1],lena,sum=0,hash[BIG1];
bool CH[BIG1];
void toposort(int lev){
    if(lev>sum){
        lena++;
        for(int i=sum;i>=1;i--) outp[lena][sum-i]=ans[i];
        return ;
    }
    for(int i=1;i<=sum;i++)
    if(!MAP[hash[i]][0]){
        MAP[hash[i]][0]=MAXN;//标记
        for(int j=1;j<=sum;j++)
            if(MAP[hash[i]][hash[j]]) MAP[hash[j]][0]--;
        ans[lev]=(char)(hash[i]+64);//记录答案
        toposort(lev+1);
        MAP[hash[i]][0]=0;//回溯
        for(int j=1;j<=sum;j++)
            if(MAP[hash[i]][hash[j]]) MAP[hash[j]][0]++;
    }
}
void init(){
    fin>>m>>n;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++){
            fin>>map[i][j];
            if(map[i][j]<65 || map[i][j]>90) continue;
            if(!CH[map[i][j]-64]) hash[++sum]=map[i][j]-64;
            CH[map[i][j]-64]=1;
        }
    for(int k=1;k<=26;k++)
        if(CH[k]){
            int x1=100,y1=100,x2=0,y2=0;//(x1,y1)left up,(x2,y2)right down
			bool rec[BIG1];
			memset(rec,0,sizeof(rec));
            for(int i=1;i<=m;i++)
                for(int j=1;j<=n;j++)
                if(map[i][j]-64==k){
                    x1=MIN(x1,i);y1=MIN(y1,j);
                    x2=MAX(x2,i);y2=MAX(y2,j);
                }
            for(int i=x1;i<=x2;i++){
                if(map[i][y1]-64!=k)
					{MAP[map[i][y1]-64][k]=1;if(!rec[map[i][y1]-64]){MAP[k][0]++;rec[map[i][y1]-64]=1;}}
                if(map[i][y2]-64!=k)
					{MAP[map[i][y2]-64][k]=1;if(!rec[map[i][y2]-64]){MAP[k][0]++;rec[map[i][y2]-64]=1;}}
            }
            for(int j=y1;j<=y2;j++){
                if(map[x1][j]-64!=k)
					{MAP[map[x1][j]-64][k]=1;if(!rec[map[x1][j]-64]){MAP[k][0]++;rec[map[x1][j]-64]=1;}}
                if(map[x2][j]-64!=k)
					{MAP[map[x2][j]-64][k]=1;if(!rec[map[x2][j]-64]){MAP[k][0]++;rec[map[x2][j]-64]=1;}}
            }
        }
}
int cmp(const void *a,const void *b){
    return strcmp((char *)a,(char *)b);
}
int main()
{
    init();
    toposort(1);
    outp[0][0]='0';
    qsort(outp,lena+1,sizeof(outp[0]),cmp);
    for(int i=1;i<=lena;i++) fout<<outp[i]<<endl;
	return 0;
}
