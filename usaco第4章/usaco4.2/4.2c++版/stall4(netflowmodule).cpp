/*
ID: silentf1
PROG: stall4
LANG: C++
*/
#include<cstdio>
#include<cstring>
#include<climits>
typedef long long INT64;
const INT64 MAXN = 500;
struct edge{
    int x,y,cap;
    edge *next,*target;
    edge(){}
    edge(int x,int y,int c,edge *n):x(x),y(y),cap(c),next(n),target(0){}
    void * operator new (size_t,void *ptr){return ptr;}
}*EDGE[MAXN];
INT64 MAXTOTAL;
long N,M,x,y,cap,Source,Sink,Queue[MAXN],Dist[MAXN];
edge *path[MAXN],*Stack[MAXN];
bool RefreshDistLabel(){
    int head=0,tail=0,now;
    memset(Dist,-1,sizeof(Dist));
    Dist[Source]=0;
    Queue[++tail]=Source;
    while(head<tail){
        now=Queue[++head];
        for(edge *e=EDGE[now];e;e=e->next){
            if(e->cap==0) continue;
            if(Dist[e->y]==-1){
                Dist[e->y]=Dist[e->x]+1;
                Queue[++tail]=e->y;
                if(e->y==Sink) return 1;
            }
        }
    }
    return 0;
}
void FindMaxFlow(){
    int Lpath=1,top=Source,record,delta;
    memcpy(Stack,EDGE,sizeof(EDGE));
    while(top>0){
        if(top==Sink){
            delta=INT_MAX;
            for(int i=1;i<Lpath;i++)
                if(delta>path[i]->cap){
                    delta=path[i]->cap;
                    record=i;
                }
            for(int i=1;i<Lpath;i++){
                path[i]->cap-=delta;
                path[i]->target->cap+=delta;
            }
            Lpath=record;
            top=path[Lpath]->x;
            MAXTOTAL+=delta;
        }
        edge *temE;
        for(temE=Stack[top];temE;temE=temE->next){
            if(temE->cap==0) continue;
            if(Dist[top]+1==Dist[temE->y]) break;
        }
        Stack[top]=temE;
        if(temE){
            path[Lpath++]=temE;
            top=temE->y;
        }
        else{
            Dist[top]=-1;
            if(Lpath==1) return;
            top=path[--Lpath]->x;
        }
    }
}
int main(){
    freopen("stall4.in","r",stdin);
    freopen("stall4.out","w",stdout);
    scanf("%d%d",&N,&M);
    Source=MAXN-4;
    Sink=MAXN-5;
    for(int i=1;i<=N;i++){ //建立二分图
        scanf("%d",&x);
        for(int j=1;j<=x;j++){
        edge *tempedge=new edge[2];
        scanf("%d",&y);
        y+=N; //important
        EDGE[i]=new((void *)tempedge++) edge(i,y,1,EDGE[i]);
        EDGE[y]=new((void *)tempedge) edge(y,i,0,EDGE[y]);
        EDGE[i]->target=EDGE[y];
        EDGE[y]->target=EDGE[i];
    }}
    for(int i=1;i<=N;i++){ //连接超级源
        edge *tempedge=new edge[2];
        EDGE[Source]=new((void *)tempedge++) edge(Source,i,1,EDGE[Source]);
        EDGE[i]=new((void *)tempedge) edge(i,Source,0,EDGE[i]);
        EDGE[Source]->target=EDGE[i];
        EDGE[i]->target=EDGE[Source];
    }
    for(int i=1+N;i<=M+N;i++){ //连接超级汇
        edge *tempedge=new edge[2];
        EDGE[i]=new((void *)tempedge++) edge(i,Sink,1,EDGE[i]);
        EDGE[Sink]=new((void *)tempedge) edge(Sink,i,0,EDGE[Sink]);
        EDGE[i]->target=EDGE[Sink];
        EDGE[Sink]->target=EDGE[i];
    }
    while(RefreshDistLabel()) FindMaxFlow();
    printf("%lld\n",MAXTOTAL);
    return 0;
}
