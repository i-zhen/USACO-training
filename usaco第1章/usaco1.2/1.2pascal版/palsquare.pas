{
ID: sacredf1
PROG: palsquare
LANG: PASCAL
}
program test;
var n,m,m2:longint;
	a,a2:array[1..1000000]of char;
procedure jinzhi(i:longint);
var q,r:longint;
	  k:string;
begin
	m:=0;
	q:=-1;
k:='';
	repeat
	begin
		q:=i div n ;
		r:=i mod n ;
		if r<10 then str(r,k) else
		case r of
		10:k:='A';
		11:k:='B';
		12:k:='C';
		13:k:='D';
		14:k:='E';
		15:k:='F';
		16:k:='G';
		17:k:='H';
		18:k:='I';
		19:k:='J';
		20:k:='K';
		end;
	    i:=q;
		inc(m);
		a[m]:=k[1];
	end
	until q=0;
	for i:=1 to m div 2  do
	begin
		k[1]:=a[i];
		a[i]:=a[m-i+1];
		a[m-i+1]:=k[1];
	end;
end;
procedure jinzhi2(i:longint);
var q,r:longint;
	  k:string;
begin
	m2:=0;
	q:=-1;
k:='';
	repeat
	begin
		q:=i div n ;
		r:=i mod n ;
		if r<10 then str(r,k) else
		case r of
		10:k:='A';
		11:k:='B';
		12:k:='C';
		13:k:='D';
		14:k:='E';
		15:k:='F';
		16:k:='G';
		17:k:='H';
		18:k:='I';
		19:k:='J';
		20:k:='K';
		end;
	    i:=q;
		inc(m2);
		a2[m2]:=k[1];
	end
	until q=0;
	for i:=1 to m2 div 2  do
	begin
		k[1]:=a2[i];
     	a2[i]:=a2[m2-i+1];
		a2[m2-i+1]:=k[1];
	end;
end;
procedure panduan(b:integer);
	var i:integer;
	flag:boolean;
begin
	flag:=true;
	for i:=1 to m do
        if a[i]<>a[m-i+1] then flag:=false ;
	if flag then 
		begin
			
			for i:=1 to m2 do
		       write(a2[i]);
		    write(' ');
			for i:=1 to m do
		       write(a[i]);
		writeln;
		end;
end;
procedure main;
var i,j:integer;
	q:string;	flag:boolean;
begin
	readln(n);
    for i:=1 to 300 do
    begin
		if n<>10 then
		begin
			jinzhi(i*i);
		    jinzhi2(i);
			panduan(i);
		end
		else
		begin
			str(i*i,q);
			flag:=true;
	        for j:=1 to (length(q) div 2)+1 do
               if q[j]<>q[length(q)-j+1] then flag:=false ;
	        if flag then 
			    writeln(i,' ',i*i);
		end;
	end;
end;
begin
  assign(input,'palsquare.in');
  reset(input);
  assign(output,'palsquare.out');
  rewrite(output);
  main;
  close(input);
  close(output);
end.