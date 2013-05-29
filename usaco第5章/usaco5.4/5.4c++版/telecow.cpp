/*
ID: silentf1
PROG: telecow
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <queue>
#define MAXN 605

using namespace std;

typedef long long INT64;
struct edge{ 
    int x,y,cap;
    edge *next,*target; 
    edge(){} 
    edge(int x,int y,int c,edge *n):x(x),y(y),cap(c),next(n),target(0){} 
    void * operator new (size_t,void *ptr){return ptr;} 
}*EDGE[MAXN], *tempedge=new edge[4000];
INT64 totalflow, MAXF;
long N, M, x, y, cap, Source, Sink, Queue[10 * MAXN], Dist[MAXN], temp, anse[MAXN][MAXN];
edge *path[MAXN], *Stack[MAXN];
queue<int> que;

bool RefreshDistLabel(){
	int head = 0, tail = 0, now;
	memset(Dist, -1, sizeof(Dist));
	Dist[Source] = 0;
	Queue[++tail] = Source;
	while(head < tail){
		now = Queue[++head];
		for(edge *e = EDGE[now]; e; e = e->next){
			if(e->cap==0) continue;
			if(Dist[e->y] == -1){
				Dist[e->y] = Dist[e->x] + 1;
				Queue[++tail] = e->y;
				if(e->y == Sink) return 1;
			}
		}
	}
	return 0;
}
void FindMaxFlow(){
	int Lpath = 1, top = Source, record, delta;
	memcpy(Stack, EDGE, sizeof(EDGE));
	while(top > 0){
		if(top == Sink){
			delta = INT_MAX;
			for(int i = 1; i < Lpath; i++)
				if(delta > path[i]->cap){
					delta = path[i]->cap;
					record = i;
				}
			for(int i = 1; i < Lpath; i++){
				path[i]->cap -= delta;
				path[i]->target->cap += delta;
			}
			Lpath = record;
			top = path[Lpath]->x;
			totalflow += delta;
		}
		edge *temE;
		for(temE = Stack[top]; temE; temE = temE->next){
			if(temE->cap == 0) continue;
			if(Dist[top] + 1 == Dist[temE->y]) break;
		}
		Stack[top] = temE;
		if(temE){
			path[Lpath++] = temE;
			top = temE->y;
		}else{
			Dist[top] = -1;
			if(Lpath == 1) return;
			top = path[--Lpath]->x;
		}
	}
}

inline void build(int x, int y){
	int x1 = x, y1 = y, x2 = x + N, y2 = y + N, fx = 1, fy = 1;
	//拆点,只拆一次
	if(x == Source) fx = INT_MAX;
	if(y == Source) fy = INT_MAX;
	if(!EDGE[x1]){
		if(x1 ==9) fx=0;
		EDGE[x1] = new((void *)tempedge++) edge(x1, x2, fx, EDGE[x1]); 
      		EDGE[x2] = new((void *)tempedge++) edge(x2, x1, 0, EDGE[x2]);
        	EDGE[x1]->target = EDGE[x2]; 
        	EDGE[x2]->target = EDGE[x1];
	}
	if(!EDGE[y1]){
		EDGE[y1] = new((void *)tempedge++) edge(y1, y2, fy, EDGE[y1]); 
        	EDGE[y2] = new((void *)tempedge++) edge(y2, y1, 0, EDGE[y2]);
        	EDGE[y1]->target = EDGE[y2]; 
        	EDGE[y2]->target = EDGE[y1];
	}
	//原图的边
	EDGE[x2] = new((void *)tempedge++) edge(x2, y1, INT_MAX, EDGE[x2]); 
        EDGE[y1] = new((void *)tempedge++) edge(y1, x2, 0, EDGE[y1]);
        EDGE[x2]->target = EDGE[y1]; 
        EDGE[y1]->target = EDGE[x2];
	EDGE[y2] = new((void *)tempedge++) edge(y2, x1, INT_MAX, EDGE[y2]); 
        EDGE[x1] = new((void *)tempedge++) edge(x1, y2, 0, EDGE[x1]);
        EDGE[y2]->target = EDGE[x1]; 
        EDGE[x1]->target = EDGE[x2];
}

int main(){
	freopen("telecow.in", "r", stdin);
	freopen("telecow.out", "w", stdout);
	scanf("%d%d%d%d", &N, &M, &Source, &Sink);
    	while(M--){
       		scanf("%d%d",&x,&y);
		build(x, y);
    	}
	for(int i = 1; i <= N * 2; i++) //复制现场
		for(edge *e = EDGE[i]; e; e = e->next)
			anse[e->x][e->y] = e->cap;
	while(RefreshDistLabel()) FindMaxFlow();
	printf("%lld\n", MAXF = totalflow);
	for(int k = 1; k <= N * 2; k++) //恢复现场
		for(edge *e = EDGE[k]; e; e = e->next)
			e->cap = anse[e->x][e->y];

	for(int i = 1; i <= N; i++){	//枚举每一个点
		if(i == Sink || i == Source) continue;
		for(edge *e = EDGE[i]; e; e = e->next){
			if(e->y - e->x == N){
				temp = e->cap;
				e->cap = 0, totalflow = 0;
				while(RefreshDistLabel()) FindMaxFlow();
				if(totalflow == MAXF - 1){
					anse[e->x][e->y] = 0;
					que.push(i);
					MAXF = totalflow;
					if(MAXF == 0 && que.size()){
						if(que.size()){
							printf("%d", que.front());
							que.pop();
						}
						while(que.size()){
							printf(" %d", que.front());
							que.pop();
						}
						printf("\n");
						return 0;
					}
				}
				for(int k = 1, tot = 0; k <= N * 2; k++) //恢复现场
					for(edge *e = EDGE[k]; e; e = e->next)
						e->cap = anse[e->x][e->y];
			}
		}
	}
	return 0;
}
