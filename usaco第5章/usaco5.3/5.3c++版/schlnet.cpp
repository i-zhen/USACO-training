/*
ID: silentf1
PROG: schlnet
LANG: C++
*/

#include <iostream>
#include <stack>
#include <string>
#include <cstdio>
#include <cstring>
#include <climits>

#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)

using namespace std;

const long MAXN = 205; //最大节点数目
struct edge{  //使用边表存储
    int x,y; //边的两边分别是x,y
    edge *next; //以x为表头的邻接边
    edge(){} //缺省构造函数
    edge(int x,int y,edge *n):x(x),y(y),next(n){} //自定义构造函数
    void * operator new (size_t,void *ptr){return ptr;} //重载new运算符
}*EDGE[MAXN * MAXN], *tempedge = new edge[MAXN * MAXN];
int n, m, DFN[MAXN], LOW[MAXN], instack[MAXN], SCC[MAXN], Dindex, count, dgr[MAXN][2];
stack<int> Stack;

void tarjan(int n){
	DFN[n] = LOW[n] = ++Dindex;
	instack[n] = true;
	Stack.push(n);
	for(edge *e = EDGE[n]; e; e = e->next){
		int v = e->y;
		if(!DFN[v]){
			tarjan(v);
			LOW[n] = MIN(LOW[n], LOW[v]);
		}else if(instack[v])
			LOW[n] = MIN(LOW[n], DFN[v]);
	}
	if(DFN[n] == LOW[n]){
		count++;
		int v;
		do{
			instack[v = Stack.top()] = false;
			Stack.pop();
			SCC[v] = count;
		}while(v != n);

	}
}

int main(){
	freopen("schlnet.in", "r", stdin);
	freopen("schlnet.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
		while(cin >> m && m)
			EDGE[i] = new((void *)tempedge++) edge(i, m, EDGE[i]);

	for(int i = 1; i <= n; i++) // tarjan's SCC
		if(!DFN[i])
			tarjan(i);
	for(int j = 1; j <= n; j++)
		for(edge *e = EDGE[j]; e; e = e->next)
			if(SCC[e->y] != SCC[j])
				dgr[SCC[e->y]][0]++, dgr[SCC[j]][1]++;
	for(int i = 1; count != 1 && i <= count; i++) // 只有一个强连通分量就不做累加
		(!dgr[i][0]? dgr[0][0]++ : 0), (!dgr[i][1]? dgr[0][1]++ : 0);
	cout << (dgr[0][0] > 1 ? dgr[0][0] : 1) << endl << MAX(dgr[0][0], dgr[0][1]) << endl;
	return 0;
}
