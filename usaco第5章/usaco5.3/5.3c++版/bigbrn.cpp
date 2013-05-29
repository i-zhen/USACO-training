/*
ID: silentf1
PROG: bigbrn
LANG: C++
*/
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>

#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a < b ? a : b)

using namespace std;

bool map[1005][1005];
int n, m, dp[1005][1005], ans;

int main(){
	freopen("bigbrn.in", "r", stdin);
	freopen("bigbrn.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		map[a][b] = 1;
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(!map[i][j]){
				if(map[i - 1][j] || map[i - 1][j - 1] || map[i][j - 1]) dp[i][j] = 1;
				else{
					dp[i][j] = MIN(dp[i - 1][j], dp[i][j - 1]);
					dp[i][j] = MIN(dp[i][j], dp[i - 1][j - 1]);
					dp[i][j]++;
				}
				ans = MAX(ans, dp[i][j]);
			}
	cout << ans << endl;
	return 0;
}
