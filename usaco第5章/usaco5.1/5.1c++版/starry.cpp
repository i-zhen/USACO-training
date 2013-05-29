/*
ID: silentf1
PROG: starry
LANG: C++
*/
#include<fstream>
#include<cstring>
#include<string>
#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)
#define MAXN 105
#define MAXL 505
using namespace std;
ofstream fout ("starry.out",ios::out);
ifstream fin ("starry.in",ios::in);
typedef struct{
    char ch;
    long hash[9],chang,kuan;
}Pic;
int map[MAXN][MAXN],Use[MAXN][MAXN],use[MAXN][MAXN],w,h,m,n,Mm,Mn,xMm,xMn,Count,tot,lev;
int pos[][2]={{0,0},{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}};
char xmap[MAXN][MAXN],MAP[MAXN][MAXN];
Pic starry[MAXL];
bool check(int now,int x,int y,int k){
    int X=pos[now][0]+x,Y=pos[now][1]+y;
    if(map[X][Y]==k) return 1;
    else return 0;
}
void floodfill(int x,int y){
	m=MIN(m,x);
	n=MIN(n,y);
	Mm=MAX(Mm,x);
	Mn=MAX(Mn,y);
    Use[x][y]=1;
    map[x][y]=2;
    for(int i=1;i<=8;i++)
        if(check(i,x,y,1))
            floodfill(x+pos[i][0],y+pos[i][1]);
}
void Paint(int x,int y,int now){
    xmap[x][y]=starry[now].ch;
	map[x][y]=0;
    for(int i=1;i<=8;i++)
        if(check(i,x,y,2))
            Paint(x+pos[i][0],y+pos[i][1],now);
}
void cutpic(){
	memset(use,0,sizeof(use));
	for(int i=m;i<=Mm;i++)
		for(int j=n;j<=Mn;j++)
			use[i-m+1][j-n+1]=Use[i][j];
}
int work[MAXN][MAXN];
void init(){memset(work,0,sizeof(work));lev=0;}
long BKDRHash(const int map[MAXN][MAXN]){
    int Hash=0,seed=131313;
    for(int i=1;i<=xMn;i++)
        for(int j=1;j<=xMm;j++)
            Hash=Hash*seed+work[j][i];
    return (Hash & 0x7FFFFFFF);
}
void make(Pic &New){
    //1
	Mm=Mm-m+1;
	Mn=Mn-n+1;
    init();
    for(int i=1;i<=Mm;i++)
        for(int j=1;j<=Mn;j++)
            work[i][j]=use[i][j];
    for(int i=1;i<=Mm;i++)
        for(int j=1;j<=Mn;j++)
            work[i][j]=(work[i][j]?++lev:0);
    xMm=Mm;
    xMn=Mn;
    New.hash[1]=BKDRHash(work);
    New.chang=Mm;
    New.kuan=Mn;
    //2
    init();
    for(int i=Mm;i>=1;i--)
        for(int j=Mn;j>=1;j--)
            work[Mn-j+1][Mm-i+1]=use[i][Mn-j+1];
    for(int i=1;i<=Mn;i++)
        for(int j=1;j<=Mm;j++)
            work[i][j]=(work[i][j]?++lev:0);
    xMm=Mn;
    xMn=Mm;
    New.hash[2]=BKDRHash(work);
    //3
    init();
    for(int i=Mm;i>=1;i--)
        for(int j=Mn;j>=1;j--)
            work[Mm-i+1][Mn-j+1]=use[i][j];
    for(int i=1;i<=Mm;i++)
        for(int j=1;j<=Mn;j++)
            work[i][j]=(work[i][j]?++lev:0);
    xMm=Mm;
    xMn=Mn;
    New.hash[3]=BKDRHash(work);
    //4
    init();
    for(int i=Mm;i>=1;i--)
        for(int j=1;j<=Mn;j++)
            work[j][Mm-i+1]=use[i][Mn-j+1];
    for(int i=1;i<=Mn;i++)
        for(int j=1;j<=Mm;j++)
            work[i][j]=(work[i][j]?++lev:0);
    xMm=Mn;
    xMn=Mm;
    New.hash[4]=BKDRHash(work);
    //5
    init();
    for(int i=1;i<=Mm;i++)
        for(int j=1;j<=Mn;j++)
            work[i][j]=use[i][Mn-j+1];
    for(int i=1;i<=Mm;i++)
        for(int j=1;j<=Mn;j++)
            work[i][j]=(work[i][j]?++lev:0);
    xMm=Mm;
    xMn=Mn;
    New.hash[5]=BKDRHash(work);
    //6
    init();
    for(int i=1;i<=Mm;i++)
        for(int j=1;j<=Mn;j++)
            work[j][i]=use[i][j];
    for(int i=1;i<=Mn;i++)
        for(int j=1;j<=Mm;j++)
            work[i][j]=(work[i][j]?++lev:0);
    xMm=Mn;
    xMn=Mm;
    New.hash[6]=BKDRHash(work);
    //7
    init();
    for(int i=1;i<=Mm;i++)
        for(int j=1;j<=Mn;j++)
            work[i][j]=use[Mm-i+1][j];
    for(int i=1;i<=Mm;i++)
        for(int j=1;j<=Mn;j++)
            work[i][j]=(work[i][j]?++lev:0);
    xMm=Mm;
    xMn=Mn;
    New.hash[7]=BKDRHash(work);
    //8
    init();
    for(int i=Mm;i>=1;i--)
        for(int j=Mn;j>=1;j--)
            work[Mm-i+1][j]=use[i][j];
    for(int i=1;i<=Mn;i++)
        for(int j=1;j<=Mm;j++)
            work[i][j]=(work[i][j]?++lev:0);
    xMm=Mn;
    xMn=Mm;
    New.hash[8]=BKDRHash(work);
}
int DeleteInsert(const Pic &New){
    for(int i=1;i<=tot;i++)
        for(int j=1;j<=8;j++)
            for(int k=j;k<=8;k++)
                if(starry[i].hash[j]==New.hash[k] && ((starry[i].chang==New.chang &&starry[i].kuan==New.kuan)
                    || (starry[i].chang==New.kuan &&starry[i].kuan==New.chang)))
                    return i;
    starry[++tot]=New;
    Count++;
    starry[tot].ch=(char)('a'+Count-1);
    return tot;
}
int main()
{
    fin>>w>>h;
    for(int i=1;i<=h;i++)for(int j=1;j<=w;j++)fin>>MAP[i][j];
    for(int i=1;i<=h;i++)for(int j=1;j<=w;j++){map[i][j]=MAP[i][j]-'0';}
	for(int i=1;i<=h;i++)for(int j=1;j<=w;j++)xmap[i][j]='0';
    for(int i=1;i<=h;i++)
        for(int j=1;j<=w;j++)
            if(map[i][j]==1){
                memset(Use,0,sizeof(Use));
				Mm=Mn=-1;
                m=i;n=j;
                floodfill(i,j);
				cutpic();
                Pic New;
                make(New);
                Paint(i,j,DeleteInsert(New));
            }
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++)
            fout<<xmap[i][j];
        fout<<endl;
    }
	return 0;
}
