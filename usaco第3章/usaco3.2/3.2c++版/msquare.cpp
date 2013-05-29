/*
ID: silentf1
PROG: msquare
LANG: C++
*/
#include<fstream>
using namespace std;
ofstream fout ("msquare.out",ios::out);
ifstream fin ("msquare.in",ios::in);
const long MAX=15000,M=769123;//保证均匀散列
struct node{
    int now[9],len;
    char Q[500];
}dl[15001];
int lenh=1,state,hanum[9]={0,10000000,1000000,100000,10000,1000,100,10,1};
bool hash[1500000];
inline long Hash(int *num){ //自己定义的hash
    long temp=0;
    for(int i=1;i<=8;i++) temp+=num[i]*hanum[i];
    return temp%M;
}
inline void change(int &a,int &b){
    short k=a;
    a=b;b=k;
}
inline void exchange(char what,int *num){
    int a1=num[4],b1=num[5];
    switch(what){
        case('A'):
            for(int i=1;i<=4;i++) change(num[i],num[8-i+1]);
        return;
        case('B'):
            for(int i=4;i>=2;i--) {num[i]=num[i-1];num[8-i+1]=num[8-i+2];}
            num[1]=a1;num[8]=b1;
        return;
        case('C'):
            change(num[7],num[6]); //2 3
            change(num[6],num[3]); //2 6
            change(num[2],num[3]); //2 7
        return;
    }
}
inline void queuein(long tail,node &Node){
    if(tail%MAX==0) dl[MAX]=Node;
    else dl[tail%MAX]=Node;
}
inline node queueout(long head){
    if(head%MAX==0) return dl[MAX];
    else return dl[head%MAX];
}
inline void bfsandprint(){
    long head=0,tail=1,h;
    node qin,qout;
    while(head<tail){
        qout=queueout(++head);
        int num[9],tnum[9];
        for(int i=1;i<=8;i++) tnum[i]=num[i]=qout.now[i];
        for(char i='A';i<='C';i++){
            char ex=i;
            exchange(i,num);
            h=Hash(num);
            if(!hash[h]) {
                hash[h]=true;
                qin=qout;
                for(int p=1;p<=8;p++) qin.now[p]=num[p];
                qin.Q[++qin.len]=ex;
                queuein(++tail,qin);
                if(hash[state]){
                    fout<<qin.len<<endl;
                    int j=1;
                    for(;j<=qin.len;j++) {fout<<qin.Q[j];if(j%60==0) fout<<endl;}
                    if(j%60!=0) fout<<endl;
                    return ;
                }
            }
            for(int i=1;i<=8;i++) num[i]=tnum[i];
        }
    }
}
int main()
{
    long Cin;
    for(int i=1;i<=8;i++){fin>>Cin;state+=Cin*hanum[i];dl[1].now[i]=i;}
    if(state==12345678) fout<<0<<endl<<endl;
    else {state%=M;bfsandprint();}
    return 0;
}
