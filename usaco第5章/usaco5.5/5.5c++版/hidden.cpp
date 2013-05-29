/*
ID: silentf1
TASK: hidden
LANG: C++
*/
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
char str[200005];
int n, k, i = 1, j = 2;

int main(){
	freopen("hidden.in", "r", stdin);
	freopen("hidden.out", "w", stdout);
	scanf("%d", &n), getchar();
	for(int i = 1; i <= n; i++){
		str[i] = str[i + n] = getchar();
		if(str[i] < 'a' || str[i] > 'z') --i;
	}
	for(; j <= n ;){
		int cnt = -1, big = 0;
		for(int k = 0; k <= n; k++){
			if(cnt != -1 && big != 0) break;
			if(str[i + k] != str[j + k])
				cnt = k;
			if(str[i + k] > str[j + k]) big = 1;
			else if(str[i + k] < str[j + k]) big = 2;
		}
		if(cnt == -1) break;
		if(big == 1) i = j++;
		else j += (cnt == 0 ? 1 : cnt);
	}
	cout << i - 1 << endl;
	return  0;
}
