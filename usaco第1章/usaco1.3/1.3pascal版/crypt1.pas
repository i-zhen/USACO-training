{
ID: sacredf1
PROG: crypt1
LANG: PASCAL
}
program crypt1 (input,output);
var nu:array['1'..'9'] of boolean; 
n:1..10;
k,i,j,tot:longint;
function zai(x:longint):boolean;
var s:string;  
i:longint;
begin 
	str(x,s);
    for i:=1 to length(s) do 
    if not(nu[s[i]]) then exit(false); 
	exit(true);
end;
begin 
	assign(input,'crypt1.in'); 
assign(output,'crypt1.out'); 
reset(input); 
rewrite(output); 
readln(n); 
for i:=1 to n do begin read(k);nu[char(k+ord('0'))]:=true;end; 
	tot:=0; 
   for i:=100 to 999 do{三位数乘二位数}  
    for j:=10 to 99 do begin 
	if(i*(j div 10)<=999)and(i*(j mod 10)<=999)and(i*j<=9999)  
		and(i*(j div 10)>=100)and(i*(j mod 10)>=100)and(i*j>=1000) 
	and((zai(i))and(zai(j))and(zai(i*(j div 10)))and(zai(i*(j mod 10)))and(zai(i*j)))  
	then inc(tot); 
	end; 
	writeln(tot); 
	close(input); 
	close(output)
end.