/*
ID: silentf1
PROG: fence6
LANG: C++
*/
#include<fstream>
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
ofstream fout ("fence6.out",ios::out);
ifstream fin ("fence6.in",ios::in);
const int BIG = 101,MAXvalue = 9999;
struct node{
    int linkedge[BIG][2],num[2],node[2],len;
    bool build[2];
}edge[BIG];
int n,m,pos[2],dis[2*BIG][2*BIG],value=MAXvalue,point,pot;
bool map[2*BIG];
inline int find(int n,int m){
    for(int k=0;k<=1;k++)
        for(int i=1;i<=edge[n].num[k];i++)
            if(edge[n].linkedge[i][k]==m) return k;
}
void dfs(int pos,int lev,int len){
    if(pos==pot && lev>3){ //必须有三个点才能形成环.
        dis[pot][pot]=MIN(len,dis[pot][pot]);
        return ;
    }
    for(int i=1;i<=point;i++)
    if(dis[pos][i] && !map[i] && pos!=i){ //必须邻接,未被访问
        map[i]=true;
        if(len+dis[pos][i]<dis[pot][pot]) dfs(i,lev+1,len+dis[pos][i]);//cut
        map[i]=false;
    }
}
int main()
{
    fin>>n;
    for(int i=1;i<=n;i++){
        fin>>m;
        edge[m].build[0]=edge[m].build[1]=false;
        fin>>edge[m].len>>edge[m].num[0]>>edge[m].num[1];
        for(int j=1;j<=edge[m].num[0];j++) fin>>edge[m].linkedge[j][0];
        for(int j=1;j<=edge[m].num[1];j++) fin>>edge[m].linkedge[j][1];
    }
    for(int i=1;i<=n;i++){ //图的重构
        pos[0]=pos[1]=0;
        for(int k=0;k<=1;k++){
            if(!edge[i].build[k]){
                pos[k]=++point;
                edge[i].node[k]=point;
                for(int j=1;j<=edge[i].num[k];j++){
                    int obj=edge[i].linkedge[j][k],temp=find(obj,i);
                    edge[obj].build[temp]=true;
                    edge[obj].node[temp]=point;
                }
            }
            else pos[k]=edge[i].node[k];
            edge[i].build[k]=true;
        }
        dis[pos[0]][pos[1]]=dis[pos[1]][pos[0]]=edge[i].len;
    }
    for(int i=1;i<=point;i++)
        for(int j=1;j<=point;j++)
            if(!dis[i][j]) dis[i][j]=MAXvalue;
    for(pot=1;pot<=point;pot++){
        for(int j=1;j<=point;j++) map[j]=false;
        dfs(pot,1,0);
        value=MIN(value,dis[pot][pot]);
    }
    fout<<value<<endl;
    return 0;
}
