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

double Procent (Statystyka & Stats)
{
  return Stats.p / (Stats.b+Stats.p)*100;
}

void Wyswietl (Statystyka & Stats)
{
  cout << " Ilosc pytan:" << Stats.p + Stats.b << endl;
  cout << " Poprawne:" << Stats.p << endl;
  cout << " Bledne:" << Stats.b << endl;
  cout << " Procent poprawnych:" << Procent(Stats) << '%' << endl;
}
