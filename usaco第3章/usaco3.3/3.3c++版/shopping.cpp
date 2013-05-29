/*
ID: silentf1
PROG: shopping
LANG: C++
*/
#include <fstream>
#define MIN(a,b) ((a)>(b)?(b):(a))
using namespace std;
ofstream fout ("shopping.out",ios::out);
ifstream fin ("shopping.in",ios::in);
const long MAX = 999999;
struct node{
    long val[6][2],pay,rank[6];
    bool okay;
}goods[101];
long need[6],pos[6],dp[6][6][6][6][6],buy,hash[1000],cheap;
void Pack(int lev){
    if(lev>buy){
        for(int i=1;i<=goods[0].val[0][0];i++){
            bool okay=true;
            if(goods[i].okay)
            for(int j=1;j<=buy;j++)  if(goods[i].rank[j]>pos[j]) {okay=false;break;}
            if(okay) dp[pos[1]][pos[2]][pos[3]][pos[4]][pos[5]]=
                     MIN(dp[pos[1]][pos[2]][pos[3]][pos[4]][pos[5]],
                     dp[pos[1]-goods[i].rank[1]][pos[2]-goods[i].rank[2]][pos[3]-goods[i].rank[3]][pos[4]-goods[i].rank[4]][pos[5]-goods[i].rank[5]]+goods[i].pay);
        }
    }else
        for(int i=0;i<=need[lev];i++){
            pos[lev]=i;
            Pack(lev+1);
        }
}
int main(){
    for(int i=0;i<=5;i++)
        for(int j=0;j<=5;j++)
            for(int k=0;k<=5;k++)
                for(int p=0;p<=5;p++)
                    for(int q=0;q<=5;q++)
                        dp[i][j][k][p][q]=MAX;
    dp[0][0][0][0][0]=0;
	int temp=0;
    fin>>cheap;
    goods[0].val[0][0]=temp=cheap;
    for(int i=1;i<=cheap;i++){
        fin>>goods[i].val[0][0];
        for(int j=1;j<=goods[i].val[0][0];j++)
            fin>>goods[i].val[j][0]>>goods[i].val[j][1];
		fin>>goods[i].pay;
    }
    fin>>buy;
    if(!buy) {fout<<0<<endl;return 0;}
    goods[0].val[0][0]+=buy;
    for(int i=1;i<=buy;i++){
        temp++;//linux与windows不一致
        fin>>goods[temp].val[1][0]>>need[i]>>goods[temp].pay;
        goods[temp].val[0][0]=goods[temp].val[1][1]=1;
        hash[goods[temp].val[1][0]]=i;
    }
    bool okay;
    for(int i=1;i<=goods[0].val[0][0];i++){ //优化,去掉不可能的商品
        okay=true;
        for(int j=1;j<=goods[i].val[0][0];j++){
            if(!hash[goods[i].val[j][0]]) okay=false;
            goods[i].rank[hash[goods[i].val[j][0]]]=goods[i].val[j][1];
        }
        goods[i].okay=okay;
    }
    Pack(1);
    fout<<dp[need[1]][need[2]][need[3]][need[4]][need[5]]<<endl;
    return 0;
}
