/*
PROG: hex
LANG: C++
ID: silentf1
*/
#include<fstream>
#include<string>
#include<cstring>
#include<cctype>
#define BIG 40000
using namespace std;
ifstream fin("hex.in");
ofstream fout("hex.out");
string hexn;
char work[4];
int octn[BIG],leno,jinzhi[]={0,1,10,100,1000,10000};
int pf(int i){
    if(i==1) return 1;
    if(i==2) return 16;
    return  256;
}
void zhuanhuan(){
    int tot=0,okay=0;
    for(int i=1;work[i];i++)
        if(isdigit(work[i])) tot+=pf(i)*(work[i]-48);
		else tot+=pf(i)*(work[i]-55);
    leno++;
    while(tot){
        okay++;
        octn[leno]+=(tot%8)*jinzhi[okay];
        tot/=8;
    }
}
int main(){
    fin>>hexn;
    for(long i=hexn.length()-1;i>=0;){
        memset(work,0,sizeof(work));
        if(i>=0) work[1]=hexn[i];
        if(i-1>=0) work[2]=hexn[i-1];
        if(i-2>=0) work[3]=hexn[i-2];
        zhuanhuan();
        if(i-3>=0) i-=3;
        else break;
    }
	while(!octn[leno]) leno--;
    for(int i=leno;i>=1;i--)
        fout<<octn[i];
    fout<<endl;
    return 0;
}
