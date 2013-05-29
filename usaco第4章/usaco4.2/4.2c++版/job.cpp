/*
ID: silentf1
PROG: job
LANG: C++
*/
#include<cstdio>
#include<cstring>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define BIGJ 1005
#define BIGM 35
const short A=0,B=1;
long jobcost[2][BIGJ],Mac[2][BIGM],use[BIGM],ma,mb,n,outp=-1;
void cost(short M,short num){
    memset(use,0,sizeof(use));
    for(int i=1;i<=n;i++){
        long MINcost=999999,pos=-1;
        for(int j=1;j<=num;j++)
            if(use[j]+Mac[M][j]<MINcost){
                MINcost=use[j]+Mac[M][j];
                pos=j;
            }
        use[pos]+=Mac[M][pos];
        jobcost[M][i]=use[pos];
    }
}
int main()
{
    freopen("job.in","r",stdin);
    freopen("job.out","w",stdout);
    scanf("%ld%ld%ld",&n,&ma,&mb);
    for(int i=1;i<=ma;i++) scanf("%ld",&Mac[A][i]);
    for(int i=1;i<=mb;i++) scanf("%ld",&Mac[B][i]);
    cost(A,ma);cost(B,mb);
    printf("%ld ",jobcost[A][n]);
    for(int i=1;i<=n;i++) outp=MAX(outp,jobcost[A][i]+jobcost[B][n-i+1]);
    printf("%ld\n",outp);
	return 0;
}
