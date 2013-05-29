/*
ID: silentf1
PROG: ratios
LANG: C++
*/
#include <fstream>
#include <cmath>
using namespace std;
ofstream fout ("ratios.out",ios::out);
ifstream fin ("ratios.in",ios::in);
const double JING=0.000001;
double A[4][4],B[4],X[4],fen1,fen2;
long tX[4];
long gcd(long m,long n){
	if(m%n==0) return n;
	else return gcd(n,m%n);
}
int main()
{
    for(int i=1;i<=3;i++) fin>>B[i];
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++){
            fin>>A[j][i];
            A[j][0]+=A[j][i];
        }
    for(int i=1;i<=3;i++){ //guass
		if(i==3) {fen1=fabs(A[i][i]);fen2=B[3];}
        double yuefen=fabs(A[i][i]);
        for(int j=0;j<=3;j++) A[i][j]/=(double)yuefen;
		B[i]/=yuefen;
        for(int k=i+1;k<=3;k++){
            double tem=A[k][i];
            for(int j=1;j<=3;j++)
                if(A[i][i]>0){
                    A[k][j]=tem*A[i][j]-A[k][j];
                    if(j==3){
                        A[k][0]=A[i][0]*tem-A[k][0];
                        B[k]=B[i]*tem-B[k];
                }}
                else{
                    A[k][j]=tem*A[i][j]+A[k][j];
                    if(j==3){
                        A[k][0]=A[i][0]*tem+A[k][0];
                        B[k]=B[i]*tem+B[k];
                    }
                }
            }
        if(A[i][0]==0) {fout<<"NONE"<<endl;return 0;}
    }
    fen1=(fabs((long)fen1-fen1)<0.1?(long)fen1:(long)fen1+1);
    fen2=(fabs((long)fen2-fen2)<0.1?(long)fen2:(long)fen2+1);
    fen1=fen1/gcd((long)fen1,(long)fen2);
    for(int i=3;i>=1;i--){
        double temp=0.0;
        for(int j=1;j<=3;j++) if(j!=i) temp+=A[i][j]*X[j];
		X[i]=(double)(B[i]-temp)/A[i][i];
    }
	for(int i=1;i<=3;i++) {
	    tX[i]=(long)(X[i]*fen1)+1;
	    if(tX[i]<0 ){fout<<"NONE"<<endl;return 0;}
	}
	for(int i=1;i<=3;i++) if(fabs(X[i]*fen1-tX[i])<0.1) fout<<tX[i]<<' ';
        else fout<<tX[i]-1<<' ';
    fout<<fen1<<endl;
}
