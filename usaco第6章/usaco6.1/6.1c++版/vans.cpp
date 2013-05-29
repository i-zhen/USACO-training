/*
ID: silentf1
TASK: vans
LANG: C++
*/
#include <iostream>
#include <cstring>
#include <cstdio>

#define MAX(a, b) (a > b ? a : b)

using namespace std;

struct Node{
	Node(){
		memset(num, 0, sizeof(num));
		len = 0;
	}
	int num[500], len;
    	friend Node operator +  (const Node &A, const Node &B){
        	Node *C = new Node;
        	int  LEN = MAX(A.len, B.len);
        	for (int i = 1; i <= LEN; i++){
            		C->num[i] += A.num[i] + B.num[i];
            		C->num[i + 1] += C->num[i] / 10;
            		C->num[i] %= 10;
        	} 
         	if(C->num[LEN + 1]!= 0) C->len = ++LEN;
            	else  C->len =LEN;
        	return  *C;
    	}
	friend Node operator -  (const Node &A, const Node &B){
        	Node *C = new Node;
		*C = A;
        	int  LEN = A.len, jinwei = 0;
        	for (int i = 1; i <= LEN; i++){
			if(C->num[i] < B.num[i]){
				C->num[i] += 10;
				for(int j = i + 1; j <= LEN; j++){
					C->num[j]--;
					if(C->num[j] >= 0) break;
					else C->num[j] += 10;
				}
			}
			C->num[i] -= B.num[i];
        	}
		if(!C->num[LEN]) C->len;
        	return  *C;
    	}
	void operator =  (const Node &A){
        	for(int i=1; i <= A.len; i++)  num[i] = A.num [i];
        	len = A.len ;
    	}
	void print(){
		for(int i = len; i >= 1; i--) 
			printf("%d", num[i]);
		printf("\n");
	}
}dp[6];
int n;

int main(){
	freopen("vans.in", "r", stdin);
	freopen("vans.out", "w", stdout);
	cin >> n;
	dp[1].len = 1;
	dp[2].len = 1, dp[2].num[1] = 2;
	dp[3].len = 1, dp[3].num[1] = 4;
	dp[4].len = 2, dp[4].num[1] = 2, dp[4].num[2] = 1;
	if(n >= 5)
		for(int i = 5; i <= n; i++){
			dp[5] = dp[4] + dp[4] + dp[3] + dp[3] + dp[1] - dp[2] - dp[2];
			dp[1] = dp[2], dp[2] = dp[3], dp[3] = dp[4], dp[4] = dp[5];
		}
	dp[(n >= 5 ? 5 : n)].print();
	return 0;
}
