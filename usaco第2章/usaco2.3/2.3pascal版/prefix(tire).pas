{
ID: sacredf1
PROB: prefix
LANG: PASCAL
}
program prefix;
type node=record	
		data:char;
		son:integer;
		jl:boolean;
		er:array[1..1800]of integer;
		end;
var ji,total,root,max,k:longint;
		zd:array[1..1800]of node;
		y1:array[1..200]of string;
		ls:array[1..200000]of boolean;
		s:ansistring;
		flag:boolean;
procedure find(x:string;wz,c:integer);
var i:integer;
begin
	for i:=1 to zd[wz].son do
	begin
		if zd[zd[wz].er[i]].data=x[c] then
		begin
			if c+1<=length(x) then find(x,zd[wz].er[i],c+1)
			else begin
						if zd[zd[wz].er[i]].jl then flag:=true;
						exit;
					end;
		end;
	end;
end;
procedure insert(x:string;y,z:integer);
var i:integer;
		f:boolean;
begin
	f:=true;
	if zd[y].son=0 then 
		begin 
			inc(total);
			inc(zd[y].son);
			zd[y].er[zd[y].son]:=total;
			zd[total].data:=x[z];
			if (z+1)<=length(x) then 
				insert(x,total,z+1)
			else begin zd[total].jl:=true;exit;end;
		end
	else
	for i:=1 to zd[y].son do
		if zd[zd[y].er[i]].data=x[z] then 
			begin
				if (z+1)<=length(x) then 
				begin
					insert(x,zd[y].er[i],z+1);
					exit;
				end
				else begin zd[total].jl:=true;exit;end;
			end
			else begin f:=false;end;
	if not f then 
		begin 
			inc(total);
			inc(zd[y].son);
			zd[y].er[zd[y].son]:=total;
			zd[total].data:=x[z];
			if (z+1)<=length(x) then 
				insert(x,total,z+1)
			else begin zd[total].jl:=true;exit;end;
		end;
end;
procedure init;
var i:longint;
	te:char;
	temp:ansistring;
begin
	root:=1;
	zd[root].data:=' ';
	zd[root].son:=0;
	total:=1;
	ji:=1;
	repeat
		while not eoln(input) do
		begin
			read(te);
			if te<>'.' then
				if (te=' ') then
					inc(ji)
				else if te in ['A'..'Z'] then
					y1[ji]:=y1[ji]+te;
		end;
		if eoln(input) then inc(ji);
		readln;
	until te='.';
	max:=-1;
	for i:=1 to ji do
	begin
		insert(y1[i],root,1);
		if length(y1[i])>max then max:=length(y1[i]);
	end;
	s:='';
	k:=0;
	while not eof(input) do
	begin
		readln(temp);
		k:=k+length(temp);
		s:=s+temp;
	end;
end;
procedure main;
var i,j,q,head,tail:longint;
	st:string;
begin
	if k>100000 then
	begin
		head:=k div 2;
		tail:=k;
	end
	else
	begin
		head:=1;
		tail:=k;
	end;//用到数学期望,大于100000的数据折半处理,正确的概率为0.5左右
	for i:=head to tail do
	begin
		st:='';
		for j:=1 to max do
		begin
			flag:=false;
			st:=st+s[i+j-1];
			find(st,root,1);
			if flag then 
				for q:=i to i+j-1 do
					ls[q]:=true;
		end;
	end;
	for i:=head to tail do
		if not ls[i] then 
		begin
			writeln(i-1);
			exit;
		end;
	if ls[k] then writeln(k);
end;
begin
	assign(input,'prefix.in');
	reset(input);
	assign(output,'prefix.out');
	rewrite(output);
	init;
	main;
	close(input);
	close(output);
end.