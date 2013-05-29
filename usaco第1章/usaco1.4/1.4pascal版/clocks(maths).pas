{
ID: sacredf1
PROG: clocks
LANG: PASCAL
}
program test;
type node= array[1..9]of integer;
var   change:array[1..9,1..9]of integer=
	    ((3,3,3,3,3,2,3,2,0),
		(2,3,2,3,2,3,1,0,1),
		(3,3,3,2,3,3,0,2,3),
		(2,3,1,3,2,0,2,3,1),
	    (2,3,2,3,1,3,2,3,2),
		(1,3,2,0,2,3,1,3,2),
		(3,2,0,3,3,2,3,3,3),
		(1,0,1,3,2,3,2,3,2),
	    (0,2,3,2,3,3,3,3,3));
    //注重好的数据结构
	  a:node;//初始化读入的数据
	  list:array[1..9]of integer;//状态记录
	  listmax:integer;
procedure main;
var i,j,k,t:integer;
begin	
	t:=0;
	for i:=1 to 9 do
	begin
		for k:=1 to ((12-a[i])div 3) do
		for j:=1 to 9 do
		begin
			list[j]:=list[j]+change[i,j];
		end;
	end;
	for i:=1 to 9 do
	begin
	   list[i]:=list[i] mod 4;
	   listmax:=listmax+list[i];
    end;
	for i:=1 to 9 do
		for j:=1 to list[i] do
		begin
		t:=t+1;
		  if t<>listmax then
			write(i,' ')
		  else
			write(i);
		end;
	writeln;
end;
procedure init;
var i:integer;
begin
	for i:=1 to 9 do
		read(a[i]);
	listmax:=0;
end;
begin
  assign(input,'clocks.in');
  reset(input);
  assign(output,'clocks.out');
  rewrite(output);
  init;
  main;
  close(input);
  close(output);
end.