/*
ID: silentf1
PROG: betsy
LANG: C++
*/
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>

using namespace std;

bool map[9][9];
int pos[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}, n, total;

inline int getlive(int x, int y){
	int t = 0;
	for(int k = 0; k < 4; k++)
		if(!map[x + pos[k][0]][y + pos[k][1]])
			t++;
	return t;
}

void dfs(int x, int y, int sum){
	if(x == n && y == 1){	//剪枝1,不能提前到达终点
		if(sum == n * n) total++;
		return;
	}
	if((map[x][y-1] && map[x][y+1] && !map[x-1][y] && !map[x+1][y]) || 
	   (!map[x][y-1] && !map[x][y+1] && map[x-1][y] && map[x+1][y])) //剪枝2，孤立区域剪枝
		return;
	int mx, my, count = 0;
	for(int i = 0; i < 4; i++){		//剪枝3,格子的度的处理	
		int X = x + pos[i][0], Y = y + pos[i][1];
		if(map[X][Y] || (X == n && Y == 1)) continue;
		if(getlive(X, Y) < 2) count++, mx = X, my = Y;
	}
	if(count > 1) return;
	else{
		if(count == 1){
			map[mx][my] = 1;
			dfs(mx, my, sum + 1);
			map[mx][my] = 0;
		}
		else
			for(int i = 0; i < 4; i++){
				int X = x + pos[i][0], Y = y + pos[i][1];
				if(!map[X][Y]){
					map[X][Y] = 1;
					dfs(X, Y, sum + 1);
					map[X][Y] = 0;
				}
			}
	}
}

int main(){
	freopen("betsy.in", "r", stdin);
	freopen("betsy.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)	//处理边界
		map[1][1] = map[0][i] = map[n + 1][i] = map[i][0] = map[i][n + 1] = 1;
	dfs(1, 1, 1);	
	cout << total << endl;
	return 0;
}
