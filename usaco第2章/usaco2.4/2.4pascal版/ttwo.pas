{
ID: sacredf1
PROG: ttwo
LANG: PASCAL
}
program ttwo;
var map:array[1..10,1..10]of char;
	xc,yc,xf,yf,x1,y1,x2,y2,fc,ff:integer;
	total:longint;
procedure zh1;
begin
	case x1 of 
		0:if y1=1 then begin x1:=1;y1:=0;fc:=3; end else begin x1:=-1;y1:=0;fc:=1;end;
		-1:begin x1:=0;y1:=1;fc:=2;end;
		1:begin x1:=0;y1:=-1;fc:=4;end;
	end;
end;
procedure zh2;
begin
	case x2 of 
		0:if y2=1 then begin x2:=1;y2:=0;ff:=3;end else begin x2:=-1;y2:=0;ff:=1;end;
		-1:begin x2:=0;y2:=1;ff:=2;end;
		1:begin x2:=0;y2:=-1;ff:=4;end;
	end;
end;
procedure main;
var c,f:boolean;
begin
	while total<160000 do//×î¶à160000ÖÖ×´Ì¬
	begin
		c:=false;f:=false;
		//cow
		if (map[xc+x1,yc+y1]<>'*')then
		case fc of
			1:if xc<>1 then c:=true;
			2:if yc<>10 then c:=true;
			3:if xc<>10 then c:=true;
			4:if yc<>1 then c:=true;
		end;
		if c then begin
			xc:=xc+x1;
			yc:=yc+y1;
		end
		else zh1;
		//farmer
		if (map[xf+x2,yf+y2]<>'*')then
		case ff of
			1:if xf<>1 then f:=true;
			2:if yf<>10 then f:=true;
			3:if xf<>10 then f:=true;
			4:if yf<>1 then f:=true;
		end;
		if f then begin
			xf:=xf+x2;
			yf:=yf+y2;
		end
		else zh2;
		inc(total);
		if (xc=xf)and(yc=yf) then begin writeln(total);halt;end;
	end;
	writeln(0);
end;
procedure init;
var i,j:integer;
begin
	total:=0;
	x1:=-1;y1:=0;fc:=1;
	x2:=-1;y2:=0;ff:=1;
	for i:=1 to 10 do
	begin
		for j:=1 to 10 do
		begin
			read(map[i,j]);
			if map[i,j]='C' then //cow
				begin
					xc:=i;
					yc:=j;
				end;
			if map[i,j]='F' then //farmer
				begin
					xf:=i;
					yf:=j;
				end;
		end;
		readln;
	end;
end;
begin
  assign(input,'ttwo.in');
  reset(input);
  assign(output,'ttwo.out');
  rewrite(output);
  init;
  main;
  close(input);
  close(output);
end.