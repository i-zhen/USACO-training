{
ID: sacredf1
PROG: runround
LANG: PASCAL
}
program test;
var num,l,q,wz:cardinal;
	s:string;
	a:array[1..25]of integer;
	b:array[1..25]of boolean;
procedure bh(nu:cardinal);
var i,j:integer;

begin
	fillchar(a,sizeof(a),0);
	str(nu,s);l:=length(s);
	for i:=l downto 1 do
	begin
		a[i]:=nu mod 10;
		nu:=nu div 10;
		b[i]:=false;
	end;
	
end;
procedure pd;
var i,tem,t2:cardinal;
begin
	i:=1;tem:=0;t2:=0;
		while tem<l do//point
		begin
			wz:=a[i] mod l;
			if (tem>0) then
				if wz+i<=l then if (wz+i)=t2 then exit
				else if (wz-(l-i))=t2 then exit;
			inc(tem);
			if wz+i<=l then begin q:=a[i+wz];b[i+wz]:=true;i:=i+wz;end
				else begin wz:=wz-(l-i);q:=a[wz];b[wz]:=true;i:=wz;end;
			t2:=wz;
		end;
end;
function qq:boolean;
var i:integer;
begin
	for i:=1 to l do
		if not b[i] then exit(false);
	exit(true);
end;
procedure main;
var i,j:cardinal;
		f:boolean;
begin
	while true do
	begin
		q:=-1;wz:=-1;
		inc(num);
		bh(num);
		f:=true;
		while f do
		begin
		f:=false;
		for i:=1 to l do
		for j:=1 to l do
			if i<>j then 
			if (a[i]=a[j] )or (a[i]=0)or (a[j]=0) then begin f:=true;break;end;
			if f then begin inc(num);bh(num);end;
		end;
		pd;
		if (q=a[1]) and qq then begin writeln(num);exit;end;
	end;
end;
procedure init;
begin
	readln(num);
	main;
end;
begin
  assign(input,'runround.in');
  reset(input);
  assign(output,'runround.out');
  rewrite(output);
  init;
  close(input);
  close(output);
end.