Var
  c:char;
  fit,seq:string;
  i,j,l,p,lp:longint;
  ans:array[0..200000]of longint;
  primitives:array[1..200]of string;
Function exist(si:string):boolean;
  Begin
    For j:=1 to lp do If primitives[j]=si then exit(true);
    exit(false)
  End;
Begin
  assign(input,'prefix.in');  reset(input);
  assign(output,'prefix.out');  rewrite(output);
  seq:='           ';  //用字符串模拟队列 因为最长primitive只有10位 所以只记录11位
  fit:='00000000001';  //对应队列每一位 记录该位是(1)否(0)为一个前缀的末尾
  ans[0]:=0;  lp:=1;   //ans[n]为以第n为结尾的 最长前缀的长度
  Repeat               //读入primitives
    read(c);
    Case c of
      ' ':inc(lp);
      'A'..'Z':primitives[lp]:=primitives[lp]+c
    End;
    If eoln then      //行结束
      Begin
        readln;  inc(lp)
      End
  Until c='.';
  Repeat
    read(c);
    If eoln then readln;
    seq:=copy(seq,2,10)+c;  //进队
     fit:=copy(fit,2,10)+'0';
    inc(l);  ans[l]:=ans[l-1];
    For p:=10 downto 1 do
      If (fit[p]='1')and(exist(copy(seq,p+1,11-p))) then //暂且可以称之为dp
        Begin
          fit:=copy(fit,1,10)+'1';
          ans[l]:=ans[l+p-11]+11-p;
          break
        End;
  Until (eof)or(fit='00000000000');//如果连续11个都不满足要求 明显前缀结束
  writeln(ans[l]);
  close(input);  close(output)
End.
