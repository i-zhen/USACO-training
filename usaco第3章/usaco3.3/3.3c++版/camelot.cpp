/*
ID: silentf1
PROG: camelot
LANG: C++
*/
#include<fstream>
#include<cmath>
#define MIN(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
using namespace std;
ofstream fout ("camelot.out",ios::out);
ifstream fin ("camelot.in",ios::in);
const int MAX = 20000;
struct node{
    int x,y;
}chess[1000],king;
struct Dis{
    int val,x,y,hx,hy;
}kdis[10000];
long Dis[31][31],r,c,cpath[31][31][31][31],kpath[31][31],lenc,dl[20001][3],kDlen,Len=MAX,add;
inline void queuein(int tail,int x,int y,int path){
    if(tail%MAX==0) {dl[MAX][0]=path;dl[MAX][1]=x;dl[MAX][2]=y;}
    else {dl[tail%MAX][0]=path;dl[tail%MAX][1]=x;dl[tail%MAX][2]=y;}
}
inline long queueout(int head){
    if(head%MAX==0) return MAX;
    else return head%MAX;
}
inline void bfs(){ //骑士的最短路
    int cx,cy,head,tail,pos,x,y,len,cpos[8][2]={{1,2},{-1,2},{-1,-2},{1,-2},{2,1},{-2,-1},{-2,1},{2,-1}};
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++){
        head=0;
        tail=1;
        dl[tail][0]=0;
        dl[tail][1]=cx=i;
        dl[tail][2]=cy=j;
        cpath[cx][cy][cx][cy]=0;
        while(head<tail){
            pos=queueout(++head);
            x=dl[pos][1];
            y=dl[pos][2];
            len=dl[pos][0];
            for(int i=0;i<8;i++)
                if(x+cpos[i][0]>0 && x+cpos[i][0]<=r && y+cpos[i][1]>0 && y+cpos[i][1]<=c)
                if (len+1<cpath[cx][cy][x+cpos[i][0]][y+cpos[i][1]] || cpath[cx][cy][x+cpos[i][0]][y+cpos[i][1]]==-1){
                    queuein(++tail,x+cpos[i][0],y+cpos[i][1],len+1);
                    cpath[cx][cy][x+cpos[i][0]][y+cpos[i][1]]=len+1;
                }
        }
    }
}
int main()
{
    fin>>r>>c;
	char Cin;
    fin>>Cin>>king.x; king.y=Cin-64;
    king.x=r-king.x+1;
    while(!fin.eof()){
        ++lenc;
        fin>>Cin>>chess[lenc].x;
        chess[lenc].y=Cin-64;
        chess[lenc].x=r-chess[lenc].x+1;
    }
	--lenc;
	if(lenc<=0) {fout<<0<<endl;return 0;}
    for(int i=1;i<=30;i++)
        for(int j=1;j<=26;j++)
            for(int k=1;k<=30;k++)
                for(int p=1;p<=26;p++)
                    cpath[i][j][k][p]=-1;
    bfs();
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            kpath[i][j]=Max(abs(king.x-i),abs(king.y-j));//找到国王的最短路程
    for(int i=1;i<=r;i++) //预先处理所有骑士到达某一点的最短路
        for(int j=1;j<=c;j++)
            for(int k=1;k<=lenc;k++)
                if(cpath[chess[k].x][chess[k].y][i][j]==-1) {Dis[i][j]=-1;break;}
                    else Dis[i][j]+=cpath[chess[k].x][chess[k].y][i][j];
    for(int i=1;i<=lenc;i++){ //可能有相同的"背"国王的的最小值
        add=MAX;
        for(int p=1;p<=r;p++) //先扫描最小值,必须合法
            for(int q=1;q<=c;q++)
                if(cpath[chess[i].x][chess[i].y][p][q]!=-1) add=MIN(add,cpath[chess[i].x][chess[i].y][p][q]+kpath[p][q]);
        if(add!=MAX)
        for(int p=1;p<=r;p++) //将相同的最小值加入处理队列
            for(int q=1;q<=c;q++)
            if(cpath[chess[i].x][chess[i].y][p][q]+kpath[p][q]==add){
                ++kDlen;
                kdis[kDlen].val=add;
                kdis[kDlen].x=chess[i].x;kdis[kDlen].y=chess[i].y;
                kdis[kDlen].hx=p;kdis[kDlen].hy=q;
            }
    }
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            for(int k=1;k<=kDlen;k++)
                if(Dis[i][j]!=-1 && cpath[kdis[k].x][kdis[k].y][i][j]!=-1 && cpath[kdis[k].hx][kdis[k].hy][i][j]!=-1)
                    Len=MIN(Len,Dis[i][j]+kdis[k].val+cpath[kdis[k].hx][kdis[k].hy][i][j]-cpath[kdis[k].x][kdis[k].y][i][j]);
    fout<<Len<<endl;
    return 0;
}
