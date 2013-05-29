/*
ID: silentf1
PROG: tour
LANG: C++
*/
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <map>

#define MAX(a, b) (a > b ? a : b)

using namespace std;

const long MAXN = 105;
int n, v, dp[MAXN][MAXN], tot;
map<string, int> city;
bool line[MAXN][MAXN];


int main(){
	freopen("tour.in", "r", stdin);
	freopen("tour.out", "w", stdout);
	cin >> n >> v;
	for(int i = 1; i <= n; i++){
		string temp;
		cin >> temp;
		city[temp] = i;
	}
	for(int i = 1; i <= v; i++){
		string a, b;
		cin >> a >> b;
		int x = city[a], y = city[b];
		line[x][y] = line[y][x] = 1;
	}
	dp[1][1] = 1;
	for(int i = 1; i < n; i++)
		for(int j = i + 1; j <= n; j++){
			for(int k = 1; k < j; k++)
				if(line[k][j] && dp[i][k] > 0)
					dp[i][j] = MAX(dp[i][j], dp[i][k] + 1);
			dp[j][i] = dp[i][j];
		}
	for(int i = 1; i < n; i++)
		tot = MAX(tot, (line[i][n] ? dp[i][n] : 0));
	cout << (tot > 1 ? tot : 1) << endl;
	return 0;
}

