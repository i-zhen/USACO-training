{
ID: sacredf1
PROG: concom
LANG: PASCAL
}
{最后数据未通过}
program test;
type node=record
		next:integer;
		jie:array[1..100]of integer;
		jdata:array[1..100]of integer;
		flag:array[1..100]of boolean;
		end;
var n:integer;
	max:integer;
	temp:array[1..100]of integer;
	a:array[1..100]of node;
	b:array[1..100]of boolean;
procedure dfs1(x,y:integer);
var i,j:integer;
begin
	if b[x]=false then exit;
	b[x]:=false;
	if x<>y then
	begin
		for i:=1 to a[x].next do
			if (a[x].jie[i]=y) then
				begin a[x].flag[a[x].jie[i]]:=true; end; 
			for i:=1 to a[x].next do
			begin
				for j:=1 to a[y].next do
					if (a[y].jie[j]=a[x].jie[i])and(not a[x].flag[i]) then 
					begin
						a[y].jdata[j]:=a[x].jdata[i]+a[y].jdata[j];
						a[x].flag[i]:=true;
					end;
			end;
			for i:=1 to a[x].next do
				if (not a[x].flag[i])and(a[x].jie[i]<>y)then 
				begin
					inc(a[y].next);
					a[y].jie[a[y].next]:=a[x].jie[i];
					a[y].jdata[a[y].next]:=a[x].jdata[i];
				end;
	end;
	for i:=1 to a[x].next do
	begin
		if (a[x].jie[i]<>y)and b[a[x].jie[i]] and (a[x].jdata[i]>50)
			then 
			begin 
				dfs1(a[x].jie[i],y);
			end;
	end;
end;
procedure qsort(l,r:longint);
var i,j,x,y:longint;
begin
	i:=l;
	j:=r;
	x:=temp[(i+j) shr 1];
	repeat
		while temp[i]<x do inc(i);
		while x<temp[j] do dec(j);
		if i<=j then
		begin
			y:=temp[i];
			temp[i]:=temp[j];
			temp[j]:=y;
			inc(i);
			dec(j);
		end;
	until i>j;
	if l<j then qsort(l,j);
	if i<r then qsort(i,r);
end;
procedure init;
var x,i,j,p,y:integer;
begin
	readln(n);
    max:=0;i:=0;j:=0;p:=0;
	for x:=1 to n do
	begin
		readln(i,j,p);
		inc(a[i].next);
		a[i].jie[a[i].next]:=j;
		a[i].jdata[a[i].next]:=p;
	    if i>max then max:=i;
	end;
	for i:=1 to max do
	begin
		for j:=1 to max do
			fillchar(a[j].flag,sizeof(a[j].flag),false);
		fillchar(b,sizeof(b),true);
		dfs1(i,i);
	end;
	for i:=1 to max do
	begin
		y:=0;
		for j:=1 to a[i].next do
			if (a[i].jdata[j]>50)and(i<>a[i].jie[j]) then 
				begin 
					inc(y);
					temp[y]:=a[i].jie[j];
				end;
		if y>1 then qsort(1,y);
		for j:=1 to y do
			writeln(i,' ',temp[j]);
	end;
end;
begin
  assign(input,'concom.in');
  reset(input);
  assign(output,'concom.out');
  rewrite(output);
  init;
  close(input);
  close(output);
end.