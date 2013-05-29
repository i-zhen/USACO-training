{
ID: sacredf1
PROG: holstein
LANG: PASCAL
}
program holstein;
type node=array[1..25]of boolean;
		node2=array[1..25]of integer;
var v,g,sum,t2:integer;
	a,t:array[1..25]of integer;
	b:array[1..15,1..25]of integer;
	ans:array[1..100] of longint;
	path,sol:array[1..100] of longint;
	p:array[1..15] of boolean;
function jc(k:integer):boolean;
var i:integer;
begin
	for i:=1 to v do
		if t[i]-b[k,i]<a[i] then exit(false);
	exit(true);
end;
function check:boolean;
var i:longint;
begin
	for i:=1 to v do if a[i]>ans[i] then exit(false);
	exit(true);
end;
procedure go(i:longint);
var j,k:longint;
begin
	p[i]:=true;//记录被选上的结点
	for k:=1 to v do inc(ans[k],b[i,k]);
	if check then begin//判断是否有解并且记录最值
		t2:=0;
		for j:=1 to g do
		if p[j] then begin
			inc(t2);
			path[t2]:=j;
		end;
		if t2<sum then begin
			sum:=t2;
			sol:=path;
		end;
	end;
	if i<g then go(i+1);//包含当前结点dfs
	for k:=1 to v do dec(ans[k],b[i,k]);//回溯
	p[i]:=false;//回溯
	if i<g then go(i+1);//不包含当前结点,继续dfs
end;
procedure main;
var i:integer;
begin
	fillchar(t,sizeof(t),0);
	sum:=maxint;
	go(1);
	write(sum,' ');
	for i:=1 to sum-1 do write(sol[i],' ');
	writeln(sol[sum]);
end;
procedure init;
var i,j:integer;		
begin
	fillchar(p,sizeof(p),false);
	readln(v);
	for i:=1 to v do
		read(a[i]);
	readln(g);
	for i:=1 to g do
	begin
		for j:=1 to v do
			read(b[i,j]);
		readln;
	end;
end;
begin
  assign(input,'holstein.in');
  reset(input);
  assign(output,'holstein.out');
  rewrite(output);
  init;
  main;
  close(input);
  close(output);
end.