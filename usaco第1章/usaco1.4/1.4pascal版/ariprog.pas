{
ID: silentf1
PROG: ariprog
LANG: PASCAL
}
program test;
type node=array[1..50000]of cardinal;
var total,n,m,t2,t:integer;
	p:array[1..12500]of boolean;
	a,b,q2:node;
procedure qsort(l,r:integer;var c,d:node);
var i,j,x,y:cardinal;
begin
	i:=l;j:=r;
	x:=c[(i+j)div 2];
	repeat
		while c[i]<x do inc(i);
		while x<c[j] do dec(j);
		if i<=j then
		begin
			y:=c[i];
			c[i]:=c[j];
			c[j]:=y;
			y:=d[i];
			d[i]:=d[j];
			d[j]:=y;
			inc(i);
			dec(j);
		end;
	until i>j;
	if i<r then qsort(i,r,c,d);
	if l<j then qsort(l,j,c,d);
end;
procedure main;
var i,i1,j,max,gongcha:cardinal;
	 pd2:boolean;
begin
	total:=0;
	max:=2*(m*m);
    for i:=1 to t2 do
	begin
		gongcha:=(max-q2[i])div(n-1);//构造公差
	    for i1:=1 to gongcha do
		begin 
			pd2:=true; 
			for j:=n-1 downto 1 do
		        if not p[q2[i]+i1*j] then begin pd2:=false;break;end;{这个部分我原来是使用函数编写的,
																							   虽然方便但会超时,所以在编程中应该
																							   慎用函数,越是整合的程序越省时间}
			if pd2 then
			begin
				inc(total);
				a[total]:=q2[i];
				b[total]:=i1;
			end;
		end;
	end;
end;
procedure init;
var j,k:integer;
		l:node;
begin
	t:=0;
	readln(n,m);
	fillchar(p,sizeof(p),false);
    for j:=0 to m do
	   for k:=0 to j do
		IF  p[j*j+k*k]<>true then
		begin
		  inc(t);
		  q2[t]:=j*j+k*k;
		  p[q2[t]]:=true;
		end;{先把数字构造出来,再用boolean数组记录,这样在判断时,时间复杂度将为O(1)}
	qsort(1,t,q2,l);
	t2:=t;
end;
procedure pout;
var i,h,t:integer;
begin
	h:=1;t:=1;b[total+1]:=maxint;
	if (total>0)and(total<>1) then 
		begin 
			qsort(1,total,b,a);
			for i:=1 to total do
			    if b[i]=b[i+1] then inc(t) else
				begin
					if (t-h)>0 then qsort(h,t,a,b);
					inc(t);
					h:=t;
					end;//排序这个地方没有好好考虑,写的比较复杂,是用指针记录分布的数列的
		end;
	if total=0 then writeln('NONE')
	else
	for i:=1 to total do
		writeln(a[i],' ',b[i]);
end;
begin
  assign(input,'ariprog.in');
  reset(input);
  assign(output,'ariprog.out');
  rewrite(output);
  init;
  main;
  pout;
  close(input);
  close(output);
end.