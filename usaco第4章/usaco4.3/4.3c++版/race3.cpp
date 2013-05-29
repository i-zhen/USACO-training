/*
ID: silentf1
PROG: race3
LANG: C++
*/
#include <fstream>
#include<cstring>
#define BIG 55
using namespace std;
ofstream fout ("race3.out",ios::out);
ifstream fin ("race3.in",ios::in);
struct node{
    int pot[BIG],len;
}ansm,ansn;
int n=0,temp,level[BIG]={0,0};
bool gra[BIG][BIG],repeat[BIG];
bool needpoint(int pos){
    if(pos==n) return false;
    repeat[pos]=1;
    for(int i=0;i<=n;i++)
        if(!repeat[i] && gra[pos][i] && !needpoint(i)) return false;
    return true;
}
void bfslevel(){
    int now,tail=1,head=0,dl[BIG]={0,0,0};
    memset(repeat,0,sizeof(repeat));
	repeat[0]=1;
    while(head<tail){
        now=dl[++head];
        for(int i=0;i<=n;i++)
        if(!repeat[i] && gra[now][i]){
			repeat[i]=1;
            dl[++tail]=i;
            level[i]=level[now]+1;
        }
    }
}
bool midpoint(int pos){
    if(level[pos]<level[temp]) return false;
    repeat[pos]=1;
    for(int i=0;i<=n;i++)
        if(!repeat[i] && gra[pos][i] && !midpoint(i)) return false;
    return true;
}
int main()
{
    ansn.len=ansm.len=0;
    while(fin>>temp){
        if(temp==-1) break;
        if(temp==-2) n++;
        gra[n][temp]=1;
    }
    n--;
    for(int i=1;i<n;i++){
        memset(repeat,0,sizeof(repeat));
        repeat[i]=1;if(needpoint(0))
        ansn.pot[++ansn.len]=i;
    }
    bfslevel();
    for(int i=1;i<=ansn.len;i++){
        memset(repeat,0,sizeof(repeat));
        repeat[ansn.pot[i]]=1;
        temp=ansn.pot[i];
        if(midpoint(ansn.pot[i])) ansm.pot[++ansm.len]=ansn.pot[i];
    }
    if(ansn.len) fout<<ansn.len<<' '; else fout<<0<<endl;
    for(int i=1;i<ansn.len;i++) fout<<ansn.pot[i]<<' ';
    if(ansn.len) fout<<ansn.pot[ansn.len]<<endl;
    if(ansm.len) fout<<ansm.len<<' '; else fout<<0<<endl;
    for(int i=1;i<ansm.len;i++) fout<<ansm.pot[i]<<' ';
    if(ansm.len) fout<<ansm.pot[ansm.len]<<endl;
	return 0;
}
