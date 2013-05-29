{
ID: sacredf1
PROG: milk2
LANG: PASCAL
{
  做这题,花了不少时间.
  起初是用模拟法做的,一个也没过!??后来想到了区间树,可是太麻烦,于是
  就想去记录区间,也就是离散化法,但是怕时间复杂度过高,就没有使用排序
  只过了两个???!!最后参考了一下题解,证明我的想法没错,但方式有误,改正后
  成功了.
}
program milk2;
var n:longint;
	a:array[1..5000,1..2]of longint;
	l,r: longint;
procedure init;
var i:longint;
begin
	readln(n);
    for i:=1 to n do
	begin
		readln(a[i,1],a[i,2]);
	end;
end;
procedure main;
var i:longint;
	you,no:longint;
begin
	
    l:=a[1,1];r:=a[1,2];
    you:=r-l;no:=0;
	for i:=2 to n do
    begin
	  if (a[i,1]>=l)and(a[i,1]<=r) then 
		 if a[i,2]>r then r:=a[i,2];
	  if a[i,1]>r then 
		  begin
			  if (r-l)>you then you:=r-l;
			  if (a[i,1]-r)>no then no:=a[i,1]-r;
			  l:=a[i,1];
			  r:=a[i,2];
		  end;
	end;
	writeln(you,' ',no);
end;
procedure qsort(l,r:longint);
var i,j,x,y:longint;
begin
	  i:=l;j:=r;
	x:=a[(l+r)div 2,1];
	repeat
		while a[i,1]<x do inc(i);
		while x<a[j,1] do dec(j);
	    if i<=j then
		begin
			y:=a[i,1];
			a[i,1]:=a[j,1];
			a[j,1]:=y;
			y:=a[i,2];
			a[i,2]:=a[j,2];
			a[j,2]:=y;
			inc(i);
		    dec(j);
		end;
	until i>j;
	if i<r then qsort(i,r);
	if l<j then qsort(l,j);
end;
begin
  assign(input,'milk2.in');
  reset(input);
  assign(output,'milk2.out');
  rewrite(output);
  init;
  qsort(1,n);
  main;
  close(input);
  close(output);
end.