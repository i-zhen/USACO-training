{
ID: sacredf1
PROG: lamps
LANG: PASCAL

其实这道题的模块分析清除后,以及在判重部分考虑好,并分析好状态,即使对1到6号灯不优化都能很快通过.
}
program test;
var on1,off1,la:array[1..100]of integer;	
	a:array[1..100,1..1000]of integer;
	n,c,total,s:integer;
procedure swap(x,y:integer);
var i,t:integer;
begin
  for i:= 1 to n do
   begin
	t:=a[x,i];
	a[x,i]:= a[y,i];
	a[y,i]:=t;
   end;
end;
procedure sort;//冒泡
var
  i,j,k,p : longint;
begin
  for i := 1 to s-1 do
    begin
      p := i;
      for j := i+1 to s do
        begin
          for k := 1 to n do
            if a[p,k] <> a[j,k] then
              begin
                if a[p,k] > a[j,k] then p := j;
                break;
              end;
        end;
      swap(i,p);
    end;
	
end;
function check:boolean;
var i:integer;
begin
	for i:=1 to n do
	begin
		if (on1[i] = 1) and (la[i]<>1) then
			exit(false);
		if (off1[i] = 1) and (la[i]<>0) then
			exit(false);
	end;
	exit(true);
end;
procedure an(x:integer);
var i:integer;
begin
	case x of
	1:for i:=1 to n do la[i]:=1-la[i];
	2:for i:=1 to n do if not odd(i) then la[i]:=1-la[i];
	3:for i:=1 to n do if  odd(i) then la[i]:=1-la[i];
	4:for i:=1 to n do if ((i-1)mod 3)=0 then la[i]:=1-la[i];
	end;
end;
procedure print;
var i:integer;
begin
	inc(s);
	for i:=1 to n do
		a[s,i]:=la[i];
end;
procedure main(k:integer);
begin
	if k>4 then
	begin
		if (c >= total) and check then print;
		exit;
	end;
	inc(total);
	an(k);//按下,total自加
	main(k+1);
	dec(total);
	an(k);//不按,total自减,之所以有两个一样的an过程,是因为可以用来当作反过程.
	main(k+1);
end;
procedure init;
var temp,i:integer;
begin
	fillchar(la,sizeof(la),0);
	fillchar(on1,sizeof(on1),0);
	fillchar(off1,sizeof(off1),0);
	temp:=0;
	readln(n);
	readln(c);
	read(temp);
	while temp<>-1 do
	begin
		if temp<>-1 then on1[temp]:=1;
		read(temp);
	end;
	readln;
	temp:=0;
	read(temp);
	while temp<>-1 do
	begin
		if temp<>-1 then off1[temp]:=1;
		read(temp);
	end;
	for i:=1 to n do
		la[i]:=1;//初始化灯是开着的.
end;
function pdd(x:integer):boolean;
var i:integer;
begin
	for i:=1 to n do
		if  a[x,i]<>a[x+1,i] then exit(true);
	exit(false);
end;
procedure print2;
var i,j:integer;
begin
	for i:=1 to s do
	begin
		if pdd(i) then//判重
		for j:=1 to n do
		  write(a[i,j]);
		if pdd(i)then writeln;
	end;
end;
begin
  assign(input,'lamps.in');
  reset(input);
  assign(output,'lamps.out');
  rewrite(output);
  init;
  main(1);
  sort;
  print2;
  if s=0 then writeln('IMPOSSIBLE');
  close(input);
  close(output);
end.