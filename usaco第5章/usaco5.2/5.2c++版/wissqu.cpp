/*
ID: silentf1
PROG: wissqu
LANG: C++
*/

#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <map>

using namespace std;

map<char, int> MAP;
char Map[5][5];
bool flag, take[5][5];
struct Node{
	char ch;
	int x, y;
}outp[17], temp[17];
long total, pos[][2] = {{0,0}, {0,1}, {1,0}, {1,1}, {-1,1},{1,-1},{0,-1},{-1,0},{-1,-1}};

void print(){
	for(int i = 1; i <= 16; i++)
		cout << outp[i].ch << ' ' << outp[i].x << ' ' << outp[i].y << endl;
	cout << total << endl;
}

inline bool judge(int x, int y, char ch){
	for(int p = 0; p <= 8; p++){
		int xx = x + pos[p][0], yy = y + pos[p][1];
		if(xx < 1 || yy < 1 || xx > 4 || yy > 4) continue;
		if(Map[xx][yy] == ch) return 0;
	}
	return 1;
}

bool Search(int lev){
	if(lev > 16){
		if(!flag){
			flag = 1;
			memcpy(outp, temp, sizeof(outp));
		}
		total += 1;
		return 0;
	}
	char tem;
	if(lev == 1){
		char ch = 'D';
		for(int i = 1; i <= 4; i++)
			for(int j = 1; j <= 4; j++){
				if(judge(i, j, ch) && !take[i][j]){
					MAP[ch]--;
					tem = Map[i][j];
					Map[i][j] = ch;
					if(!flag){
						temp[lev].ch = ch;
						temp[lev].x = i;
						temp[lev].y = j;
					}
					take[i][j] = 1;
					if (Search(lev + 1)) return 1;
					MAP[ch]++;
					Map[i][j] = tem;
					take[i][j] = 0;
				}
		}
	}else{
		for(char ch = 'A'; ch <= 'E'; ch++)
			if(MAP[ch] != 0){	
			for(int i = 1; i <= 4; i++)
				for(int j = 1; j <= 4; j++){
					if(judge(i, j, ch) && !take[i][j]){
						MAP[ch]--;
						tem = Map[i][j];
						Map[i][j] = ch;
						if(!flag){
							temp[lev].ch = ch;
							temp[lev].x = i;
							temp[lev].y = j;
						}
						take[i][j] = 1;
						if (Search(lev + 1)) return 1;
						MAP[ch]++;
						Map[i][j] = tem;
						take[i][j] = 0;
					}
				}
		}
	}

	return 0;
}

int main(){
	freopen("wissqu.in", "r", stdin);
	freopen("wissqu.out", "w", stdout);
	MAP['A'] = MAP['B'] = MAP['C'] = MAP['E'] = 3;
	MAP['D'] = 4;

	for(int i = 1; i <= 4 ; i++)
		for(int j = 1; j <= 4; j++)
			cin >> Map[i][j];

	Search(1);
	print();
	return 0;
}
