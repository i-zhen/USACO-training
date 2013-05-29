/*
ID: silentf1
PROG: fence4
LANG: C++
*/
#include<fstream>
#include<cmath>
using namespace std;
ofstream fout ("fence4.out",ios::out);
ifstream fin ("fence4.in",ios::in);
const double JD = 0.005;
struct Point{
    double x,y;
}point[201],see;
struct Line{
    Point start,end;
}line[201];
long n,len=0;
bool cansee[201],reg[201];
inline double crossproduct(Point start,Point U,Point V){//计算叉积
    double Ux=U.x-start.x,Uy=U.y-start.y,Vx=V.x-start.x,Vy=V.y-start.y;
    return (Ux*Vy-Uy*Vx);
}
inline int cancross(Line A,Line B){
    double A1=crossproduct(A.start,A.end,B.start),A2=crossproduct(A.start,A.end,B.end),
        B1=crossproduct(B.start,B.end,A.start),B2=crossproduct(B.start,B.end,A.end);
    if(A1==0 || A2==0) return -1;//被点挡住,A为中位线时,以A为轴,有0就表明被点挡住了.
    if(A1*A2<0 && B2*B1<0) return 1;//严格相交
    return 0;
}
inline bool check(const Line &mid){
    for(int i=1;i<=n;i++) if(!reg[i])
        if(cancross(mid,line[i])!=0) return false;
    return true;
}
inline bool watch(Point start,Point end){
    if(sqrt(((start.x-end.x)*(start.x-end.x))+((start.y-end.y)*(start.y-end.y)))<JD) return false;
    Line mid;//中位线
    bool temp=false;
    mid.end.x=(start.x+end.x)/2;
    mid.end.y=(end.y+start.y)/2;
    mid.start.x=see.x;
    mid.start.y=see.y;
    if(check(mid)) return true;
    else{
        temp=watch(start,mid.end);
        if(!temp) temp=watch(mid.end,end);
    }
    return temp;
}
int main()
{
    fin>>n>>see.x>>see.y;
    fin>>point[1].x>>point[1].y;
    for(int i=1;i<=200;i++) cansee[i]=false;
    for(int i=2;i<=n;i++){
        fin>>point[i].x>>point[i].y;
        line[i-1].start=point[i-1];
        line[i-1].end=point[i];
    }
    line[n].start=point[1];
    line[n].end=point[n];
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
            if(cancross(line[i],line[j])==1){fout<<"NOFENCE"<<endl;return 0;}
    for(int i=1;i<=n;i++){
        if(crossproduct(see,line[i].start,line[i].end)==0) continue;//cut
        reg[i]=true;//不要跟自己比较
        if(watch(line[i].start,line[i].end)){len++; cansee[i]=true;}
        reg[i]=false;
    }
    fout<<len<<endl;
    if(cansee[n]&&cansee[n-1]){ //如果最后两个都合法,交换
        Line temp=line[n];
        line[n]=line[n-1];
        line[n-1]=temp;
    }
    for(int i=1;i<=n;i++) if(cansee[i])
        fout<<line[i].start.x<<' '<<line[i].start.y<<' '<<line[i].end.x<<' '<<line[i].end.y<<endl;
    return 0;
}
