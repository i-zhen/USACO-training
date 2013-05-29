/*
ID: silentf1
PROG: fence
LANG: C++
*/
#include <fstream>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
ofstream fout ("fence.out",ios::out);
ifstream fin ("fence.in",ios::in);
int n,x,y,point[2001],node[501],lenp=0,Max,init=1,edge[501][501];
inline int Del(int pos){ //选择最小的点
    int Min=9999;
    for(int i=1;i<=Max;i++) //察看连通性
        if(edge[i][pos]) Min=MIN(Min,i);
    return Min;
}
void eulerian(int pos){
    int delnode;
    if(node[pos]==0) point[++lenp]=pos; //已经查找完毕加入队列
    else{
        while(node[pos]!=0){ //delete
            delnode=Del(pos);
            node[delnode]--;
            node[pos]--;
            edge[pos][delnode]=--edge[delnode][pos];
            eulerian(delnode);
        }
        point[++lenp]=pos;//本身需要入队
    }
}
int main()
{
    fin>>n;
    for(int i=1;i<=500;i++)
        for(int j=1;j<=500;j++)
            edge[i][j]=0;
    for(int i=1;i<=n;i++){
        fin>>x>>y;
        Max=MAX(MAX(Max,x),y);
        edge[x][y]=++edge[y][x];
        ++node[x];
        ++node[y];
    }
    for(int i=1;i<=Max;i++) if(node[i]&1) {init=i;break;}//找起始点
    eulerian(init);
    for(int i=lenp;i>=1;i--) fout<<point[i]<<endl;//倒序输出
    return 0;
}
