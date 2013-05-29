{
PROG: beads
LANG: PASCAL
}
{题解 - beads
分析
这道题用标准的搜索是O(n^2)的，可以用类似动态规划的方法优化到O(n)。
用数组bl,br,rl,rr分别记录在项链i处向左向右收集的篮色红色珠子数。
项链是环形的，但我们只要把两个同样的项链放在一块，就把它转换成线性的了。
我们只要求出bl,br,rl,rr，那么结果就是max(max(bl[i],rl[i])+max(br[i+1],rr[i+1])) (0<=i<=2*n-1)。
我们以求bl,rl为例:
初始时bl[0]=rl[0]=0
我们从左往右计算
如果necklace[i]='r',rl[i]=rl[i-1]+1,bl[i]=0；
如果necklace[i]='b', bl[i]=bl[i-1]+1,rl[i]=0；
如果necklace[i]='w',bl[i]=bl[i-1]+1,rl[i]=rl[i-1]+1。
同理可以求出br,rr。
}
program beads;
type node=record
	ch:char;
	up,down:integer;
	end;
var 
	pos:array[1..10000]of node;
	n,total:longint;
procedure init;
var i,j:integer;
begin
    for i:=1 to n do
    begin
		read(pos[i].ch);
		if i=1 then pos[i].up:=n else pos[i].up:=i-1;
		if i=n then pos[i].down:=1 else pos[i].down:=i+1;
	end;
end;
procedure main;
var 
		i,tr,tb,k,temp,zq:integer;
begin
	total:=-1;
	 for i:=1 to n do
	 begin
         tr:=0;tb:=0;
		 k:=i;zq:=0;{用于记录周期防止无限循环}
		 while true do
	     begin
			 if zq>n-1 then break;
			 if (pos[k].ch='w') or (pos[k].ch='r') then inc(tr) else break;inc(zq);
				 
			k:=pos[k].down;
		 end;
		k:=i;
	     while true do
	     begin
			  if zq>n-1 then break;
			 if (pos[k].ch='w') or (pos[k].ch='b') then inc(tb) else break;inc(zq);
				
				 k:=pos[k].down;
		 end;
			 if tr>tb then temp:=tr else temp:=tb;
		tr:=0;tb:=0;
		k:=i-1;
		 while true do
	     begin
			  if zq>n-1 then break;
			 if (pos[k].ch='w') or (pos[k].ch='r') then inc(tr) else break;inc(zq);
				
			k:=pos[k].up;
		end;
		k:=i-1;
	     while true do
	     begin
			  if zq>n-1 then break;
			 if (pos[k].ch='w') or (pos[k].ch='b') then inc(tb) else break;inc(zq);
				
				 k:=pos[k].up;
		end;
			 if tr>tb then temp:=tr+temp else temp:=tb+temp;
			if temp>total then total:=temp;
		end;
end;
begin
  assign(input,'beads.in');
  reset(input);
  assign(output,'beads.out');
  rewrite(output);
  readln(n);
  init;
  main;
  writeln(total);
  close(input);
  close(output);
end.