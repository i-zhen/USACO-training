{
ID: sacredf1
PROG: money
LANG: PASCAL
}
program money;
var v,n,i,j,k:integer;
	a:array[0..10000]of int64;
begin
  assign(input,'money.in');
  reset(input);
  assign(output,'money.out');
  rewrite(output);
  readln(v,n);
  a[0]:=1;
  for i:=1 to v do
  begin
	read(k);
	for j:=k to n do
		a[j]:=a[j]+a[j-k];
  end;
  writeln(a[n]);
  close(input);
  close(output);
end.