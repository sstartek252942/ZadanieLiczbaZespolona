#include <iostream>
#include "WyrazenieZesp.hh"


/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */

void Wyswietl(WyrazenieZesp  WyrZ)
{
  std::cout<<":? Podaj wynik operacji: ";
  Wyswietl(WyrZ.Arg1);
  switch (WyrZ.Op)
  {
  	case Op_Dodaj: 	std::cout<<" + "; break;
  	case Op_Odejmij:std::cout<<" - "; break;
  	case Op_Mnoz: 	std::cout<<" * "; break;
  	case Op_Dziel: 	std::cout<<" / "; break;
  }
  Wyswietl(WyrZ.Arg2);
  std::cout<<" ="<<std::endl;
}



LZespolona Oblicz(WyrazenieZesp  WyrZ)
{
  switch (WyrZ.Op)
  {
  	case 0: 	 return WyrZ.Arg1 + WyrZ.Arg2; break;
  	case 1: return WyrZ.Arg1 - WyrZ.Arg2; break;
  	case 2: 	 return WyrZ.Arg1 * WyrZ.Arg2; break;
  	case 3: 	 return WyrZ.Arg1 / WyrZ.Arg2; break;
  }
  std::cout << "Blad programu"<<std::endl;
  return WyrZ.Arg1;
}
