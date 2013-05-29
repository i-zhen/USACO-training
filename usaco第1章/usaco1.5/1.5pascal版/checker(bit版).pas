{
ID:sacredf1
PROB:checker
LANG:PASCAL
}
program checker;
var
    n,total,finish:longint;
a:array[1..14] of integer;
b,c,d:array[-13..26] of boolean;
procedure init;
begin
    assign(input,'checker.in');reset(input);
	assign(output,'checker.out');rewrite(output);
    readln(n);
finish:=(1 shl n) -1;//1左移n位再减1等于n个位上置1。
    fillchar(b,sizeof(a),true);
    fillchar(c,sizeof(b),true);
    fillchar(d,sizeof(b),true);
    total:=0;
    close(input);
end;
//求解n皇后问题的一般方法。
procedure dfs(t:integer);
var
    j,i:integer;
begin
for j:=1 to n do
   if b[j] and c[t+j] and d[t-j] then
		begin
			a[t]:=j;
			b[j]:=false;
			c[t+j]:=false;
			d[t-j]:=false;
			if t=n then
				begin
					inc(total);
					for i:=1 to n-1 do
						write(a[i],' ');
					writeln(a[n]);
					if total=3 then exit;//找出三个具体方案后结束。
				end
			else dfs(t+1);
			b[j]:=true;
			c[t+j]:=true;
			d[t-j]:=true;
		end;
end;
//求解n皇后总方案数的位运算方法。
procedure dfsn(upright,biasl,biasr:longint);
//upright有皇后的列，biasl左下对角线对应列，biasr右下对角线对应列。
var
      pos,p:longint;
begin

{ 1}  if upright <>finish then
{ 2}  begin
{ 3}     pos:=finish and not (upright or biasl or biasr);
{ 4}     while pos<>0 do
{ 5}     begin
{ 6}        p:=pos and -pos;
{ 7}        pos:=pos-p;
{ 8}        dfsn(upright +p,( biasl +p)shl 1,( biasr +p)shr 1);
{ 9}     end;
{10}  end
{11}  else inc(total);
end;
begin
    init;   
    dfs(1);
    total:=0;
    dfsn(0,0,0);
    writeln(total);
    close(output);
end.

