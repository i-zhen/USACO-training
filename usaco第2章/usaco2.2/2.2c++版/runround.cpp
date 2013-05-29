/*
ID: silentf1
PROG: runround
LANG: C++
*/
#include <fstream>
using namespace std;
ofstream fout ("runround.out",ios::out);
ifstream fin ("runround.in",ios::in);
long n,num[10],i;
bool jl[10],tpd[10],texit;
bool pd(int a)
{
	for(int y=1;y<=a;y++)
		if(!jl[y]) return false;
	return true;
}
int main()
{
	fin>>n;
	n++;
	for(;;)
	{
		int temp=n,te,pos=1,tot=0;
		i=0;
		texit=false;
		for(int w=1;w<=9;w++)	tpd[w]=false;
		while (temp!=0)
		{
			te=temp%10;
			temp/=10;
			i++;
			num[i]=te;
			if(!tpd[te]) tpd[te]=true; else {texit=true;n++;break;}
			jl[i]=false;
		}
		if(!texit)
		{
			for(int j=1;j<=i/2;j++)
			{
				int a=num[j];
				num[j]=num[i-j+1];num[i-j+1]=a;
			}
			while(tot<i)
			{
				jl[pos]=true;
				pos=(pos+num[pos])%i;
				if(pos==0) pos=i;
				tot++;
			}
			if((pd(i))&&(pos==1)) break;
			else n++;
		}
	}
	for(int k=1;k<i;k++)
		fout<<num[k];
	fout<<num[i]<<endl;
    return 0;
}
