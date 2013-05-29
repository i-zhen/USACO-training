/*
ID: silentf1
PROG: prime3
LANG: C++
*/
#include<cstdio>//AC
#include<cstring>
#include<cmath>
#define BIG 1005
const bool LIE = true;
struct node{
    int num[6],val;
}pri[BIG];
int K1,Lenp,TOTAL,FIRST,ranc[6][6],RANC[BIG][6][6],outtot,multi[]={0,1,10,100,1000,10000};
inline bool checkprime(const int &prime){ //二分法查找
    if(!(prime&1)) return false;
    int left=1,right=Lenp,mid=(left+right)>>1;
    while(left<right){
        if(prime>pri[mid].val){
            left=mid+1;
            mid=(left+right)>>1;
        }
        else{
            right=mid;
            mid=(left+right)>>1;
        }
    }
    if(prime==pri[left].val) return true;
    return false;
}
inline int add(const bool &lie,const int &pos,const int &len){ //求和函数
    int sum=0;
    if(lie) for(int i=1;i<=len;i++) sum+=ranc[i][pos];
        else for(int i=1;i<=len;i++) sum+=ranc[pos][i];
    return sum;
}
inline int multiply(const bool &lie,const int &pos){ //求数字的函数
    int num=0;
    if(lie) for(int i=1;i<=5;i++) num+=ranc[i][pos]*multi[6-i];
        else for(int i=1;i<=5;i++) num+=ranc[pos][i]*multi[6-i];
    return num;
}
inline int multiply(const bool &lie,const int &wh,const int &pos){ //求数字的函数
    int num=0;
    if(lie) for(int i=1;i<=5;i++) num+=RANC[wh][i][pos]*multi[6-i];
        else for(int i=1;i<=5;i++) num+=RANC[wh][pos][i]*multi[6-i];
    return num;
}
inline void lastcheck(){ //可行性判断，并生成最终方案
    int TOT2,TOT3,TOT4,TOT5,TOT6;
    TOT3=add(!LIE,2,5)-ranc[2][3];
    TOT4=add(!LIE,4,5)-ranc[4][3];
    if(TOT3>TOTAL || TOT4>TOTAL ) return;
    ranc[2][3]=TOTAL-TOT3;ranc[4][3]=TOTAL-TOT4;
    TOT2=multiply(LIE,3);TOT4=multiply(!LIE,2);
    TOT5=multiply(!LIE,3);TOT6=multiply(!LIE,4);
    if(!checkprime(TOT2) || !checkprime(TOT5) || !
        checkprime(TOT4) || !checkprime(TOT6)) return;
    memcpy(RANC[++outtot],ranc,sizeof(ranc));
}
bool midpane2(int lev){
    if(lev>2){
        lastcheck();
        return true;
    }
    switch(lev){
        case(1):
               for(int i=1;i<=Lenp;i++)
                if(pri[i].num[1]==ranc[1][1] && pri[i].num[5]==ranc[5][1]
                && pri[i].num[2] && pri[i].num[3] && pri[i].num[4]){
                    for(int i1=2;i1<=4;i1++) ranc[i1][1]=pri[i].num[i1];
                    if(!midpane2(lev+1)) return false;
                }
        break;
        case(2):
               for(int i=1;i<=Lenp;i++)
                if(pri[i].num[1]==ranc[1][5] && pri[i].num[5]==ranc[5][5]
                && (pri[i].num[2]&1) && (pri[i].num[3]&1) && (pri[i].num[4]&1)){
                    for(int i1=2;i1<=4;i1++) ranc[i1][5]=pri[i].num[i1];
                    if(!midpane2(lev+1)) return false;
                }
        break;
    }
    return true;
}
bool midpane1(int lev){
    if(lev>2){
        int TOT1,TOT2; //以下是可行性剪枝
        TOT1=add(LIE,2,5)-ranc[3][2];
        TOT2=add(LIE,4,5)-ranc[3][4];
        if(TOT1>TOTAL || TOT2>TOTAL) return true;
        ranc[3][2]=TOTAL-TOT1;ranc[3][4]=TOTAL-TOT2;
        TOT1=multiply(LIE,2);TOT2=multiply(LIE,4);
        if(!checkprime(TOT1) || !checkprime(TOT2)) return true;
        midpane2(1);
        return true;
    }
    switch(lev){
        case(1):
            for(int i=1;i<=Lenp;i++)
                if(pri[i].num[1]==ranc[1][1] && pri[i].num[5]==ranc[1][5]
                && pri[i].num[2] && pri[i].num[3] && pri[i].num[4]){ //对于开头是否是0要剪枝
                    for(int i1=2;i1<=4;i1++) ranc[1][i1]=pri[i].num[i1];
                    if(!midpane1(lev+1)) return false;
                }
        break;
        case(2):
               for(int i=1;i<=Lenp;i++)
                if(pri[i].num[1]==ranc[5][1] && pri[i].num[5]==ranc[5][5]
                && (pri[i].num[2]&1) && (pri[i].num[3]&1) && (pri[i].num[4]&1)){ //末尾的剪枝：判断是不是奇数
                    for(int i1=2;i1<=4;i1++) ranc[5][i1]=pri[i].num[i1];
                    if(!midpane1(lev+1)) return false;
                }
        break;
    }
    return true;
}
inline void crosspane(){
    for(int i=1;i<=Lenp;i++)
        if(pri[i].num[1]==FIRST){
            for(int i1=1;i1<=5;i1++) ranc[i1][i1]=pri[i].num[i1];
            for(int j=1;j<=Lenp;j++)
                if(pri[j].num[3]==ranc[3][3]){
                    for(int j1=1;j1<=5;j1++) ranc[j1][6-j1]=pri[j].num[6-j1];//以下是可行性剪枝，对于当前总和超过TOTAL的要剪掉
                    if(ranc[1][1]+ranc[1][5]>TOTAL || ranc[1][1]+ranc[5][1]>TOTAL || ranc[5][1]+ranc[5][5]>TOTAL || ranc[1][5]+ranc[5][5]>TOTAL ||
                       ranc[2][2]+ranc[2][4]>TOTAL || ranc[2][2]+ranc[4][2]>TOTAL || ranc[4][2]+ranc[4][4]>TOTAL || ranc[4][4]+ranc[4][2]>TOTAL)
                       continue;
                    midpane1(1);
                }
        }
}
inline bool cmp(const int &A,const int &B){
    int ma,mb;
    for(int i=1;i<=5;i++){
        ma=multiply(!LIE,A,i);
        mb=multiply(!LIE,B,i);
        if(ma<mb) return true;
        if(ma==mb) continue;
        if(ma>mb) return false;
    }
    return false;
}
inline void sort(){
    int ranc[6][6];
    for(int i=1;i<outtot;i++)
        for(int j=1;j<=outtot-i;j++)
            if(cmp(j,j+1)){
                memcpy(ranc,RANC[j],sizeof(RANC[j]));
                memcpy(RANC[j],RANC[j+1],sizeof(RANC[j+1]));
                memcpy(RANC[j+1],ranc,sizeof(ranc));
            }
}
int main()
{
    freopen("prime3.in","r",stdin);
    freopen("prime3.out","w",stdout);
    scanf("%d%d",&TOTAL,&FIRST);
    for(int i=10001;i<=99997;i+=2){ //提前构造出满足条件的素数
        bool flag=false;
        for(int j=2;j<=(int)sqrt(i);j++)if(i%j==0){flag=true;break;}
        if(!flag){
            int total=0,k=i,num[6],pos=0;
            while(k>0){
                num[6-(++pos)]=k%10;
                total+=num[6-pos];
                k/=10;
            }
            if(total==TOTAL){
                memcpy(pri[++Lenp].num,num,sizeof(num));
                pri[Lenp].val=i;
            }
        }
    }
    crosspane();
    sort(); //冒泡排序
    for(int k=outtot;k>=1;k--){
        for(int i=1;i<=5;i++){
            for(int j=1;j<=5;j++)
                printf("%d",RANC[k][i][j]);
            printf("\n");
        }
        if(k!=1) printf("\n");
    }
    if(!outtot) printf("NONE\n");
	return 0;
}
