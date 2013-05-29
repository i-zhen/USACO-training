{
ID: sacredf1
PROG: zerosum
LANG: PASCAL
}
program test;
type node=array[0..8]of integer;
var n:3..9;
	a:array[1..9]of integer;
	b1:array[1..9]of integer;
	total:longint;
	b:node;
procedure print(c:node);
var i:integer;
begin
	for i:=2 to n do
	begin
		case c[i-1] of 
		1:begin
			write(a[i-1],' ');
			end;
		2:begin
			write(a[i-1],'+');
			end;
		3:begin
			write(a[i-1],'-');
			end;
		end;
	end;
	writeln(a[n]);
	{for i:=1 to n-1 do
		write(c[i],' ');
	writeln;}
end;
procedure pd(c:node);
var i,temp,temp2:integer;
begin
	fillchar(b1,sizeof(b1),0);
	total:=0;temp:=0;
	for i:=1 to n do
	begin
		if c[i]=1 then
		begin
			if c[i-1]=1 then total:=total*10+a[i+1];
			if c[i-1]<>1 then
			begin
				total:=a[i];
				total:=total*10+a[i+1];
			end;
			if c[i+1]<>1 then
			begin inc(temp);b1[temp]:=total;end;
		end;
	end;
	temp:=1;temp2:=0;
	if c[1]=1 then begin total:=b1[1];inc(temp2);end
		else total:=a[1];
	while temp<n do
	begin
		if c[temp]<>1 then
		begin
		if c[temp+1]<>1 then
			case c[temp] of
				2:total:=total+a[temp+1];
				3:total:=total-a[temp+1];
			end
		else 
			begin
				inc(temp2);
				case c[temp] of
				2:total:=total+b1[temp2];
				3:total:=total-b1[temp2];
				end;
				for i:=temp+1 to n do
					if i<>1 then
					begin
						temp:=i;
						break;
					end;
			end;
		end;
		inc(temp);
	end;
	if total=0 then print(c)
		else exit;
end;
procedure dfs(x:integer;b:node);
var i:integer;
begin
	if (x=n) then
	begin
		pd(b);
		exit;
	end;
	for i:=1 to 3 do
	begin
		b[x]:=i;
		if x+1<=n then dfs(x+1,b); 
	end;
end;
procedure init;
var i:integer;
begin
	readln(n);
	fillchar(a,sizeof(a),0);
	for i:=1 to n do
		a[i]:=i;
	b[0]:=0;
end;
begin
  assign(input,'zerosum.in');
  reset(input);
  assign(output,'zerosum.out');
  rewrite(output);
  init;
  dfs(1,b);
  close(input);
  close(output);
end.