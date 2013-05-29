program prefix;
  var c:packed array[1..200000]of char;  //基元序列
      h:packed array[0..200000]of boolean;  //dp方程
      table:array[1..200]of string;  //字典
      l,n,ans,i,j:longint;
      ch:char;
  function equal(st:longint;s:string):boolean;  
//以st+1为开头st+length(s)为结尾的字串与s是否相等.
//这种设置会使后面主程序很方便.
    var i,l:longint;
    begin
      l:=length(s);
      for i:=1 to l do
        if s[i]<>c[st+i]
          then exit(false);
      exit(true);
    end;
  function max(a,b:longint):longint;
    begin
      if a>b
        then exit(a)
        else exit(b);
    end;
  begin
    assign(input,'prefix.in');
    assign(output,'prefix.out');
    reset(input);
    rewrite(output);
    fillchar(h,sizeof(h),0);
    l:=0;
    n:=1;
    read(ch);
    while ch<>'.'do
      begin
        if(ord(ch)>=ord('A'))and(ord(ch)<=ord('Z'))
          then table[n]:=table[n]+ch
          else inc(n);
        read(ch);
      end;
    read(ch);
    while not eof do
      begin
        read(ch);
        if(ord(ch)>=ord('A'))and(ord(ch)<=ord('Z'))
          then begin
            inc(l);
            c[l]:=ch;
          end;
      end;  //上面是输入
    h[0]:=true;
    ans:=0;
    i:=0;
    while i<=ans do
      begin
        if h[i]
          then begin
            for j:=1 to n do
              if(length(table[j])+i<=l)and(equal(i,table[j]))
                then begin
                  h[i+length(table[j])]:=true;
                  ans:=max(ans,i+length(table[j]));
                end;
          end;
        inc(i);
      end;
    writeln(ans);
    close(input);
    close(output);
  end.