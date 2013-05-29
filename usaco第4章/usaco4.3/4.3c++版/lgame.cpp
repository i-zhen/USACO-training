/*
ID: silentf1
PROG: lgame
LANG: C++
*/
#include<fstream>
#include<cstring>
#include<cstdlib>
#include<string.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define BIG 40005
using namespace std;
ofstream fout ("lgame.out",ios::out);
ifstream fin ("lgame.in",ios::in);
ifstream fdt ("lgame.dict",ios::in);
string dict[BIG],module,ans[BIG];
long lend,pos[BIG][3],maxn,lena
    ,score[]={2,5,4,4,1,6,5,5,1,7,6,3,5,2,3,5,7,2,1,2,4,6,6,7,5,7};
bool rec[9][2],flag;
int cmp(const void *a,const void *b){
    string A=*(string*)a,B=*(string*)b;
    if(A>B) return 1;else return -1;
}
int main()
{
    while(fdt>>dict[++lend]) if(dict[lend][0]=='.') break;
	lend--;
    fin>>module;
        for(int i=1;i<=lend;i++){
        memset(rec,0,sizeof(rec));
        for(int j=0;j<dict[i].length();j++){
            flag=false;
            for(int k=0;k<module.length();k++)
                if(!rec[k][0] && module[k]==dict[i][j]){
                    pos[i][0]|=(1<<k);
                    pos[i][1]+=score[module[k]-97];
                    flag=true;
                    rec[k][0]=true;
                    break;
                }
            if(flag) for(int k=module.length()-1;k>=0;k--)
                        if(!rec[k][1] && module[k]==dict[i][j]){
                        pos[i][2]|=(1<<k);
                        rec[k][1]=true;
                        break;
                    }
            if(!flag) {pos[i][1]=0;break;}
        }
        if(pos[i][1]==maxn) ans[++lena]=dict[i];
        if(pos[i][1]>maxn){
            maxn=pos[i][1];
            lena=1;
            ans[lena]=dict[i];
        }
    }
    for(int i=1;i<lend;i++)
    if(pos[i][1])
        for(int j=i+1;j<=lend;j++)
        if(pos[j][1] && ((pos[i][0]&pos[j][2])==0)){
            if(pos[i][1]+pos[j][1]==maxn) ans[++lena]=dict[i]+' '+dict[j];
            if(pos[i][1]+pos[j][1]>maxn){
                maxn=pos[i][1]+pos[j][1];
                lena=1;
                ans[lena]=dict[i]+' '+dict[j];
            }
        }
    ans[0][0]='0';
    qsort(ans,lena+1,sizeof(ans[0]),cmp);
    fout<<maxn<<endl;
    for(int i=1;i<=lena;i++) fout<<ans[i]<<endl;
	return 0;
}
