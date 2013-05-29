{
ID: sacredf1
PROG: namenum
LANG: PASCAL
}
program test;
var f1,f2,f3:text;
function zi(b:char):integer;
begin
	case b of
	'A','B','C':zi:=2;
	'J','K','L':zi:=5;
    'T','U','V':zi:=8;
	'D','E','F':zi:=3;
	'M','N','O':zi:=6;
    'W','X','Y':zi:=9;
	'G','H','I':zi:=4;
	 'P','R','S':zi:=7
	else zi:=0;
	end;
end;
procedure main;
var i:integer;
	flag,f22:boolean;
	k,n:string;
begin
	readln(f1,n);f22:=false;
	while not(eoln(f3)) do
    begin
		readln(f3,k);
	    flag:=false;
	    if length(k)=length(n) then
		for i:=1 to length(k) do
			if zi(k[i])<>(ord(n[i])-ord('0')) then begin flag:=false;break;end else flag:=true;
		if flag then begin writeln(f2,k);f22:=true;end;
	end;
	if f22=false then writeln(f2,'NONE');
end;
begin
  assign(f1,'namenum.in');
  reset(f1);
  assign(f3,'dict.txt');
  reset(f3);
  assign(f2,'namenum.out');
  rewrite(f2);
  main;
  close(f1);
  close(f2);
end.