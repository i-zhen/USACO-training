{
ID: sacredf1
PROG: castle
LANG: PASCAL
}
program castle;
var i,j,n1,m,max,t1,t2,t3:integer;
	a,a2:array[1..50,1..50]of integer;
	b:array[1..50,1..50]of integer;
	n,e,w,s:array[1..2500]of boolean;
	mj:array[1..2500]of integer;
procedure dfs(x,y:integer;t2:integer);
begin
	inc(t2);
	inc(t3);
	n[t2]:=true;
	e[t2]:=true;
	w[t2]:=true;
	s[t2]:=true;
	b[x,y]:=t1;
	//dfs
		if a[x,y]-8>=0 then begin a[x,y]:=a[x,y]-8;s[t2]:=false;end;
		if a[x,y]-4>=0 then begin a[x,y]:=a[x,y]-4;e[t2]:=false;end;
		if a[x,y]-2>=0 then begin a[x,y]:=a[x,y]-2;n[t2]:=false;end;
		if a[x,y]-1>=0 then begin a[x,y]:=a[x,y]-1;w[t2]:=false;end;	
		if w[t2]and(b[x,y-1]=-1)  then dfs(x,y-1,t2);
		if n[t2]and(b[x-1,y]=-1) then dfs(x-1,y,t2);
		if e[t2] and(b[x,y+1]=-1) then dfs(x,y+1,t2);
		if s[t2] and(b[x+1,y]=-1) then dfs(x+1,y,t2);
end;
procedure main;
var st:integer;
	i2,j2:integer;
begin
	max:=0;
	t1:=0;
	t2:=0;
	//flood fill
	for i:=1 to n1 do
		for j:=1 to m do
		begin
			if b[i,j]=-1
			then 
			begin
				inc(t1);
				t2:=0;t3:=0;
				dfs(i,j,t2);
				mj[t1]:=t3;
				if t3>max then max:=t3;
			end;
		end;
	writeln(t1);
	writeln(max);
	max:=0;
	//寻找合并最值
	for i:=1 to m do
		for j:=n1 downto 1 do
		begin
			//先找上面的
			if b[j,i]<>b[j-1,i] then
				if (a2[j,i]-2>=0)then
				if mj[b[j,i]]+mj[b[j-1,i]]>max then 
					begin
						max:=mj[b[j,i]]+mj[b[j-1,i]];
						st:=2;
						i2:=j;j2:=i;
					end;
			//再找右面的
			if b[j,i]<>b[j,i+1] then
				if (a2[j,i]-4>=0) then
				if mj[b[j,i]]+mj[b[j,i+1]]>max then 
					begin
						max:=mj[b[j,i]]+mj[b[j,i+1]];
						st:=4;
						i2:=j;j2:=i;
					end;
		end;
		writeln(max);
		write(i2,' ',j2);
		if st=4 then writeln(' E') else writeln(' N');
end;
procedure init;
var i,j:integer;
begin
	fillchar(a,sizeof(a),0);
	readln(m,n1);
	for i:=1 to n1 do
	begin
		for j:=1 to m do
		begin read(a[i,j]);b[i,j]:=-1;end;
	readln;
	end;
	a2:=a;
end;
begin
  assign(input,'castle.in');
  reset(input);
  assign(output,'castle.out');
  rewrite(output);
  init;
  main;
  close(input);
  close(output);
end.