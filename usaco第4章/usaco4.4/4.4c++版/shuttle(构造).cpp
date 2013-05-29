/*
ID: silentf1
PROG: shuttle
LANG: C++
*/
#include<fstream>
using namespace std;
ofstream fout ("shuttle.out",ios::out);
ifstream fin ("shuttle.in",ios::in);
int n,rect[500],dis,head,len,rec;
int main()
{
    fin>>n;
    for(int i=1;i<=n+1;i++){
        dis=(i&1?-2:2);
        head=(i&1?n+i:n-i+2);
        for(int j=1;j<=i;j++)
            rect[++len]=head+dis*(j-1);
    }
    for(int i=n;i>=1;i--)
        for(int j=1;j<=i;j++)
            rect[++len]=rect[i*(i-1)/2+j];
    for(int i=2;i<len;i++)
        (++rec%20?fout<<rect[i]<<' ':fout<<rect[i]<<endl);
    fout<<rect[len]<<endl;
	return 0;
}
