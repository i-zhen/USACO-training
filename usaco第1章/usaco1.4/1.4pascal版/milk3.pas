{
IN:tj21623
TASK:milk3
LANG:PASCAL
}
program milk3;
var
	milk:array[0..20,0..20,0..20] of boolean;
	a,b,c,ta,tb,tc:integer;
	jilu:array[0..20]of boolean;
procedure init;
begin
	assign(input,'milk3.in');reset(input);
	assign(output,'milk3.out');rewrite(output);
    readln(a,b,c);
	ta:=0;tb:=0;tc:=0;
    fillchar(milk,sizeof(milk),false);
	fillchar(jilu,sizeof(jilu),false);
    close(input);
end;
function trueabc(x,y,z:integer):boolean;//该函数用来记录递归状态。
begin
	if milk[x,y,z]=true then trueabc:=true
		else
		begin
			milk[x,y,z]:=true;
			trueabc:=false;
		end;
end;

procedure work(x,y,z:integer);
var
	i,j:integer;
begin
	if trueabc(x,y,z) then exit;//记录状态，判重。
	for i:=1 to 3 do
	case i of
	1:	if x<>0 then begin
		for j:=1 to 2 do
			case j of
				1:if y=b then continue
					else
					begin
						if x>b-y then 
							begin
								ta:=x-b+y;tb:=b;tc:=z;if ta=0 then jilu[tc]:=true; 
								work(ta,tb,tc);
							end
						else 
							begin 
								ta:=0;tb:=y+x;tc:=z;jilu[tc]:=true; 
								work(ta,tb,tc);
							end;
					end;
				2:begin
						ta:=0;tb:=y;tc:=x+z;jilu[tc]:=true; 
						work(ta,tb,tc);//把a中的全部倒回c中是不会溢出的.所以不必判断
					end;
			end;
		end;
	2:	if y<>0 then begin
		for j:=1 to 2 do
			case j of
				1:if x=a then continue
					else
					begin
						if y>a-x then 
							begin
								ta:=a;tb:=y-a+x;tc:=z;if ta=0 then jilu[tc]:=true; 
								work(ta,tb,tc);
							end
						else 
							begin 
								ta:=x+y;tb:=0;tc:=z; if ta=0 then jilu[tc]:=true; 
								work(ta,tb,tc);
							end;
					end;
				2:begin
						ta:=x;tb:=0;tc:=y+z;if ta=0 then jilu[tc]:=true; 
						work(ta,tb,tc);//把b中的全部倒回c中是不会溢出的.所以不必判断
					end;
			end;
		end;
	3:	if	z<>0 then begin
		for j:=1 to 2 do
			case j of
				1:if x=a then continue//把c中的倒入a中要判断
					else
					begin
						if z>a-x then
							begin
								ta:=a;tb:=y;tc:=z-a+x;if ta=0 then jilu[tc]:=true; 
								work(ta,tb,tc);
							end
						else
							begin
								ta:=x+z;tb:=y;tc:=0;if ta=0 then jilu[tc]:=true; 
								work(ta,tb,tc);
							end;
					end;
				2:if y=b then continue//把c中的倒入b中要判断
					else
					begin
						if z>b-y then
							begin
								ta:=x;tb:=b;tc:=z-b+y;if ta=0 then jilu[tc]:=true; 
								work(ta,tb,tc);
							end
						else
							begin
								ta:=x;tb:=y+z;tc:=0;if ta=0 then jilu[tc]:=true; 
								work(ta,tb,tc);
							end;
					end;
			end;
		end;
	end;
end;
procedure pout;
var
	i,j,k:integer;
begin
	j:=0;k:=0;
	for i:=0 to 20 do if jilu[i] then inc(j);
	for i:=0 to 20 do if jilu[i] then 
		begin
			inc(k);
			if k<>j then write(i,' ')
			else write(i);
		end;
	writeln;
	close(output);
end;
begin
	init;
	work(0,0,c);
	pout;
end.