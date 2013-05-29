/*
ID: silentf1
TASK: twofive
LANG: C++
*/
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

char ch, str[30];
int n, dp[6][6][6][6][6], used[26], maxr[6], maxc[6], bnd[6], ans, cur;

int calc(int a, int b, int c, int d, int e, int chr){
	int &inwork = dp[a][b][c][d][e];
	if(inwork) return inwork;
	if(used[chr]) return inwork = calc(a, b, c, d, e, chr + 1);
	if(a < 5 && chr > maxr[0] && chr > maxc[a]) inwork += calc(a + 1, b, c, d, e, chr + 1);
	if(b < a && chr > maxr[1] && chr > maxc[b]) inwork += calc(a, b + 1, c, d, e, chr + 1);
	if(c < b && chr > maxr[2] && chr > maxc[c]) inwork += calc(a, b, c + 1, d, e, chr + 1);
	if(d < c && chr > maxr[3] && chr > maxc[d]) inwork += calc(a, b, c, d + 1, e, chr + 1);
	if(e < d && chr > maxr[4] && chr > maxc[e]) inwork += calc(a, b, c, d, e + 1, chr + 1);
	return inwork;
}

inline void put(int chr, int r, int c){
	memset(dp, 0, sizeof(dp));
	dp[5][5][5][5][5] = 1; //边界条件
	maxr[r] = maxc[c] = chr; //更新当前行/列最值
	used[chr] = true;
}

int main(){
	freopen("twofive.in", "r", stdin);
	freopen("twofive.out", "w", stdout);
	cin >> ch;
	if(ch == 'N'){
		cin >> n;
		maxc[0] = maxr[0] = -1; //一开始要从'A'开头的字符计算
		for(int i = 0; i < 25; i++){
			bnd[i / 5]++; //当前即将要搜索的列
			int j;
			for(j = 0; j < 25; j++)
				if(!used[j] && j > maxr[i / 5] && j > maxc[i % 5]){
					put(j, i / 5, i % 5);
					ans = calc(bnd[0], bnd[1], bnd[2], bnd[3], bnd[4], 0);
					if(cur + ans >= n) break;
					cur += ans;
					used[j] = false;
				}
			cout << char(j + 'A');
		}
		cout << endl;
	}else{
		cin >> str;
		for(int i = 0; i < 25; i++){
			bnd[i / 5]++; //当前即将要搜索的列
			int j;
			for(j = 0; j < int(str[i] - 'A'); j++) //事实上字母'A'开头不会被计算
				if(!used[j] && j > maxr[i / 5] && j > maxc[i % 5]){
					put(j, i / 5, i % 5);
					ans += calc(bnd[0], bnd[1], bnd[2], bnd[3], bnd[4], 0);
					used[j] = false;
				}
			used[j] = true, maxr[i / 5] = maxc[i % 5] = j; //更新要固定的字符和当前行/列的最值
		}
		cout << ans + 1 << endl;
	}
	return 0;
}
