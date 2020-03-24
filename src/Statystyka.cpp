#include <iostream>
#include "Statystyka.hh"

using std::cout;
using std::endl;

Statystyka Inicjuj (Statystyka & Stats)
{
  Stats.p = 0;
  Stats.b = 0;
  return Stats;
}

void Poprawna (Statystyka & Stats)
{	
  Stats.p++;
}

void Bledna (Statystyka & Stats)
{
  Stats.b++;
}

int Wszystkie(Statystyka & Stats)
{
  return Stats.b+Stats.p;
}

double Procent (Statystyka & Stats)
{
  return Stats.p * 100 / Wszystkie(Stats);
}

std::ostream & operator << (std::ostream & strm, Statystyka & Stats)
{
  strm << " Ilosc pytan:" << Wszystkie(Stats) << endl;
  strm << " Poprawne:" << Stats.p << endl;
  strm << " Bledne:" << Stats.b << endl;
  strm << " Procent poprawnych:" << Procent(Stats) << '%' << endl;

  return strm;
}
