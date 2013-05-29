{
ID: sacredf1
PROG: subset
LANG: PASCAL
}
program test;
var n:longint;
	k:array[0..39,-39..1000]of longint;
procedure main;
var i,x:integer;
begin
	for i:=0 to n do
		k[i,0]:=1;
	for i:=1 to n do
		for x:=1 to n*(n+1)div 2 do
			k[i,x]:=k[i-1,x]+k[i-1,x-i];
	writeln(k[n-1,((n+1)*n div 4)-n]);
end;
procedure init;
var i:integer;
begin
	fillchar(k,sizeof(k),0);
	readln(n);
	if odd(n*(n+1) div 2) then writeln('0')
		else main;
end;
begin
  assign(input,'subset.in');
  reset(input);
  assign(output,'subset.out');
  rewrite(output);
  init;
  close(input);
  close(output);
end.