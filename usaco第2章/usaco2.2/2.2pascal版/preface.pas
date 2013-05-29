{
ID: sacredf1
PROG: preface
LANG: PASCAL
}
program test;
var pg:integer;
	k:array[1..1000]of integer;
function ff(a:integer):integer;
var x:integer;
begin
	ff:=1;
	for x:=1 to a do
		ff:=ff*10;
end;
procedure js(x,y:integer);
var p,q,temp1,temp2,temp3:integer;//主要是划分范围,枚举判断
begin
	temp1:=5*ff(y-1);
	if (x<temp1) then
	begin
		temp1:=5*ff(y-1);temp2:=ff(y-1);
		if x=temp1-temp2
		then begin inc(k[temp1]);inc(k[temp2]);exit;end
		else
		begin
			if temp2=x then begin inc(k[temp2]);exit;end;
			if 2*temp2=x then begin k[temp2]:=k[temp2]+2;exit;end;
			if 3*temp2=x then begin k[temp2]:=k[temp2]+3;exit;end;
		end;
	end
	else
	begin
		temp1:=ff(y);temp2:=ff(y-1);temp3:=5*ff(y-1);
		if x=temp1-temp2
		then begin inc(k[temp1]);inc(k[temp2]);exit;end
		else
			if x=temp3 then begin inc(k[temp3]);exit;end
			else
				begin
					if temp2+temp3=x then begin inc(k[temp2]);inc(k[temp3]);exit;end;
					if 2*temp2+temp3=x then begin k[temp2]:=k[temp2]+2;inc(k[temp3]);exit;end;
					if 3*temp2+temp3=x then begin k[temp2]:=k[temp2]+3;inc(k[temp3]);exit;end;
				end
	end;
end;
procedure main;
var p,q,temp:integer;
	s:string;
begin
	for q:=1 to pg do

		begin
		str(q,s);temp:=q;
		for p:=1 to length(s) do
		begin
			js(temp mod ff(p),p);
			temp:=(temp div ff(p) )* ff(p);
		end;
	end;
	if k[1]<>0 then writeln('I ',k[1]);
	if k[5]<>0 then writeln('V ',k[5]);
	if k[10]<>0 then writeln('X ',k[10]);
	if k[50]<>0 then writeln('L ',k[50]);
	if k[100]<>0 then writeln('C ',k[100]);
	if k[500]<>0 then writeln('D ',k[500]);
	if k[1000]<>0 then writeln('M ',k[1000]);
end;
procedure init;
begin
	fillchar(k,sizeof(k),0);
	readln(pg);
	main;
end;
begin
  assign(input,'preface.in');
  reset(input);
  assign(output,'preface.out');
  rewrite(output);
  init;
  close(input);
  close(output);
end.