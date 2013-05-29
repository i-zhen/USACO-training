{
ID: sacredf1
PROG: milk
LANG: PASCAL
}
program milk;
var n,m,total:longint;
	mi,mi2:array[1..5000]of longint;
procedure init;
var i:longint;
begin
	total:=0;
	readln(n,m);
	for i:=1 to m do
		readln(mi[i],mi2[i]);
end;
procedure qsort(l,r:longint);
var i,j,x,y:longint;
begin
	  i:=l;j:=r;
	x:=mi[(l+r)div 2];
	repeat
		while mi[i]<x do inc(i);
		while x<mi[j] do dec(j);
	    if i<=j then
		begin
			y:=mi[i];
			mi[i]:=mi[j];
			mi[j]:=y;
			y:=mi2[i];
			mi2[i]:=mi2[j];
			mi2[j]:=y;
			inc(i);
		    dec(j);
		end;
	until i>j;
	if i<r then qsort(i,r);
	if l<j then qsort(l,j);
end;
procedure main;
var i,temp:longint;
	flag:boolean;
begin
	temp:=0;
	qsort(1,m);
	for i:=1 to m do
	begin
		if ((temp+mi2[i])>n)and(temp<n) then 
			begin total:=total+(n-temp)*mi[i];writeln(total);close(output);halt;end
				else if temp=n then begin writeln(total);close(output);halt;end;
		if 	(temp+mi2[i])<=n then begin
			temp:=temp+mi2[i];
			total:=total+mi[i]*mi2[i];
		end;
	end;
	writeln(total);
end;
begin
  assign(input,'milk.in');
  reset(input);
  assign(output,'milk.out');
  rewrite(output);
  init;
  main;
  close(input);
  close(output);
end.