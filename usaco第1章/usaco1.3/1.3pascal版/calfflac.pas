{
ID: sacredf1
PROG: calfflac
LANG: PASCAL
}
program test;
type node=record
		s,l,r:integer;
		end;
var c:integer;
	total:node;
	b:array[1..20250]of char;
procedure init;
begin
	c:=0;
    total.s:=1;
	total.l:=1;total.r:=1;
	while not(eof) do
	begin
			inc(c);
			read(b[c]);
	end;
end;
procedure main;
var i,l,r:integer;
	l2,r2,e,o:integer;
	f1,f2:boolean;
begin
	for i:=1 to c do
    if (((b[i]>='a')and(b[i]<='z')) or ((b[i]>='A')and(b[i]<='Z')) ) then
   begin
		f1:=true;f2:=true;
		l:=i;r:=i+1;{偶}l2:=i-1;r2:=i+1;{奇}
		e:=0;o:=1;
		while f1 or f2 do
		begin
		{偶数}
			if f1 then
			begin
				if (l>0)and(r<c)then
				begin
					while true do
					if (not (((b[l]>='a')and(b[l]<='z')) or ((b[l]>='A')and(b[l]<='Z'))))and(l>1) then dec(l)
					else break;
					while true do
					if(not (((b[r]>='a')and(b[r]<='z')) or ((b[r]>='A')and(b[r]<='Z'))))and(r<c-1) then inc(r)
					else break;
					if (ord(b[l])=ord(b[r]) )or (ord(b[l])+32=ord(b[r]) )or(ord(b[l])-32=ord(b[r]) )then
						begin
							e:=e+2;
							if total.s<e then begin total.s:=e;total.l:=l;total.r:=r;end;
							dec(l);
							inc(r);
						end
					else f1:=false;
				end
				else 
				f1:=false;
			end;
		
		{奇数}
			if f2  then
			begin
				if (l2>0)and(r2<c)then
				begin
					while true do
				   if (not(((b[l2]>='a')and(b[l2]<='z')) or ((b[l2]>='A')and(b[l2]<='Z')))) and(l2>1)then dec(l2)
				   else break;
					while true do
				   if (not(((b[r2]>='a')and(b[r2]<='z')) or ((b[r2]>='A')and(b[r2]<='Z')))) and(r2<c-1) then inc(r2)
					else break;
					if (ord(b[l2])=ord(b[r2]) )or (ord(b[l2])+32=ord(b[r2]) )or(ord(b[l2])-32=ord(b[r2]) )then
						begin
							o:=o+2;
							if total.s<o then begin total.s:=o;total.l:=l2;total.r:=r2;end;
							dec(l2);
							inc(r2);
						end
					else f2:=false;
				end
				else f2:=false;
			end;
		end;
	end;
	writeln(total.s);
	for i:=total.l to total.r do
	write(b[i]);
	writeln;
end;
begin
  assign(input,'calfflac.in');
  reset(input);
  assign(output,'calfflac.out');
  rewrite(output);
  init;
  main;
  close(input);
  close(output);
end.