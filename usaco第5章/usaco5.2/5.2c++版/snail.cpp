/*
ID: silentf1
PROG: snail
LANG: C++
*/
#include<fstream>
#include<cstring>
#include<string>
#define BIG 120 + 5
#define MAX(a,b) (a>b?a:b)
using namespace std;
ofstream fout ("snail.out",ios::out);
ifstream fin ("snail.in",ios::in);
int map[BIG][BIG],road[BIG][BIG],n,b,next[5][2]={{0,0},{0,1},{0,-1},{1,0},{-1,0}};
long Step;
string load;
inline bool isright(const int &x,const int &y,const int &k){
    if(road[x+next[k][0]][y+next[k][1]]) return 0;
    return 1;
}
inline bool okay(const int &x,const int &y,const int &k){
    if(x+next[k][0]>n || x+next[k][0]<1) return 0;
    if(y+next[k][1]>n || y+next[k][1]<1) return 0;
    return 1;
}
void dfs_map(int x,int y,int k,long step){
    road[x][y]=1;
    if(!isright(x,y,k)){
       Step=MAX(Step,step);
       road[x][y]=0;
       return;
    }
    if(map[x+next[k][0]][y+next[k][1]]!=1 && okay(x,y,k))
        dfs_map(x+next[k][0],y+next[k][1],k,step+1);
    else
        switch(k){
            case(1):
                if(map[x+next[3][0]][y+next[3][1]]!=1 && okay(x,y,3) && isright(x,y,3))
                    dfs_map(x+next[3][0],y+next[3][1],3,step+1);
                if(map[x+next[4][0]][y+next[4][1]]!=1 && okay(x,y,4) && isright(x,y,4))
                    dfs_map(x+next[4][0],y+next[4][1],4,step+1);
                break;
            case(2):
                if(map[x+next[3][0]][y+next[3][1]]!=1 && okay(x,y,3) && isright(x,y,3))
                    dfs_map(x+next[3][0],y+next[3][1],3,step+1);
                if(map[x+next[4][0]][y+next[4][1]]!=1 && okay(x,y,4) && isright(x,y,4))
                    dfs_map(x+next[4][0],y+next[4][1],4,step+1);
                break;
            case(3):
                if(map[x+next[1][0]][y+next[1][1]]!=1 && okay(x,y,1) && isright(x,y,1))
                    dfs_map(x+next[1][0],y+next[1][1],1,step+1);
                if(map[x+next[2][0]][y+next[2][1]]!=1 && okay(x,y,2) && isright(x,y,2))
                    dfs_map(x+next[2][0],y+next[2][1],2,step+1);
                break;
            case(4):
                if(map[x+next[1][0]][y+next[1][1]]!=1 && okay(x,y,1) && isright(x,y,1))
                    dfs_map(x+next[1][0],y+next[1][1],1,step+1);
                if(map[x+next[2][0]][y+next[2][1]]!=1 && okay(x,y,2) && isright(x,y,2))
                    dfs_map(x+next[2][0],y+next[2][1],2,step+1);
                break;
        }
    Step=MAX(Step,step);
    road[x][y]=0;
}
int main()
{
    memset(map,0,sizeof(map));
    fin>>n>>b;
    for(int i=1;i<=b;i++){
        fin>>load;
        if(load[2]=='\0') map[load[0]-'A'+1][load[1]-'0']=1;
        else
            if(load[3]=='\0') map[load[0]-'A'+1][(load[1]-'0')*10+load[2]-'0']=1;
                else map[load[0]-'A'+1][(load[1]-'0')*100+(load[2]-'0')*10+load[3]-'0']=1;
    }
    dfs_map(1,1,1,1);
    memset(road,0,sizeof(road));
    dfs_map(1,1,3,1);
    fout<<Step<<endl;
	return 0;
}
