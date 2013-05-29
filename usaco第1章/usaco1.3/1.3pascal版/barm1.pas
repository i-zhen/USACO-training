{
ID: sacredf1
PROG: barn1
LANG: PASCAL
}
program test;
var m,s,c,total:integer;
	a,b:array[1..200] of integer;
procedure qsort2(l,r:longint);
var i,j,x,y:longint;
begin
	i:=l;j:=r;
	x:=a[(l+r)div 2];
	repeat
		while a[i]<x do inc(i);
		while x<a[j] do dec(j);
	    if i<=j then
		begin
			y:=a[i];
			a[i]:=a[j];
			a[j]:=y;
			inc(i);
		    dec(j);
		end;
	until i>j;
	if i<r then qsort2(i,r);
	if l<j then qsort2(l,j);
end;
procedure init;
var i:integer;
begin
	readln(m,s,c);
	for i:=1 to c do
		readln(a[i]);
    qsort2(1,c);
	total:=a[c]-a[1]+1;
end;
procedure qsort(l,r:longint);
var i,j,x,y:longint;
begin
	i:=l;j:=r;
	x:=b[(l+r)div 2];
	repeat
		while b[i]<x do inc(i);
		while x<b[j] do dec(j);
	    if i<=j then
		begin
			y:=b[i];
			b[i]:=b[j];
			b[j]:=y;
			inc(i);
		    dec(j);
		end;
	until i>j;
	if i<r then qsort(i,r);
	if l<j then qsort(l,j);
end;
procedure main;
var i:integer;
begin
	for i:=1 to c-1 do
	begin
        b[i]:=a[i+1]-a[i]-1;	
	end;
	qsort(1,c-1);
	for i:=c-1 downto c-m+1 do
	begin
		total:=total-b[i];
	end;
	writeln(total);
end;
begin
  assign(input,'barn1.in');
  reset(input);
  assign(output,'barn1.out');
  rewrite(output);
  init;
  main;
  close(input);
  close(output);
end.