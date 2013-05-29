/*
ID: silentf1
PROG: milk6
LANG: C++
*/
#include<cstdio>
#include<cstring>
#include<climits>
#define MAXE 50
#define MAXN 100
struct edge{
    int x,y,cap,flow;
    edge *next,*target;
    edge(){}
    edge(int x,int y,int c,edge *n):x(x),y(y),cap(c),next(n),target(0){flow=cap;}
    void * operator new(size_t,void *ptr){return ptr;}
}*EDGE[MAXE],*Path[MAXE],*Stack[MAXE],*Lb[MAXN*11];
long TotalFlow,N,M,Source,Sink,Dist[MAXE],Queue[MAXN]
    ,TOTedge,rec[MAXN*11];
bool Tedge[MAXN*11];
inline bool RefreshDistLabel(){
    long head=0,tail=0,now=0;
    memset(Dist,-1,sizeof(Dist));
    Dist[Source]=0;
    Queue[++tail]=Source;
    while(head<tail){
        now=Queue[++head];
        for(edge *e=EDGE[now];e;e=e->next){
            if(e->cap==0) continue;
            if(Dist[e->y]==-1){
                Dist[e->y]=Dist[now]+1;
                Queue[++tail]=e->y;
                if(e->y==Sink) return 1;
            }
        }
    }
    return 0;
}
inline long FindMaxFlow(){
    long Lpath=1,top=Source,delta,record,Totalflow=0;
    memcpy(Stack,EDGE,sizeof(EDGE));
    while(top>0){
        if(top==Sink){
            delta=INT_MAX;
            for(int i=1;i<Lpath;i++)
                if(delta>Path[i]->cap){
                    delta=Path[i]->cap;
                    record=i;
                }
            for(int i=1;i<Lpath;i++){
                Path[i]->cap-=delta;
                Path[i]->target->cap+=delta;
            }
            Lpath=record;
            top=Path[Lpath]->x;
            Totalflow+=delta;
        }
        else{
            edge *temE;
            for(temE=Stack[top];temE;temE=temE->next){
                if(temE->cap==0) continue;
                if(Dist[top]+1==Dist[temE->y]) break;
            }
            Stack[top]=temE;
            if(temE){
                Path[Lpath++]=temE;
                top=temE->y;
            }else{
                Dist[top]=-1;
                if(Lpath==1) return Totalflow;
                top=Path[--Lpath]->x;
            }
        }
    }
}
void init(){
    scanf("%ld%ld",&N,&M);
    Source=1;
    Sink=N;
    edge *tempEDGE=new edge[2*M];
    long x,y,cap;
    for(int i=1;i<=M;i++){
        scanf("%ld%ld%ld",&x,&y,&cap);
        EDGE[x]=new((void *)tempEDGE++) edge(x,y,cap,EDGE[x]);
        Lb[i]=EDGE[x]; //按照顺序映射边集
        rec[i]=cap;
        EDGE[y]=new((void *)tempEDGE++) edge(y,x,0,EDGE[y]);
        EDGE[x]->target=EDGE[y];
        EDGE[y]->target=EDGE[x];
    }
    while(RefreshDistLabel()) TotalFlow+=FindMaxFlow();
}
int main()
{
    freopen("milk6.in","r",stdin);
    freopen("milk6.out","w",stdout);
    init();
    long save,Flow=0,nowflow=TotalFlow;
    if(TotalFlow){
        for(int i=1;i<=M;i++){ //查找是否存在割边
            if(Lb[i]->cap>TotalFlow) continue;
            for(int j=1;j<=M;j++) Lb[j]->cap=rec[j];
            save=Lb[i]->cap;
            Lb[i]->cap=Flow=0;
            while(RefreshDistLabel()) Flow+=FindMaxFlow();
            if(Flow==0) {TOTedge=1;Tedge[i]=1;break;}
        }
        if(!TOTedge)
            for(int i=1;i<=M;i++){ //查找最小集合
                for(int j=1;j<=M;j++) if(!Tedge[j])Lb[j]->cap=rec[j];
                save=Lb[i]->cap;
                Lb[i]->cap=Flow=0;
                while(RefreshDistLabel()) Flow+=FindMaxFlow();
                if(save==nowflow-Flow){
                    nowflow-=save;
                    Tedge[i]=1;
                    TOTedge++;
                }
                else Lb[i]->cap=save;
            }
    }
    printf("%ld %ld\n",TotalFlow,TOTedge);
    for(int i=1;i<=M;i++) if(Tedge[i]) printf("%ld\n",i);
	return 0;
}
