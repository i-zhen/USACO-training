/*
ID: silentf1
PROG: fc
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>

#define ISBIG(a,b) ((a)-(b)>0?1:-1)
#define BIG 100005

using namespace std;
const double JD = 0.000001;

struct node{
    double x,y;
}num[BIG];

long n;
long Stack[BIG],lens=0;
node A,B;

inline bool CrossPruduct(const node &A,const node &B){
    double ans=A.x*B.y-A.y*B.x;
    return !(ans<0);
}

inline void make(const int &i){
    A.x=num[Stack[lens]].x-num[Stack[lens-1]].x;
    A.y=num[Stack[lens]].y-num[Stack[lens-1]].y;
    B.x=num[i].x-num[Stack[lens]].x;
    B.y=num[i].y-num[Stack[lens]].y;
}

inline void dograham(const int &i){
    if(lens==1)
        Stack[++lens]=i;
    else{
        make(i);
        if(CrossPruduct(A,B))
            Stack[++lens]=i;
        else{
            while(--lens>1){
                make(i);
                if(CrossPruduct(A,B))
                    break;
            }
            Stack[++lens]=i;
        }
    }
}

inline double compute(){
    double ans=0;
    for(int i=1;i<lens;i++)
        ans+=sqrt((num[Stack[i]].x-num[Stack[i+1]].x)*(num[Stack[i]].x-num[Stack[i+1]].x)+
                (num[Stack[i]].y-num[Stack[i+1]].y)*(num[Stack[i]].y-num[Stack[i+1]].y));
    return ans;
}
inline void graham(){
    Stack[++lens]=1;
    for(int i=2;i<=n;i++)
        dograham(i);
    for(int i=Stack[lens]-1;i>=1;i--)
        dograham(i);
}

int cmp(const void *a,const void *b){
    node A=*(node *)a,B=*(node *)b;
    if(fabs(A.y-B.y)<JD){
        if(fabs(A.x-B.x)<JD) return 0;
        else return ISBIG(A.x,B.x);
    }
    else return ISBIG(A.y,B.y);
}

int main(){
    freopen("fc.in","r",stdin);
    freopen("fc.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>num[i].x>>num[i].y;
    num[0].x=-15000000;
    num[0].y=-15000000;
    qsort(num,n+1,sizeof(num[0]),cmp);
    graham();
    cout.setf(ios::fixed);
    cout.precision(2);
    cout<<compute()<<endl;
    return 0;
}
