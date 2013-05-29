/*
ID: silentf1
TASK: rectbarn
LANG: C++
*/
#include <iostream>
#include <cstring>
#include <cstdio>

#define MIN(a, b) (a < b ? (a ? a : b) : b)
#define MAX(a, b) (a > b ? a : b)
#define MAXN 3000 + 5

using namespace std;

bool map[MAXN][MAXN];
int lr[MAXN][2], h[MAXN], r, c, p, x, y, ans;//滚动数组

int main(){
	freopen("rectbarn.in", "r", stdin);
	freopen("rectbarn.out", "w", stdout);
	cin >> r >> c >> p;
	for(int i = 1; i <= p ; i++){
		scanf("%d%d", &x, &y);
		map[x][y] = 1;
	}
	for(int i = 1; i <= r; i++){
		p = 0; //统计横向可以扩展的长度
		for(int j = 1; j <= c; j++)
			if(!map[i][j]){
				h[j] = h[j] + 1, ++p;
				lr[j][0] = MIN(lr[j][0], p);
			}else
				h[j] = 0, lr[j][0] = 0, p = 0;
		p = 0;
		for(int j = c; j >= 1; j--)
			if(!map[i][j]){
				++p, lr[j][1] = MIN(lr[j][1], p);
				ans = MAX(ans, h[j] * (lr[j][0] + lr[j][1] - 1));
			}else
				lr[j][1] = 0, p = 0;
	}
	cout << ans << endl;
	return 0;
}
