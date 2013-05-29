const
    prog_name='clocks';
    fd:array [1..9,1..9] of integer = (
    //(A,B,C,D,E,F,G,H,I)
    (3,3,0,3,3,0,0,0,0),// ABDE
    (3,3,3,0,0,0,0,0,0),// ABC
    (0,3,3,0,3,3,0,0,0),// BCEF
    (3,0,0,3,0,0,3,0,0),// ADG
    (0,3,0,3,3,3,0,3,0),// BDEFH
    (0,0,3,0,0,3,0,0,3),// CFI
    (0,0,0,3,3,0,3,3,0),// DEGH
    (0,0,0,0,0,0,3,3,3),// GHI
    (0,0,0,0,3,3,0,3,3));// EFHI
procedure assignfile;
    begin
        assign(input,prog_name+'.in');
        reset(input);
        assign(output,prog_name+'.out');
        rewrite(output);
    end;
procedure closefile;
    begin
        close(input);
        close(output);
    end;
var
    i,j,p,r,k:longint;
    c,d:array [0..262144,0..9] of shortint;
begin
    assignfile;
    fillword(c,sizeof(c) shr 1,0);
    fillword(d,sizeof(d) shr 1,0);
    for i:=1 to 3 do
    begin
        for j:=1 to 3 do
        begin
            read(d[1,i*3-3+j]);
            if d[1,i*3-3+j]=12 then
                d[1,i*3-3+j]:=0;
            inc(d[1,0],d[1,i*3-3+j]);
        end;
        readln;
    end;
    c[1,0]:=1;
    p:=1;
    r:=0;
    while r<p do
    begin
        inc(r);
        for i:=c[r,0] to 9 do//?
            if c[r,i]<3 then
            begin
                inc(p);
                for j:=1 to 9 do
                begin
                    d[p,j]:=(d[r,j]+fd[i,j]) mod 12;
                    inc(d[p,0],d[p,j]);
                end;
                c[p]:=c[r];
                inc(c[p,i]);
                c[p,0]:=i;//?
                if d[p,0]=0 then
                begin
                    r:=p;
                    break;
                end;
            end;
    end;
    p:=0;
    for i:=1 to 9 do
        for j:=1 to c[k,i] do
        begin
            inc(p);
            if p>1 then
                write(' ',i)
            else
                write(i);
        end;
    writeln;
    closefile;
end.