/*
ID: silentf1
PROG: butter
LANG: C++
*/
#include <fstream>
using namespace std;
ofstream fout ("butter.out",ios::out);
ifstream fin ("butter.in",ios::in);
const long Max = 10000,MAX = 999999;
int n,p,c,cow[501],edge[801][801],Node[801][801],dis[801],dl[10001];
bool inque[801];
inline void queuein(int pos,int node){
    if(pos%Max==0) dl[Max]=node;
    else dl[pos%Max]=node;
}
inline long queueout(int pos){
    if(pos%Max==0) return dl[Max];
    else return dl[pos%Max];
}
inline void spfa(){
    int head,tail,qout,Min=MAX,add;
    for(int i=1;i<=p;i++){
        head=0;tail=1;
        dl[tail]=i;
        for(int k=1;k<=p;k++){
            inque[k]=false;
            dis[k]=MAX;//保证所有节点都要入队至少一次
        }
        dis[i]=0;
        inque[i]=true;
        while(head<tail){ //SPFA
            qout=queueout(++head); //出队
            for(int k=1;k<=Node[qout][0];k++){ //所有直接相连顶点
                int temp=Node[qout][k];
                if(dis[qout]+edge[qout][temp]<dis[temp]){ //Relax
                    dis[temp]=dis[qout]+edge[qout][temp];
                    if(!inque[temp]){ //更新后需要入队
                        queuein(++tail,temp);
                        inque[temp]=true; //已经入队
                    }
                }
            }
            inque[qout]=false;//已经出队
        }
		add=0;
        for(int j=1;j<=n;j++) add+=dis[cow[j]];
        Min=(Min<add?Min:add);
    }
    fout<<Min<<endl;
}
int main(){
    fin>>n>>p>>c;
    for(int i=1;i<=p;i++)
        for(int j=1;j<=p;j++)
            if(i==j) edge[i][j]=0;
            else edge[i][j]=MAX;
    for(int i=1;i<=n;i++) fin>>cow[i];
    for(int i=1;i<=c;i++){
        int x,y,Dis;
        fin>>x>>y>>Dis;
        edge[x][y]=edge[y][x]=Dis;
        Node[x][++Node[x][0]]=y;
        Node[y][++Node[y][0]]=x;
    }
    spfa();
    return 0;
}
