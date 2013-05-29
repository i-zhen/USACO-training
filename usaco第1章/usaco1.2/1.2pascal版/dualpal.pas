{
ID: sacredf1
PROG: dualpal
LANG: PASCAL
}
program test;
var n,m,s:longint;
	a:array[1..1000000]of char;
procedure jinzhi(i,o:longint);
var q,r:longint;
	  k:string;
begin
	m:=0;
	q:=-1;
k:='';
	repeat
	begin
		q:=i div o ;
		r:=i mod o ;
		if r<10 then str(r,k) else
		case r of
		10:k:='A';
		11:k:='B';
		12:k:='C';
		13:k:='D';
		14:k:='E';
		15:k:='F';
		16:k:='G';
		17:k:='H';
		18:k:='I';
		19:k:='J';
		20:k:='K';
		end;
	    i:=q;
		inc(m);
		a[m]:=k[1];
	end
	until q=0;
	for i:=1 to m div 2  do
	begin
		k[1]:=a[i];
		a[i]:=a[m-i+1];
		a[m-i+1]:=k[1];
	end;
end;           
function panduan:boolean;
var i:integer;
begin
	panduan:=true;
	for i:=1 to m do
        if a[i]<>a[m-i+1] then panduan:=false ;
end;                        
procedure init;
var i,i2,j:integer;
begin
  i:=0;
  readln(n,s);
  while i<>n do
  begin
	  inc(s);j:=0;
	for i2:=2 to 10 do
	begin
	  jinzhi(s,i2);if panduan then inc(j);
		  if j>1 then begin writeln(s);inc(i);break;end;
    end;
      
  end;
end;
begin
  assign(input,'dualpal.in');
  reset(input);
  assign(output,'dualpal.out');
  rewrite(output);
init;
  close(input);
  close(output);
end.