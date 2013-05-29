{
ID: sacredf1
PROG: hamming
LANG: PASCAL
}
program hamming;
var n,b,d,total,max:integer;
	s:array[1..64]of integer;
function check(te:integer):boolean;
var i,tk,p,leijia:integer;
begin
	for i:=1 to total do
	begin
		tk:=0;leijia:=0;
		tk:=s[i] xor te;
		while tk<>0 do
		begin
			p:=tk mod 2;
			if p=1 then inc(leijia);
			tk:=tk div 2;
		end;
		if leijia<d then exit(false);
	end;
	exit(true);
end;
procedure main;
var i,i2:integer;
begin
	fillchar(s,sizeof(s),0);total:=1;
	s[1]:=0;
	for i:=1 to max do
	begin
		if check(i) then begin
			inc(total);
			s[total]:=i;
		end;
		if total=n then 
		begin
			for i2:=1 to n-1 do
			if i2 mod 10=0 then writeln(s[i2]) else write(s[i2],' ');
			writeln(s[n]);
			halt;
		end;
	end;
end;
procedure init;
var i:integer;
begin
	max:=1;
	total:=0;
	readln(n,b,d);
	for i:=1 to b do
		max:=max*2;
	dec(max);
end;
begin
  assign(input,'hamming.in');
  reset(input);
  assign(output,'hamming.out');
  rewrite(output);
  init;
  main;
  close(input);
  close(output);
end.