/*
ID: silentf1
PROG: spin
LANG: C++
*/
#include <fstream>
using namespace std;
ofstream fout ("spin.out",ios::out);
ifstream fin ("spin.in",ios::in);
struct node{
    int sta,speed,que[6][2],tq;
}wheel[6];
long Time=0;
short kou[360];
inline bool pass(){
    long a;
    for(int i=0;i<=359;i++) kou[i]=0;
    for(int i=1;i<=5;i++){
        for(int j=1;j<=wheel[i].tq;j++){
            for(int k=0;k<=wheel[i].que[j][1];k++){//认真读题
                a=(wheel[i].sta+wheel[i].que[j][0]+k)%360;
                kou[a]++;
            }
        }
    }
    for(int i=0;i<=359;i++) if(kou[i]>=5) return true;
    return false;
}
int main()
{
    for(int i=1;i<=5;i++){
        fin>>wheel[i].speed;
        wheel[i].sta=0;
        fin>>wheel[i].tq;
        for(int k=1;k<=wheel[i].tq;k++)
            fin>>wheel[i].que[k][0]>>wheel[i].que[k][1];
    }
    do{
        if(pass()) {fout<<Time<<endl;return 0;}
        for(int i=1;i<=5;i++) wheel[i].sta=(wheel[i].sta+wheel[i].speed)%360;
        Time++;
    }while(Time<=360);//一个周期
    fout<<"none"<<endl;
    return 0;
}
