/*
ID: silentf1
TASK: latin
LANG: C++
*/

#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>

using namespace std;

typedef long long INT64;

int n, tot[8], mat[8], qun;
INT64 jc[] = {0, 1, 2, 6, 24, 120, 720, 5040}, total;
bool col[8][8], row[8][8], f[8];	//表示第n行(列)的数字m有无被占用。

inline int find_qun(){
	int id = 2, lar, t;
	memset(f, 0, sizeof(f));
	for(int i = 1;  i <= n; i++){
		if(!f[i]){
			lar = 0, t = i;
			do{
				f[t] = true, lar++, t = mat[t];
			}while(!f[t]);
			if(lar > id) id = lar;
		}
		if (id >= ((n + 1) / 2)) return id;
	}
	return id;
}

void solve(int r, int c){
	if((r == n) && (c == 2))
		++tot[qun], ++total;
	for(int j = 1; j <= n; j++)
		if(!col[c][j] && !row[r][j]){
			col[c][j] = row[r][j] = true;
			if(r == 2) mat[c] = j;
			if(c == n){
				if(r == 2) qun = find_qun();
				if(r == 2 && tot[qun]) total += tot[qun];
				else solve(r + 1, 2);
			}
			else
				solve(r, c + 1);
			col[c][j] = row[r][j] = false;
		}	
}

int main(){
	freopen("latin.in", "r", stdin);
	freopen("latin.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
		col[i][i] = row[i][i] = true;
	mat[1] = 2;
	solve(2, 2);
	cout << total * jc[n - 1] << endl;
	return 0;
}
