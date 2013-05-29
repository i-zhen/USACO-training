{
ID: sacredf1
PROG: sort3
LANG: PASCAL
}
program test;
var n:integer;
	a:array[1..1000] of integer;
	jilu,wz:array[0..3]of integer;
procedure init;
var i:integer;
begin
	readln(n);
	fillchar(jilu,sizeof(jilu),0);
	fillchar(wz,sizeof(wz),0);
	for i:=1 to n do
	begin
		readln(a[i]);
		inc(jilu[a[i]]);//记录1,2,3的个数.
	end;
	wz[1]:=1;
	wz[2]:=jilu[1]+1;
	wz[3]:=jilu[1]+jilu[2]+1;
end;
procedure huan(var a,b:integer);
begin
	a:=a xor b;
	b:=a xor b;
	a:=a xor b;
end;
procedure main;
var i,i2,j,k,t:integer;
	f:boolean;
begin
	t:=0;
	for i:=1 to 3 do
		for j:=wz[i] to wz[i]+jilu[i]-1 do
		begin
			f:=false;
			if a[j]<>i then
			begin 
			if not f then  //一次交换式
				for k:=wz[a[j]] to wz[a[j]]+jilu[a[j]]-1 do
					if (a[k]=i ) then 
						begin 
							huan(a[k],a[j]);
							inc(t); 
							f:=true;
							break;
						end;
				if not f then  //两次交换式
				begin
				for k:=wz[a[j]+1] to wz[a[j]+1]+jilu[a[j]+1]-1 do
					if a[k]=i then
					begin
						huan(a[k],a[j]);
						inc(t);
						break;
					end;
				for k:=wz[a[j]-1] to wz[a[j]-1]+jilu[a[j]-1]-1 do
					if a[k]=i then
					begin
						huan(a[k],a[j]);
						inc(t);
						break;
					end;
				end;
			end;
		end;
		writeln(t);
end;
begin
  assign(input,'sort3.in');
  reset(input);
  assign(output,'sort3.out');
  rewrite(output);
  init;
  main;
  close(input);
  close(output);
end.