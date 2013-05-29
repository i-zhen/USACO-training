/*
ID: silentf1
PROG: charrec
LANG: C++
*/

#include <iostream>
#include <cstring>
#include <cstdio>
#include <climits>

using namespace std;

const char letter[] = " abcdefghijklmnopqrstuvwxyz";
char	font[28][21][21], data[1201][21], ans[100];	//下面dif的意义是第i个字符,第j行与测试数据第p行的不同个数
int	dif[28][21][1201], cost[1201][4];		//cost[][1..2..3]分别表示连续匹配19，20，21行的最小匹配量
int 	dp[1201][2], n, temp, p, ansl[1201][4];		//ansl记录cost选择长度和字母时的匹配方案,dp保存最优值和当前方案选择

int main(){
	freopen("font.in", "r", stdin);
	scanf("%d", &n), getchar();
	for(int i = 1; i <= 27; i++)
		for(int j = 1; j <= 20; j++, getchar())
			for(int k = 1; k <= 20; k++)
				font[i][j][k] = getchar();
	
	freopen("charrec.in", "r", stdin);
	freopen("charrec.out", "w", stdout);
	scanf("%d", &n), getchar();
	for(int i = 1; i <= n; i++, getchar())
		for(int j = 1; j <= 20; j++)
			data[i][j] = getchar();

	//init dif
	for(int i = 1; i <= 27; i++)
		for(int j = 1; j <= 20; j++)
			for(int k = 1; k <= n; k++)
				for(int p = 1; p <= 20; p++)
					dif[i][j][k] += int(data[k][p] != font[i][j][p]);
	
	//init cost
	for(int i = 1; i <= n; i++){
		cost[i][1] = cost[i][2] = cost[i][3] = INT_MAX;
		for(int j = 1; j <= 27; j++){		//枚举字符
			if(i + 18 <= n){		//少一行
				for(p = 2, temp = 0; p <= 20; p++) temp += dif[j][p][i + p - 2]; //先计算刚好19行的总和
				if(temp < cost[i][1]) cost[i][1] = temp, ansl[i][1] = j;
				for(p = 2; p <= 20; p++){	//枚举删除的一行
					temp += dif[j][p - 1][i + p - 2], temp -= dif[j][p][i + p - 2];
					if(temp < cost[i][1]) cost[i][1] = temp, ansl[i][1] = j;
				}
			}
			if(i + 19 <= n){		//刚好20行
				for(p = 1, temp = 0; p <= 20; p++) temp += dif[j][p][i + p - 1]; //先计算刚好20行的总和
				if(temp < cost[i][2]) cost[i][2] = temp, ansl[i][2] = j;
			}
			if(i + 20 <= n){		//多一行
				for(p = 2, temp = dif[j][1][i]; p <= 20; p++) temp += dif[j][p][i + p]; //先计算刚好21行的总和
				if(temp < cost[i][3]) cost[i][3] = temp, ansl[i][3] = j;
				for(p = 2; p <= 20; p++){	//枚举多出来的一行,多出来的不用计算到差异值之中
					temp += dif[j][p][i + p - 1], temp -= dif[j][p][i + p];
					if(temp < cost[i][3]) cost[i][3] = temp, ansl[i][3] = j;
				}
			}
		}
	}
	//dp
	for (dp[0][0] = 0, p = 1; p <= n; p++) dp[p][0] = INT_MAX;
	for(int i = 19; i <= n; i++){	//判断dp[i] < INT_MAX避免越界结果为负
		if(i - 19 >= 0 && dp[i - 19][0] < INT_MAX && dp[i - 19][0] + cost[i - 18][1] < dp[i][0])
			dp[i][0] = dp[i - 19][0] + cost[i - 18][1], dp[i][1] = 19;
		if(i - 20 >= 0 && dp[i - 20][0] < INT_MAX && dp[i - 20][0] + cost[i - 19][2] < dp[i][0])
			dp[i][0] = dp[i - 20][0] + cost[i - 19][2], dp[i][1] = 20;
		if(i - 21 >= 0 && dp[i - 21][0] < INT_MAX && dp[i - 21][0] + cost[i - 20][3] < dp[i][0])
			dp[i][0] = dp[i - 21][0] + cost[i - 20][3], dp[i][1] = 21;
	}

	for(p = n, temp = 0; p; p -= dp[p][1])
		ans[++temp] = ansl[p - dp[p][1] + 1][dp[p][1] - 18];	
	for(int i = temp; i >= 1; i--)
		cout << letter[ans[i] - 1];
	cout << endl;
	return 0;
}
