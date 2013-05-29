/*
ID: silentf1
PROG: frac1
LANG: C++
*/
#include <fstream>
using namespace std;
ofstream fout ("frac1.out",ios::out);
ifstream fin ("frac1.in",ios::in);
struct totnum
{
	public:
	int x,y;
	totnum *next;
}tot;
totnum *head=NULL,*te,*ls;
int n;
double temp=0.000001,a,b;
bool flag;
int main()
{
	fin>>n;
	fout<<"0/1"<<endl;
	for(int i=2;i<=n;i++) //分母
		for(int j=1;j<i;j++) //分子
		{
			//prime
			flag=false;
			for(int p=2;p<=i;p++)
				if ((i%p==0)&&(j%p)==0)
				{
					flag=true;
					break;
				}
			//main
			if (!flag) 
			{
				a=(double)j/i;
				if(head==NULL)
				{
					head=new totnum;
					head->x=j;
					head->y=i;
					head->next=NULL;
				}
				else
				{
					te=head;
					ls=NULL;
					while(te!=NULL)
					{
						b=(double)te->x/te->y;
						if(a-b>temp) ls=te;
							else if(b-a>temp) break;
						te=te->next;
					}
					if(ls==NULL)
					{
						ls=new totnum;
						ls->x=j;
						ls->y=i;
						ls->next=head;
						head=ls;
					}
					else
					{
						te=NULL;
						te=new totnum;
						te->x=j;
						te->y=i;
						te->next=ls->next;
						ls->next=te;
					}
				}
			}
		}
	while(head!=NULL)
	{
		fout<<head->x<<'/'<<head->y<<endl;
		delete head;
		head=head->next;
	}
	fout<<"1/1"<<endl;
    return 0;
}
