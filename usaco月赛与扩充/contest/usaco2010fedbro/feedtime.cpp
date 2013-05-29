/*
PROG: feedtime
LANG: C++
ID: silentf1
*/
#include<fstream>
#define MAX(a,b) ((a)>(b)?(a):(b))
using namespace std;
ifstream fin("feedtime.in");
ofstream fout("feedtime.out");
const long MAx=751;
char map[MAx][MAx];
long w,h,Max=0,pos[][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}},val=0;
long dfs(int x,int y){
    if(x<=0 || x>w || y<=0 || y>h) return 0;
    if(map[x][y]=='*') return 0;
    long temp=1;
    map[x][y]='*';
    for(int i=0;i<8;i++)
        temp+=dfs(x+pos[i][1],y+pos[i][0]);
    return temp;
}
inline void init(){
	 fin>>h>>w;
    for(int i=1;i<=w;i++)
        for(int j=1;j<=h;j++)
            fin>>map[i][j];
}
int main(){
    init();
    for(int i=1;i<=w;i++)
        for(int j=1;j<=h;j++)
            if(map[i][j]!='*'){
				val=dfs(i,j);
                Max=MAX(Max,val);
            }
    fout<<Max<<endl;
    return 0;
}
