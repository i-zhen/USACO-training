{
ID: sacredf1
PROG: pprime
LANG: PASCAL
}
program test;
var a,b,i9,code:longint;
	a1,b1,zi:string;
procedure pd(k:string);
var j:cardinal;
	flag:boolean;
begin
	val(k,i9,code);
	flag:=true;
	if (i9>=a)and(i9<=b) then 
		for j:=2 to trunc(sqrt(i9)) do//就是这里,原本div 2,总是超时
					      //改为sqrt就明显好多了
					      //再一次证明不能忽略任何小细节
			if (i9 mod j) =0 then  begin flag:=false;break;end else flag:=true
		else flag:=false;
	if flag then writeln(i9);
end;
procedure main;
var i:integer;
		h,t,j,j2,i2,s:cardinal;
	z,c:string;
begin
    for i:=length(a1) to length(b1) do 
    begin
	zi:='';c:='';
	if odd(i) then
	begin
		z:='';
		h:=1;t:=1;s:=1;
		if i>1 then for j:=1 to i div 2 do
			h:=h*10;
		if i=1 then t:=9 else
		begin
			for j:=1 to i div 2 +1 do
			t:=t*10;
			dec(t);
		end;
		for j:=1 to i div 2 do
			s:=s*10;
		for j:=h to t do 
		if (j>=trunc(sqrt(a))) then
			if (j>b div s) then exit else
		begin
			str(j,zi);z:=zi;
			j2:=length(z);
			if j2=1 then  z:='' else 
			begin
			for 	i2:=1 to j2 div 2 do
			begin
				c[1]:=z[i2];
				z[i2]:=z[j2-i2+1];
				z[j2-i2+1]:=c[1];
			end;
			c:='';
			for i2:=1 to j2-1 do
				zi:=zi+z[i2+1];
			end;
			pd(zi);
		end;
	end
	else
	if i=2 then 
		if a<=11 then if b>=11 then writeln(11);//When even,the 11 is the only one that can accept.
	end;
end;
procedure init;
begin
	readln(a,b);
	str(a,a1);
	str(b,b1);
	main;
end;
begin
  assign(input,'pprime.in');
  reset(input);
  assign(output,'pprime.out');
  rewrite(output);
  init;
  close(input);
  close(output);
end.