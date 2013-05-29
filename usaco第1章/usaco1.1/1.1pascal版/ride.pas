{
ID: sacredf1
PROG: ride
LANG: PASCAL
}

program ride;
var i,j,t1,t2:longint;
    z1,z2:string;
function zifu(d:char):integer;
begin
   zifu:=ord(d)-64;
end;
procedure pan(x,y:longint);
begin
  if (x mod 47 )=(y mod 47) then writeln('GO') else writeln('STAY');
end;
begin
  assign(input,'ride.in');
  reset(input);
  assign(output,'ride.out');
  rewrite(output);
  readln(z1);
  readln(z2); 
  t1:=0;
  t1:=zifu(z1[1]);
  for i:=2 to length(z1) do
  begin
    t1:=t1*zifu(z1[i]);
  end;
  t2:=zifu(z2[1]);
  for j:=2 to length(z2) do
  begin
    t2:=t2*zifu(z2[j]);
  end;
  pan(t1,t2);
  close(input);
  close(output);
end.