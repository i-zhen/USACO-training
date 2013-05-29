/*
ID: silentf1
PROG: agrinet
LANG: C++
*/
#include<cstdio>
#include<cstdlib>
#define BIG 105
struct Edge{
    long beg,end,len;
}edge[50*BIG];
long n,ne,pos,LEN,vset[BIG],tot=0;
int find(int x){
    if(vset[x]!=x) return find(vset[x]);
    else return x;
}
void unite(int x,int y){
    int i=find(x),j=find(y);
    vset[j]=i; //与vset[i]=j;等效
}
int cmp(const void *a,const void *b){
    Edge A=*(Edge *)a,B=*(Edge *)b;
    return A.len-B.len;
}
int main()
{
    freopen("agrinet.in","r",stdin);
    freopen("agrinet.out","w",stdout);
    scanf("%ld",&n);
    edge[0].len=-BIG;
    for(int i=1;i<=n;i++){
        vset[i]=i;  //初始化并查集
        for(int j=1;j<=n;j++){
            scanf("%ld",&LEN);
            if(i>=j && LEN) {edge[++ne].beg=i;edge[ne].end=j; //只要有效的一部分
                    edge[ne].len=LEN;}
        }
    }
    qsort(edge,ne+1,sizeof(edge[0]),cmp);
    while(n>1){ //kruskal
        if(find(edge[++pos].beg) != find(edge[pos].end)){
            tot+=edge[pos].len;
            unite(edge[pos].beg,edge[pos].end);
            n--;
        }
    }
    printf("%ld\n",tot);
	return 0;
}
