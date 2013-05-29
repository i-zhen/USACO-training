{
ID: sacredf1
PROG: numtri
LANG: PASCAL
}
program test;
var a:array[0..1000,0..1000]of longint;
	n:integer;
procedure init;
var i,j:integer;
begin
	readln(n);
	fillchar(a,sizeof(a),0);
	for i:=1 to n do
	begin
		for j:=1 to i do
			read(a[i,j]);
		readln;
	end;
	
end;
procedure main;
var i,j:integer;
	max:longint;
begin
	for i:=2 to n do
		for j:=1 to i do
		begin
			if a[i-1,j]>a[i-1,j-1] then a[i,j]:=a[i,j]+a[i-1,j] else a[i,j]:=a[i,j]+a[i-1,j-1];
		end;
	max:=-1;
	for i:=1 to n do
		if a[n,i]>max then max:=a[n,i];
	writeln(max);
end;
begin
  assign(input,'numtri.in');
  reset(input);
  assign(output,'numtri.out');
  rewrite(output);
  init;
  main;
  close(input);
  close(output);
end.