/*
ID: silentf1
TASK: picture
LANG: C++
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define MAX(a, b) (a > b ? a : b)
#define recv recvh
#define rech recvh

using namespace std;

struct Node{
	long lch, rch, l, r, clr, mid, all, tot;  //clr表示当前颜色,all表示整体的颜色
	bool mark;	//mark是True时杂色，False则纯色。
}tree[40005];
struct rectVH{
	int s, t, vh, start;
	bool operator < (const rectVH &cmp)const {
		if(vh == cmp.vh) return cmp.start < start;
                return vh < cmp.vh;
        }	
}recvh[20005];
long tot = 1, n, ans;

class regtree{
	public:
		void build(long left, long right, long index){
			tree[index].l = left;
			tree[index].r = right;
			tree[index].mid = (left + right) / 2;
			tree[index].all = right - left + 1;
			tree[index].mark = tree[index].clr = tree[index].tot = 0;
			if(left < right){
				tree[index].lch = ++tot;
				build(left, tree[index].mid, tot);
				tree[index].rch = ++tot;
				build(tree[index].mid + 1, right, tot);
			}
		}

		void insert(long left, long right, long index, int delta){
			if(tree[index].l >= left && tree[index].r <= right) 
				if(!tree[index].mark){	//lazy
					tree[index].clr += delta;
					if(tree[index].clr == 1 && delta > 0) ans += tree[index].all;
					if(tree[index].clr == 0 && delta < 0) ans += tree[index].all;
					return;
				}
			if(!tree[index].mark && tree[index].all != 1){	//下放
				tree[tree[index].lch].clr = tree[index].clr, tree[tree[index].lch].mark = false;
				tree[tree[index].rch].clr = tree[index].clr, tree[tree[index].rch].mark = false;
			}
			if(tree[index].all == 1) return; //不递归叶子结点
			if(left <= tree[index].mid && tree[index].lch != 0) insert(left, right, tree[index].lch, delta); 
			if(right > tree[index].mid && tree[index].rch != 0) insert(left, right, tree[index].rch, delta);
			tree[index].mark = true;	//先归为杂色，因为递归后有可能是杂色
			if(!tree[tree[index].lch].mark && !tree[tree[index].rch].mark && 
				(tree[tree[index].lch].clr == tree[tree[index].rch].clr)) //恢复统一色，如果可能
				tree[index].mark = false, tree[index].clr = tree[tree[index].lch].clr;
		}
}line;

int main(){
	freopen("picture.in", "r", stdin);
	freopen("picture.out", "w", stdout);
	tree[0].mark = false;	//边界条件	
	cin >> n;
	int N2 = n * 2, N3 = n * 3;
	for(int i = 1; i <= n; i++){
		int lx, ly, rx, ry;
		scanf("%d%d%d%d", &lx, &ly, &rx, &ry);
		lx += 10000, ly += 10000, rx += 10000, ry += 10000;
		recv[i].s = ly, recv[i].t = ry - 1, recv[i].vh = lx, recv[i].start = true;
		recv[i + n].s = ly, recv[i + n].t = ry - 1, recv[i + n].vh = rx, recv[i + n].start = false;
		rech[i + N2].s = lx, rech[i + N2].t = rx - 1, rech[i + N2].vh = ly, rech[i + N2].start = true;
		rech[i + N3].s = lx, rech[i + N3].t = rx - 1, rech[i + N3].vh = ry, rech[i + N3].start = false;
	}
	sort(recvh + 1, recvh + N2 + 1);
	sort(recvh + N2 + 1, recvh + n + N3 + 1);
	tot = 1, line.build(0, 20000, 1);	//纵向的边
	for(int i = 1; i <= N2; i++)
		line.insert(recvh[i].s, recvh[i].t, 1, (recvh[i].start ? 1 : -1));
	memset(tree, 0, sizeof(tree));
	tot = 1, line.build(0, 20000, 1);	//横向的边
	for(int i = N2 + 1; i <= N3 + n; i++)
		line.insert(recvh[i].s, recvh[i].t, 1, (recvh[i].start ? 1 : -1));
	cout << ans << endl;
	return 0;
}
