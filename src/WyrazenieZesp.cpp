#include <iostream>
#include "WyrazenieZesp.hh"


/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */

std::ostream & operator << (std::ostream & strm, WyrazenieZesp WyrZ)
{
  strm<<WyrZ.Arg1<<WyrZ.Op<<WyrZ.Arg2;
  return strm;
}

std::ostream & operator << (std::ostream & strm, Operator Op)
{
  switch (Op)
  {
  	case Op_Dodaj:   strm<<" + "; break;
  	case Op_Odejmij: strm<<" - "; break;
  	case Op_Mnoz:    strm<<" * "; break;
  	case Op_Dziel:   strm<<" / "; break;
  }
  return strm;
}

std::istream & operator >> (std::istream & strm, WyrazenieZesp & WyrZ)
{
  strm >> WyrZ.Arg1 >> WyrZ.Op >> WyrZ.Arg2;
  return strm;
}

std::istream & operator >> (std::istream & strm, Operator & Op)
{
  char znak;
  strm >> znak;
  switch(znak) 
  {
    case '+': Op = Op_Dodaj;	break;
    case '-': Op = Op_Odejmij;	break;
    case '*': Op = Op_Mnoz;	break;  
    case '/': Op = Op_Dziel;	break;
    default: strm.setstate(std::ios::failbit); 	break;
  }
  //std::cout<<"YES"<<std::endl;
  return strm;
}

LZespolona Oblicz(WyrazenieZesp  WyrZ)
{
  switch (WyrZ.Op)
  {
  	case Op_Dodaj:   return WyrZ.Arg1 + WyrZ.Arg2; break;
  	case Op_Odejmij: return WyrZ.Arg1 - WyrZ.Arg2; break;
  	case Op_Mnoz:    return WyrZ.Arg1 * WyrZ.Arg2; break;
  	case Op_Dziel:   return WyrZ.Arg1 / WyrZ.Arg2; break;
  }
  std::cout << "Blad programu"<<std::endl;
  return WyrZ.Arg1;
}
