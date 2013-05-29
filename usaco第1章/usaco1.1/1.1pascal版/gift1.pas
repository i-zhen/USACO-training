{
ID: sacredf1
PROG: gift1
LANG: PASCAL
}
program gift1;
type node=record
	    zh:string;
		mon,s,h:longint;
        end;
var a:array[1..10]of node;
		n:longint;
procedure init;
var i,j,k,temp,q:integer;
	x:string;
begin
	readln(n);
	for i:=1 to n do
    begin
		readln(a[i].zh);
		end;
	for i:=1 to n do
	begin
		readln(x);
	  for j:=1 to n do
	    if a[j].zh=x then begin readln(a[j].mon,a[j].s);break;end;
			for k:=1 to a[j].s do
		    begin
				temp:=trunc(a[j].mon div a[j].s);
				readln(x);
			    for q:=1 to n do
	              if a[q].zh=x then a[q].h:=temp+a[q].h;
				a[j].h:=a[j].h-temp;
		     end;
	     
	end;
end;
procedure pout;
var i:integer;
begin
	for i:=1 to n do
    begin
		writeln(a[i].zh,' ',a[i].h);
	end;
end;
begin
  assign(input,'gift1.in');
  reset(input);
  assign(output,'gift1.out');
  rewrite(output);
  init;
  pout;
  close(input);
  close(output);
end.