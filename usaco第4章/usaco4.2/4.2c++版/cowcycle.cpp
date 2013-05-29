/*
ID: silentf1
PROG: cowcycle
LANG: C++
*/
#include<fstream>
#include<cstring>
#include<cmath>
using namespace std;
ofstream fout ("cowcycle.out",ios::out);
ifstream fin ("cowcycle.in",ios::in);
int f,f1,f2,r,r1,r2;
double bs[6],fs[11],obs[6],ofs[11],fx=99999.9;
inline double compute(){
    double com[51],COM[51],ans=0.0,xba=0.0,change;
    int pos=0;
    memset(com,0,sizeof(com));
    memset(COM,0,sizeof(COM));
    for(int i=1;i<=f;i++)
		for(int j=1;j<=r;j++)
			com[++pos]=(double)bs[i]/(double)fs[j];
    com[0]=-1.0;
    for(int i=1;i<pos;i++)
		for(int j=1;j<=pos-i;j++)
			if(com[j]-com[j+1]>0){
				change=com[j+1];
				com[j+1]=com[j];
				com[j]=change;
			}
    for(int i=1;i<pos;i++){
		COM[i]=com[i+1]-com[i];
		xba+=COM[i];
    }
    xba/=(double)(pos-1);
    for(int i=1;i<pos;i++) ans+=(COM[i]-xba)*(COM[i]-xba);
    return ans/(double)(pos-1);
}
void afterfind(int lev,int R1){
    if(lev>r){
        if(bs[f]*fs[r]<3*bs[1]*fs[1]) return;
        double now=compute();
        if(now-fx<0){
			fx=now;
            memcpy(obs,bs,sizeof(bs));
            memcpy(ofs,fs,sizeof(fs));
        }
        return ;
    }
    for(int i=R1;i<=r2;i++){
        fs[lev]=i;
        afterfind(lev+1,i+1);
    }
}
void behindfind(int lev,int F1){
    if(lev>f){
        if(bs[f]*r2<3*bs[1]*r1) return;
            else afterfind(1,r1);
        return ;
    }
    for(int i=F1;i<=f2;i++){
        bs[lev]=i;
        behindfind(lev+1,i+1);
    }
}
int main()
{
    fin>>f>>r>>f1>>f2>>r1>>r2;
    behindfind(1,f1);
    for(int i=1;i<f;i++) fout<<obs[i]<<' ';
    fout<<obs[f]<<endl;
    for(int i=1;i<r;i++) fout<<ofs[i]<<' ';
    fout<<ofs[r]<<endl;
 	return 0;
}
