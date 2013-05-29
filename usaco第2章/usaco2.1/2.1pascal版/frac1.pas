{
ID: sacredf1
PROG: frac1
LANG: PASCAL
}
program frac1;
var n:integer;
	t:cardinal;
	bx:array[1..100000]of longint;
	ass:array[1..100000,1..2] of longint;
procedure qsort(l,r:longint);
var i,j,y:longint;
	x:real;
begin
	  i:=l;j:=r;
	x:=bx[(l+r)div 2];
	repeat
		while bx[i]<x do inc(i);
		while bx[j]>x do dec(j);
	    if i<=j then
		begin
			y:=ass[i,1];
			ass[i,1]:=ass[j,1];
			ass[j,1]:=y;
			y:=ass[i,2];
			ass[i,2]:=ass[j,2];
			ass[j,2]:=y;
			y:=bx[i];
			bx[i]:=bx[j];
			bx[j]:=y;
			inc(i);
		    dec(j);
		end;
	until i>j;
	if i<r then qsort(i,r);
	if l<j then qsort(l,j);
end;
procedure main;
var i,j,a,b,c,d:integer;
begin
	for i:=2 to n do
		for j:=1 to  n-1 do
		if j<i then
		begin
				a:=j;b:=i;
				for c:=1 to a do 
					if (b mod c=0)and(a mod c=0) then d:=c; 
				if d=1 then 
				begin 
					inc(t);
					ass[t,1]:=j;
					ass[t,2]:=i;
				end;
		end;
		for i:=1 to t do
			bx[i]:=trunc(ass[i,1]/ass[i,2]*100000);//这里是把分数放大,10000不够,因为最小的1/160与1/159比不出来.
		if t<>0 then qsort(1,t);
		for i:=1 to t do
			writeln(ass[i,1],'/',ass[i,2]);
end;
procedure init;
begin
	readln(n);
	writeln('0/1');
	t:=0;
	main;
end;
begin
  assign(input,'frac1.in');
  reset(input);
  assign(output,'frac1.out');
  rewrite(output);
  init;
  writeln('1/1');
  close(input);
  close(output);
end.