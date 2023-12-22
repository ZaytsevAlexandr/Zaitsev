    program counter_w;
  var
    kol: array[39..73] of integer;
    w: array[39..73] of real;
    f: text;
    number, i, j, e: integer;
    exitsum: real;
  begin
    assign(f,'C:\Users\sasha\Documents\Лабораторные работы\1.1.4\tau_40.txt');
    reset(f);
    for i:= 1 to 100 do
      begin
        readln(f,number);
        for j:= 39 to 73 do
          begin
            if number = j
              then kol[j]:=kol[j] + 1;
        end;
      end;
    for e:=39 to 73 do
    begin
      w[e]:= kol[e] / 100;
      writeln(w[e],' ');
    end;
    for e:=39 to 73 do
      exitsum:=exitsum + w[e];
    writeln();
    writeln('Должно быть единицa: ',exitsum);
  end.