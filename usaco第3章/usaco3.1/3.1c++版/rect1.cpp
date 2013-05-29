/*
ID: silentf1
PROG: rect1
LANG: C++
*/
#include<fstream>
using namespace std;
ofstream fout ("rect1.out",ios::out);
ifstream fin ("rect1.in",ios::in);
const long MAX = 1001;
struct node{
  long llx,lly,urx,ury,colour;
}rect[MAX];
struct link1{
  long llx,lly,urx,ury;
  link1 *next,*up;
}*head,*tail;
long a,b,n,ans[2501];
bool quit;
inline long TMAX(long a,long b) {return (a>b?a:b);}
inline long TMIN(long a,long b) {return (a<b?a:b);}
inline bool add(long llx,long lly,long urx,long ury,link1 *t)
{
  if(llx==urx || lly==ury) return false;//the area cannot be zero
  link1 *temp=new link1;
  temp->llx=llx;
  temp->lly=lly;
  temp->urx=urx;
  temp->ury=ury;
  t->next=temp;
  temp->up=t;
  return true;
}
inline void work(int n)
{
  link1 *temp,*ttail;
  long s=0;
  for(int i=n;i>=1;i--) //倒序染色
  {
    temp=head;
    ttail=tail;
	quit=false;
    while(temp!=NULL)
    {
      if(rect[i].urx<=temp->llx || temp->urx<=rect[i].llx || rect[i].ury<=temp->lly || temp->ury<=rect[i].lly)
      {//判断是否拥有交集
		if(temp==tail) quit=true;//quit
		temp=temp->next;
      }
      else//扩展
      {//计算交集面积
	      long x1=TMIN(rect[i].urx,temp->urx),x2=TMAX(rect[i].llx,temp->llx),
		   y1=TMIN(rect[i].ury,temp->ury),y2=TMAX(rect[i].lly,temp->lly);
	      if(rect[i].colour!=1)
	      {
		      s=(x1-x2)*(y1-y2);
		      ans[rect[i].colour]+=s;
		      ans[1]-=s;
	      }
	      if(rect[i].ury<temp->ury) if(add(temp->llx,rect[i].ury,temp->urx,temp->ury,ttail)) ttail=ttail->next; //1
	      if(rect[i].lly>temp->lly) if(add(temp->llx,temp->lly,temp->urx,rect[i].lly,ttail)) 	ttail=ttail->next;//3
	      if(rect[i].llx>temp->llx) if(add(temp->llx,y2,rect[i].llx,y1,ttail)) 	ttail=ttail->next; //2
	      if(rect[i].urx<temp->urx) if(add(rect[i].urx,y2,temp->urx,y1,ttail))  ttail=ttail->next; //4
	      link1 *tdelete=temp;//删除扩展完毕的矩形
	      if(temp==tail) quit=true;
	      if(temp==head) { head=temp->next;head->up=NULL;}
	      else
	      {
		      temp->up->next=temp->next;
		      temp->next->up=temp->up;
	      }
	      temp=temp->next;
	      delete tdelete;
      }
      if(quit) break;
    }
    tail=ttail;//refresh
  }
}
int main()
{
  fin>>a>>b>>n;
  ans[1]=a*b;
  head=new link1;
  head->llx=0;
  head->lly=0;
  head->urx=a;
  head->ury=b;
  tail=head;
  for(int i=1;i<=n;i++)
    fin>>rect[i].llx>>rect[i].lly>>rect[i].urx>>rect[i].ury>>rect[i].colour;
  work(n);
  for(int i=1;i<=2500;i++)
    if(ans[i]!=0) fout<<i<<' '<<ans[i]<<endl;
  return 0;
}
