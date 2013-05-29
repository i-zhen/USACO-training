/*
ID: silentf1
PROG: window
LANG: C++
*/
#include <iostream>
#include <cctype>
#include <cstring>
#include <string>
#include <iomanip>
#include <cstdio>
#include <map>
#include <cmath>
#include <list>

#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a < b ? a : b)

using namespace std;

struct Node{
	Node(int x, int y, int X, int Y):x1(x), y1(y), x2(X), y2(Y){
		tarea = abs(x1 - x2) * abs(y1 - y2);
	};
	int x1, y1, x2, y2;
	double tarea;
};
map<char, Node *> window;
string cmd;
list<char> que;
double ans;

inline void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

int CutRect(list<char>::iterator i, int x1, int y1, int x2, int y2){ //矩形切割
	if(++i == que.begin() || x1 == x2 || y1 == y2) return (x2 - x1) * (y2 - y1);
	int a1 = window[*(--i)]->x1, a2 = window[*i]->x2, b1 = window[*i]->y1, b2 = window[*i]->y2, tot;
	if(!((a1 >= x2) || (a2 <= x1) || (b1 >= y2) || (b2 <= y1))){ //存在交集判断：去掉没有交集的,剩下的就是有交集的
		tot =  CutRect(--i, x1, y1, MIN(a2, x2), MAX(y1, b1)), ++i;
		tot += CutRect(--i, x1, MAX(y1, b1), MAX(x1, a1), y2), ++i;
		tot += CutRect(--i, MAX(x1, a1), MIN(b2, y2), x2, y2), ++i;
		tot += CutRect(--i, MIN(a2, x2), y1, x2, MIN(y2, b2)), ++i;
		return tot;
	}else return CutRect(--i, x1, y1, x2, y2);
}

int main(){
	freopen("window.in", "r", stdin);
	freopen("window.out", "w", stdout);
	while(cin >> cmd){
		if(cmd[0] == 'w'){	//创建窗体，初始时自动置顶；
			int x[] = {0,0,0,0}, t = 0, i, j;
			for(i = 1; i < cmd.size(); i++)
				if(cmd[i] == ','){
					for(j = i + 1; isdigit(cmd[j]); j++)
						x[t] = x[t] * 10 + (cmd[j] - '0');
					i = j - 1, t++;
				}
			if(x[0] > x[2]) swap(x[0], x[2]);
			if(x[1] > x[3]) swap(x[1], x[3]);
			Node *win = new Node(x[0], x[1], x[2], x[3]);
			window[cmd[2]] = win;
			que.push_front(cmd[2]); //插入到队列的头部
		}else if(cmd[0] == 't'){ //置顶窗体
			for(list<char>::iterator i = que.begin(); i != que.end(); i++)
				if((*i) == cmd[2]){
					que.erase(i);
					que.push_front(cmd[2]);
					break;
				}
		}else if(cmd[0] == 'b'){ //置底窗体
			for(list<char>::iterator i = que.begin(); i != que.end(); i++)
				if((*i) == cmd[2]){
					que.erase(i);
					que.push_back(cmd[2]);
					break;
				}
		}else if(cmd[0] == 'd'){ //删除窗体
			for(list<char>::iterator i = que.begin(); i != que.end(); i++)
				if((*i) == cmd[2]){
					que.erase(i);
					window.erase(cmd[2]);
					break;
				}
		}else{ 			//计算窗体
			for(list<char>::iterator i = que.begin(); i != que.end(); i++)
				if((*i) == cmd[2]){
					Node* nd = window[cmd[2]];
					if(i != que.begin())
						ans = CutRect(--i, nd->x1, nd->y1, nd->x2, nd->y2) / nd->tarea;
					else ans = 1.0;
					break;
				}
			cout.precision(3);
			cout.setf(ios::fixed);
			cout << ans * 100.0 << endl;
		}
	}
	return 0;
}
