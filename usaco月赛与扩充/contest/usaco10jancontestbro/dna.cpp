/*
PROG: dna
LANG: C++
ID: silentf1
*/
#include<fstream>
#include<cstring>
using namespace std;
ifstream fin("dna.in");
ofstream fout("dna.out");
int m,f,val;
char bull[21][26],cow[21][26];
inline bool value(int a,int b,int c,bool isbull)
{
    int len=0;
    if(isbull) len=strlen(bull[c]); else len=strlen(cow[c]);
    for(int i=0;i<len;i++)
    if(isbull){if(bull[c][i]!=bull[a][i] && bull[c][i]!=cow[b][i]) return false;}
    else{if(cow[c][i]!=bull[a][i] && cow[c][i]!=cow[b][i]) return false;}
    return true;
}
int main()
{
    fin>>m>>f;
    for(int i=1;i<=m;i++) fin>>bull[i];
    for(int i=1;i<=f;i++) fin>>cow[i];
    for(int i=1;i<=m;i++)
        for(int j=1;j<=f;j++)
        {
            val=0;
            for(int k=1;k<=m;k++) if(k!=i)
              if(value(i,j,k,true)) val++;
            for(int l=1;l<=f;l++) if(l!=j)
              if(value(i,j,l,false)) val++;
            if(j!=f) fout<<val<<' '; else fout<<val<<endl;
        }
    return 0;
};
