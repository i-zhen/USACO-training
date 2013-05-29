/*
ID: silentf1
PROG: agrinet
LANG: C++
*/
#include<cstdio>
#include<climits>
#define BIG 105
struct Edge{
    long beg,end,len;
}edge[BIG];
long n,mst[BIG][BIG],tot=0;
int main(){
    freopen("agrinet.in","r",stdin);
    freopen("agrinet.out","w",stdout);
    scanf("%ld",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%ld",&mst[i][j]);
    for(int i=1;i<=n;i++){
        edge[i].beg=1;edge[i].end=i;edge[i].len=mst[1][i];}
    for(int k=1;k<=n-1;k++){
        int pos,len=INT_MAX;
        Edge y;
        for(int i=k;i<=n;i++)
            if(edge[i].len && edge[i].len<len){
                len=edge[i].len;
                pos=i;
            }
        tot+=edge[pos].len;
        if(pos!=k){y=edge[k];edge[k]=edge[pos];edge[pos]=y;} //换到处理完的位置
        for(int i=k+1;i<=n;i++){
            if(edge[i].len>mst[edge[k].end][edge[i].end]){
                edge[i].len=mst[edge[k].end][edge[i].end];
                edge[i].beg=edge[k].end;
            }
        }
    }
    printf("%ld\n",tot);
    return 0;
}
