    program counter_for_tau;
  var 
    i, j, number_1, number_2: integer;
    f: text;
  begin
    assign(f,'C:\Users\sasha\Documents\Лабораторные работы\1.1.4\dannie.txt');
    reset(f);
    number_2:=0;
    for i:=1 to 100 do
      begin
        for j:=1 to 40 do
          begin
            readln(f,number_1);
            number_2:=number_2 + number_1;
          end;
         writeln(number_2);
         number_2:=0;
       end;
    close(f);
  end.
        