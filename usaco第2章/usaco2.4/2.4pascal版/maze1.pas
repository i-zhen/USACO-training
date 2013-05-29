{
ID: sacredf1
PROG: maze1
LANG: PASCAL
}
program test;
type node=array[-1..500,-1..500]of longint;
var w,h,max,tail,head:longint;
	map:array[-1..500,-1..500]of char;
	dlx,dly:array[-1..10000]of integer;
	gt:node;
procedure main(a,b,a2,b2:longint;var g:node);//floodfill,多进程bfs
var x,y:longint;
begin
	x:=0;y:=0;
	tail:=2;head:=0;
	dlx[1]:=a;
	dly[1]:=b;//出口最先入队
	dlx[2]:=a2;
	dly[2]:=b2;//出口最先入队
	g[a div 2,b div 2]:=1;
	g[a2 div 2,b2 div 2]:=1;
	while head<=tail do
	begin
		inc(head);//头指针出队,读取新的节点.
		x:=dlx[head];
		y:=dly[head];
		//expand,扩展状态
		if (map[x+1,y]<>'-')and((x+2)<2*h+1)and(g[(x+2) div 2,y div 2]=0) then 
		begin
			inc(tail);
			dlx[tail]:=x+2;
			dly[tail]:=y;
			g[(x+2) div 2,y div 2]:=g[x div 2,y div 2]+1;
		end;
		if (map[x-1,y]<>'-')and((x-2)>1)and(g[(x-2) div 2,y div 2]=0) then
		begin
			inc(tail);
			dlx[tail]:=x-2;
			dly[tail]:=y;
		g[(x-2) div 2,y div 2]:=g[x div 2,y div 2]+1;
		end;
		if (map[x,y+1]<>'|')and((y+2)<2*w+1)and(g[x div 2,(y+2) div 2]=0) then
		begin
			inc(tail);
			dlx[tail]:=x;
			dly[tail]:=y+2;
		g[x div 2,(y+2) div 2]:=g[x div 2,y div 2]+1;
		end;
		if (map[x,y-1]<>'|')and((y-2)>1)and(g[x div 2,(y-2) div 2]=0) then
		begin
			inc(tail);
			dlx[tail]:=x;
			dly[tail]:=y-2;
		g[x div 2,(y-2) div 2]:=g[x div 2,y div 2]+1;
		end;
	end;
end;
procedure init;
var i,j:integer;
begin
	readln(w,h);
	//初始化图
	for i:=1 to h*2+1 do
	begin
		for j:=1 to w*2+1 do
			read(map[i,j]);
		readln;
	end;
end;
procedure m1;
var i,j,s,a,b,a2,b2:integer;
begin
	//flood fill
	i:=0;s:=0;
	repeat
		if i=0 then i:=1 else i:=2*h+1;
		for j:=1 to w*2+1 do
		if map[i,j]=' ' then 
		begin
			inc(s);
			case s of
			1:if (i=1) then begin a:=i+1;b:=j;end
			else begin a:=i-1;b:=j;end;
			2:if (i=1) then begin a2:=i+1;b2:=j;end
				else begin a2:=i-1;b2:=j;end;
			end;
		end;
	until i=2*h+1;
	j:=0;
	repeat
		if j=0 then j:=1 else j:=2*w+1;
		for i:=1 to h*2+1 do
		if map[i,j]=' ' then 
		begin
			inc(s);
			case s of
			1:if j=1 then begin a:=i;b:=j+1;end
				else begin a:=i;b:=j-1;end;
			2:if j=1 then begin a2:=i;b2:=j+1;end
				else begin a2:=i;b2:=j-1;end;
			end;
		end;
	until j=2*w+1;
	fillchar(gt,sizeof(gt),0);
	main(a,b,a2,b2,gt);
	max:=0;
	for i:=1 to h do
		for j:=1 to w do
			if max<gt[i,j] then max:=gt[i,j];
	writeln(max);
end;
begin
  assign(input,'maze1.in');
  reset(input);
  assign(output,'maze1.out');
  rewrite(output);
  init;
  m1;
  close(input);
  close(output);
end.