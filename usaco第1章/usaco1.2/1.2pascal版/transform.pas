{
ID: sacredf1
PROG: transform
LANG: PASCAL
}
program test;
var a,b:array[1..10,1..10]of char;
	n:integer;
		flag:boolean;
procedure init;
var i,j:integer;
begin
	readln(n);
	for i:=1 to n do
	begin
		for j:=1 to  n do
		read(a[i,j]);
	  readln;
	end;
	for i:=1 to n do
	begin
		for j:=1 to  n do
		read(b[i,j]);
	  readln;
	end;
end;
procedure fanzhuan;
var i,j:integer;
begin
	for i:=1 to n do
       for j:=1 to  n do
      if a[i,j]<>b[i,j] then begin flag:=false;break;end;
		  if flag then begin writeln(4);close(input);close(output);halt;end 
		  else flag:=true;
end;
procedure zuhe;
var i,j:integer;
begin
	flag:=true;
	for i:=1 to n do
    	for j:=n downto 1 do
		  if a[j,i]<>b[i,n-j+1] then begin flag:=false;break;end;
		  if flag then begin writeln(5);close(input);close(output);halt;end 
		  else flag:=true;
	for i:=n downto 1 do
		  for j:=n downto 1 do
		  if a[j,i]<>b[n-j+1,n-i+1]then begin flag:=false;break;end;
		  if flag then begin writeln(5);close(input);close(output);halt;end 
		  else flag:=true;
	for i:=n downto 1 do
		  for j:=1 to n do
		  if a[j,i]<>b[n-i+1,j]then begin flag:=false;break;end;
		  if flag then begin writeln(5);close(input);close(output);halt;end 
		  else flag:=true;
end;
procedure main;
var i,j:integer;
	k:char;
begin
	flag:=true;
	for i:=1 to n do
    	for j:=n downto 1 do
		  if a[j,i]<>b[i,n-j+1] then begin flag:=false;break;end;
		  if flag then begin writeln(1);close(input);close(output);halt;end 
		  else flag:=true;
	for i:=n downto 1 do
		  for j:=n downto 1 do
		  if a[j,i]<>b[n-j+1,n-i+1]then begin flag:=false;break;end;
		  if flag then begin writeln(2);close(input);close(output);halt;end 
		  else flag:=true;
	for i:=n downto 1 do
		  for j:=1 to n do
		  if a[j,i]<>b[n-i+1,j]then begin flag:=false;break;end;
		  if flag then begin writeln(3);close(input);close(output);halt;end 
		  else flag:=true;
	for i:=1 to n  do
		for j:=1 to n div 2 do
		begin
			k:=a[i,j];
		    a[i,j]:=a[i,n-j+1];
		    a[i,n-j+1]:=k;
		end;
	fanzhuan;
	zuhe;
	for i:=1 to n do
       for j:=1 to  n do
      if a[i,j]<>b[i,j] then begin flag:=false;break;end;
		  if flag then begin writeln(6);close(input);close(output);halt;end 
		  else flag:=true;
	if flag then writeln(7);
end;
begin
  assign(input,'transform.in');
  reset(input);
  assign(output,'transform.out');
  rewrite(output);
  init;
  main;
  close(input);
  close(output);
end.