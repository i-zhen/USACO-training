{
ID: sacredf1
PROG: nocows
LANG: PASCAL
}
program nocows;
var
  n,p,i,j,k:longint;
  dp:array[1..200,0..100]of longint;
begin
  assign(input,'nocows.in');
  assign(output,'nocows.out');
  reset(input);
  rewrite(output);
  readln(n,k);
  for i:=1 to k do
    dp[1,i]:=1;
  for j:=1 to k do
    for i:=1 to n do
    begin
      if not odd(i) then
        continue;
      for p:=1 to i-2 do
        dp[i,j]:=(dp[i,j]+dp[p,j-1]*dp[i-1-p,j-1])mod 9901;
    end;
    writeln((dp[n,k]+9901-dp[n,k-1]) mod 9901);
    close(input);
    close(output);
end.