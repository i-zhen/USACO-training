{
ID: sacredf1
PROG: friday
LANG: PASCAL
}
program test;
var n:longint;
	  a:array[1..12]of integer;
	  b:array[0..6]of integer;
	  day:longint;
procedure init;
var y,i:integer;
begin
  readln(n);
  b[6]:=1;{未算第一个月的,手动加上}
 day:=0;
  for y:=1900 to 1900+n-1 do
  begin
	  a[1]:=31;a[3]:=31;a[5]:=31;a[7]:=31;a[8]:=31;a[10]:=31;a[12]:=31;
     If( ((y Mod 4 = 0) And (y Mod 100 <> 0))) Or (y Mod 400 = 0 )
		Then a[2]:=29 else a[2]:=28;
	  a[4]:=30;a[6]:=30;a[9]:=30;a[11]:=30;
      for i:=1 to 12 do
		begin
		day:=day+a[i];   
		inc(b[(day+13)mod 7]);
		end;
  end;
end;
begin
  assign(input,'friday.in');
  reset(input);
  assign(output,'friday.out');
  rewrite(output);
  init;
  dec(b[(13+day)mod 7]);{减去最后一个月的重复计算}
  writeln(b[6],' ',b[0],' ',b[1],' ',b[2],' ',b[3],' ',b[4],' ',b[5]);
  close(input);
  close(output);
end.