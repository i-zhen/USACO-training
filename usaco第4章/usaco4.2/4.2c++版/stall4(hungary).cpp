/*
ID: silentf1
PROG: stall4
LANG: C++
*/
#include <fstream>
#include <cstring>
#define MAXN 1000
#define MAXE 5000
using namespace std;
ofstream fout ("stall4.out",ios::out);
ifstream fin ("stall4.in",ios::in);
struct EDGE{
    int x,y,next;
}edge[MAXE];
int Link[MAXN],head[MAXN],n,m,x,y,tot;
bool use[MAXN];
bool hungary(int node){
    int temp=head[node];
    while(temp){
        if(!use[edge[temp].y]){ //如果是未检查点
            use[edge[temp].y]=true; //已经检查
            if(!Link[edge[temp].y] || hungary(Link[edge[temp].y])){
                //如果是单纯未匹配边或者找到增广路则更新最大匹配
                Link[edge[temp].y]=node; //设置当前匹配边
                return true;
            }
        }
        temp=edge[temp].next;
    }
    return false;
}
int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++){
        fin>>x; //边数
        for(int j=1;j<=x;j++){
            fin>>edge[++tot].y;
            edge[tot].x=i; edge[tot].y+=n;
            edge[tot].next=head[i]; head[i]=tot;
        }
    }
    tot=0;
    for(int i=1;i<=n;i++){//hungary
        memset(use,0,sizeof(use));
        if(hungary(i)) tot++;
    }
    fout<<tot<<endl;
	return 0;
}
