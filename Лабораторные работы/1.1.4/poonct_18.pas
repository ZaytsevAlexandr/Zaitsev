program poonct_18_lab_114_not_for_sale;
var
  kolpodxod, i, n, tau, kol, x: integer;
  standotklon, sredn, procent: real;
  f: text;
begin
  kolpodxod:= 0;
  writeln('Enter your tau: ');
  readln(tau);
  x:= 4000 div tau;
  writeln('Enter your sredn (with dots): ');
  readln(sredn);
  writeln('Enter your standart otklon: ');
  readln(standotklon);
  writeln('Choose your number of standart otklon (1 or 2 or 3): ');
  readln(kol);
  assign(f, 'C:\Users\sasha\Documents\Лабораторные работы\1.1.4\tau_10.txt');
  reset(f);
  for i:=1 to x do
  begin
    readln(f, n);
    if abs((n - sredn)) <= kol*standotklon
      then 
        kolpodxod:=kolpodxod + 1;
  end;
  procent:=kolpodxod / x;
  writeln('Your result: ',procent*100,'%');
  close(f);
end.