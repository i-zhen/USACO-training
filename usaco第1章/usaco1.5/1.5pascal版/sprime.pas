{
ID: sacredf1
PROG: sprime
LANG: PASCAL
}
program sprime;
var n:integer;
	sw:array[1..4]of integer=(2,3,5,7);
	jw:array[1..4]of integer=(1,3,7,9);
	mw:array[1..4]of integer=(1,3,7,9);
function pd(a:longint):boolean;//pd函数用于检查是否为质数,如果不是就剪枝(不继续搜索)
var j:cardinal;
begin
		for j:=2 to trunc(sqrt(a)) do
			if (a mod j) =0 then  
			exit(false);
		exit(true);
end;
function cf(i:integer):longint;
var j:integer;
begin
	cf:=1;
	for j:=1 to i-1 do
		cf:=cf*10;
end;
procedure main(wz,t:longint);
var i,i2,i3,t1:longint;
begin
	case wz of
	1:for i:=1 to 4 do
			begin
				t:=sw[i]*cf(n);
				if (wz+1)<=n then begin main(wz+1,t);end
					else writeln(t);
			end;
	else
		if wz=n then
		begin 
			t1:=t;
			for i2:=1 to 4 do
			begin
				t1:=t1+mw[i2];
				if pd(t1) then writeln(t1);
				t1:=t;
			end
		end
		else
		begin
		t1:=t;
		for i3:=1 to 4 do
			begin
				t1:=t1+jw[i3]*cf(n-wz+1);
				if pd(t1 div (cf(n-wz+1))) then
				begin   
					main(wz+1,t1);
				end;
				t1:=t;
			end;
		end;
	end;
end;
procedure init;
begin
	readln(n);
    main(1,0);
end;
begin
  assign(input,'sprime.in');
  reset(input);
  assign(output,'sprime.out');
  rewrite(output);
  init;
  close(input);
  close(output);
end.