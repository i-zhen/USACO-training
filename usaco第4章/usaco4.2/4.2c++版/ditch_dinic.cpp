/*
ID: silentf1
PROG: ditch
LANG: C++
*/
#include<cstdio>
#include<cstring>
#include<climits>
typedef long long INT64;
const INT64 MAXN = 205; //最大节点数目
struct edge{  //使用边表存储
    int x,y,cap; //边的两边分别是x,y;容量是cap;因为本方法为阻塞流法所以仅需容量;
    edge *next,*target; //以x为表头的邻接边和反向边;
    edge(){} //缺省构造函数
    edge(int x,int y,int c,edge *n):x(x),y(y),cap(c),next(n),target(0){} //自定义构造函数
    void * operator new (size_t,void *ptr){return ptr;} //重载new运算符
}*EDGE[MAXN];
INT64 MAXTOTAL;  //记录最大流
long N,M,x,y,cap,Source,Sink,Queue[10*MAXN],Dist[MAXN]; //Dist为分层图层次
edge *path[MAXN],*Stack[MAXN]; //分别记录增广路和回溯用栈
bool RefreshDistLabel(){ //分层图构造函数，同时寻找增广路
    int head=0,tail=0,now;
    memset(Dist,-1,sizeof(Dist));
    Dist[Source]=0; //源点层次距离
    Queue[++tail]=Source;
    while(head<tail){
        now=Queue[++head];
        for(edge *e=EDGE[now];e;e=e->next){ //查看所有邻接
            if(e->cap==0) continue; //已经无边则跳过
            if(Dist[e->y]==-1){ //未扩展
                Dist[e->y]=Dist[e->x]+1; //从上个层次扩展.(e->x换成now也可以)
                Queue[++tail]=e->y;
                if(e->y==Sink) return 1; //找到合法层次则退出
            }
        }
    }
    return 0;
}
void FindMaxFlow(){
    int Lpath=1,top=Source,record,delta;
    memcpy(Stack,EDGE,sizeof(EDGE));
    while(top>0){
        if(top==Sink){ //找到增广路
            delta=INT_MAX;
            for(int i=1;i<Lpath;i++) //找到可增广最小条件
                if(delta>path[i]->cap){
                    delta=path[i]->cap;
                    record=i; //记录增广后的继承出发点
                }
            for(int i=1;i<Lpath;i++){ //增广
                path[i]->cap-=delta;
                path[i]->target->cap+=delta;
            }
            Lpath=record; //回溯
            top=path[Lpath]->x; //回溯
            MAXTOTAL+=delta; //更新最大流
        }
        edge *temE;
        for(temE=Stack[top];temE;temE=temE->next){ //查看所有邻接
            if(temE->cap==0) continue; //不合法
            if(Dist[top]+1==Dist[temE->y]) break; //合法
        }
        Stack[top]=temE; //记录当前的DFS位置
        if(temE){ //找到可增广点
            path[Lpath++]=temE; //入队
            top=temE->y; //深度优先增广
        }
        else{ //已经无法增广
            Dist[top]=-1; //删掉当前边
            if(Lpath==1) return; //如果无法增广则退出.(top也可以)
            top=path[--Lpath]->x; //回溯
        }
    }
}
int main(){
    freopen("ditch.in","r",stdin);
    freopen("ditch.out","w",stdout);
    scanf("%d%d",&M,&N);
    Source=1;
    Sink=N;
    edge *tempedge=new edge[2*M]; //临时交换边表
    while(M--){
        scanf("%d%d%d",&x,&y,&cap);
        EDGE[x]=new((void *)tempedge++) edge(x,y,cap,EDGE[x]); //利用临时边表更新邻接边
        EDGE[y]=new((void *)tempedge++) edge(y,x,0,EDGE[y]);
        EDGE[x]->target=EDGE[y]; //反向边表
        EDGE[y]->target=EDGE[x];
    }
    while(RefreshDistLabel()) FindMaxFlow();
    printf("%lld\n",MAXTOTAL);
    return 0;
}
