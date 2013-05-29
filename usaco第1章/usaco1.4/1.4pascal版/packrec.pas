program packrec;
const    
	maxn=8;
	maxans=40;
	change:array[1..4] of shortint=(5,6,7,8);
	mod4:array[1..8] of shortint=(0,1,2,3,0,1,2,3);
type
	rect=record
		h,w:integer;
	end;
var
	raw:array[1..maxn] of rect;
	ans:array[1..maxans]of rect;
	min,total:integer;
procedure assignfile;
begin
	assign(input,'packrec.in');
	reset(input);
	assign(output,'packrec.out');
	rewrite(output);
end;
procedure closefile;
begin
	close(input);
	close(output);
end;
procedure init;
var
	i,x,y:integer;
begin
	for i:=1 to 4 do
	begin
		readln(x,y); 
		raw[i].h:=y;
		raw[i].w:=x;
		raw[change[i]].h:=x;
		raw[change[i]].w:=y;
	end;
end;
procedure swap(var x,y:integer);
var
	temp:integer;
begin
	temp:=x;
	x:=y;
	y:=temp;
end;
procedure check(x,y:integer);
var
	i:integer;
	temp:integer;
begin
	if x<y then  swap(x,y);
		temp:=x*y;
	if temp<=min then
		begin
			if temp<min then total:=0;
				min:=temp;
			for i:=1 to total do if (ans[i].h=x)and(ans[i].w=y) then exit;
				inc(total);
			ans[total].h:=x;
			ans[total].w:=y;
		end;
end;
function max(x,y:integer):integer;
begin
	if x>y then exit(x) else exit(y);
end;
procedure swap_rect(var x,y:rect);
var     
temp:rect;
begin
	temp:=x;
	x:=y;
	y:=temp;
end;
procedure sort;
var     i,j:integer;
begin
	for i:=1 to (total-1) do
		for j:=(i+1) to total do  
		if ans[i].w>ans[j].w then
			swap_rect(ans[i],ans[j]);end;
procedure work;
var     i1,i2,i3,i4,x,y,i:integer;
begin
	total:=0;
	min:=maxint;
	for i1:=1 to maxn do
		for i2:=1 to maxn do 
		if (mod4[i2])<>(mod4[i1]) then
			for i3:=1 to maxn do
			if ((mod4[i3])<>(mod4[i1]))and((mod4[i3])<>(mod4[i2])) then 
				for i4:=1 to maxn do
				if ((mod4[i4])<>(mod4[i1]))and((mod4[i4])<>(mod4[i2]))and((mod4[i4])<>(mod4[i3])) then
					begin
						{-----1-------}
						y:=0; x:=0;
						x:=raw[i1].w+raw[i2].w+raw[i3].w+raw[i4].w;  
						y:=max(raw[i1].h,raw[i2].h); y:=max(y,raw[i3].h); y:=max(y,raw[i4].h); 
						check(x,y);
						{-----2-------}
						x:=max(raw[i2].w+raw[i3].w+raw[i4].w,raw[i1].h);  
						y:=0; y:=max(y,raw[i2].h); y:=max(y,raw[i3].h); y:=max(y,raw[i4].h); 
						inc(y,raw[i1].w); 
						check(x,y);
						{-----3-------}
						y:=max(raw[i2].h,max(raw[i3].h,raw[i4].h)+raw[i1].w);     
						x:=max(raw[i3].w+raw[i4].w,raw[i1].h)+raw[i2].w;
						check(x,y);
						{-----4/5-----}
						x:=raw[i3].w+raw[i4].w+max(raw[i1].w,raw[i2].w); 
						y:=max(raw[i3].h,raw[i4].h); y:=max(y,raw[i1].h+raw[i2].h); 
						check(x,y);
						{-----6-------}
						y:=max(raw[i1].h+raw[i2].h,raw[i3].h+raw[i4].h);  
						x:=max(raw[i2].w,raw[i4].w); x:=max(x,raw[i1].w+raw[i3].w);
						if raw[i1].h>raw[i3].h then x:=max(x,raw[i1].w+raw[i4].w);
						if raw[i3].h>raw[i1].h then x:=max(x,raw[i3].w+raw[i2].w);
						if raw[i1].h+raw[i2].h>raw[i3].h then x:=max(x,raw[i2].w+raw[i4].w);
						check(x,y);                                 
					 end;
	sort;
	writeln(min);
	for i:=1 to total do
		writeln(ans[i].w,' ',ans[i].h)
end;
begin
	assignfile;
	init;
	work;
	closefile;
end.
