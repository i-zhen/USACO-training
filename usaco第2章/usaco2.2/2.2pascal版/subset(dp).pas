{
ID: sacredf1
PROG: subset
LANG: PASCAL
}
program test;
var n:longint;
	k:array[0..39,0..10000]of int64;
procedure main;
var i,j:longint;
begin
	k[0,0]:=1;
	for i:=1 to n do
		for j:=0 to n*(n+1)div 4 do
			if j-i>=0 then
				k[i,j]:=k[i-1,j]+k[i-1,j-i]
			else
				k[i,j]:=k[i-1,j];
	writeln(k[n,((n+1)*n div 4)] div 2);
end;
procedure init;
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