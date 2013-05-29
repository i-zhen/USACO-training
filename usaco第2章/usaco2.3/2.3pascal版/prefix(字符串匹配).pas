program prefix;
const cht=['A'..'Z'];
var i,j,n,t:longint;
    tmp:char;
    temp,s:ansistring;
    a:array[1..200]of string[10];
    f:array[0..200000]of boolean;
begin
 assign(input,'prefix.in');
 reset(input);
 assign(output,'prefix.out');
 rewrite(output);
 t:=1;
 while tmp<>'.'  do
  begin
   read(tmp);
   if tmp in cht then
    a[t]:=a[t]+tmp
   else inc(t);
  end;
 while not eof do
  begin
   readln(temp);
   s:=s+temp;
  end;
 dec(t);
 n:=length(s);
 f[0]:=true;
 for i:=1 to n do
  for j:=1 to t do
   if length(a[j])<=i then
    if copy(s,i-length(a[j])+1,length(a[j]))=a[j] then
     if f[i-length(a[j])] then
      begin
       f[i]:=true;
       break;
      end;
 for i:=n downto 0 do
  if f[i] then
   begin
    writeln(i);
    halt;
   end;
 close(input);
 close(output);
end.
