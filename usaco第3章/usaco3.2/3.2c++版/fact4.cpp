/*
ID: silentf1
PROG: fact4
LANG: C++
*/
#include <fstream>
using namespace std;
ofstream fout ("fact4.out",ios::out);
ifstream fin ("fact4.in",ios::in);
int main()
{
    long n,fact=1;
    fin>>n;
    for(int i=2;i<=n;i++){
        fact*=i;
        while(fact%10==0) fact/=10;
        fact%=100000;
    }
    fout<<fact%10<<endl;
    return 0;
}
