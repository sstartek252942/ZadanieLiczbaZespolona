#include <iostream>
#include <cmath>
#include "LZespolona.hh"

bool Wczytaj (LZespolona & Skl)
{
  std::cout<<"   Twoja odpowiedz: ";
  char znak;
  std::cin>>znak;
  if (znak != '(') return false; 
  std::cin>>Skl.re>>Skl.im>>znak;
  if (znak != 'i') return false; 
  std::cin>>znak;
  if (znak != ')') return false; 
  return true;
}

LZespolona Utworz (double re, double im)
{
  LZespolona Wynik;
  Wynik.re = re;
  Wynik.im = im;
  return Wynik;
}

void Wyswietl (LZespolona Skl)
{
  std::cout << '(' << Skl.re << std::showpos << Skl.im << std::noshowpos << 'i' << ')';// << std::endl;
}

/*~
 * Sprzezenie zespolone
 */
LZespolona SZ (LZespolona  Skl)
{
  Skl.im *= -1;
  return Skl;
}

/*~
 * Modul liczby zespolonej
 */
double MZ (LZespolona  Skl)
{
  return sqrt((Skl.re * Skl.re) + (Skl.im * Skl.im));
}

LZespolona  operator / (LZespolona  Skl,  double  a)
{
  Skl.re /= a;
  Skl.im /= a;
  return Skl;
}

bool  operator == (LZespolona  Skl1,  LZespolona  Skl2)
{
  return (Skl2.im == Skl2.im && Skl1.re == Skl2.re);
}

bool  operator != (LZespolona  Skl1,  LZespolona  Skl2)
{
  return (Skl2.im != Skl2.im || Skl1.re != Skl2.re);
}

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */

LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}

LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}

LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re * Skl2.re - Skl1.im * Skl2.im;
  Wynik.im = Skl1.re * Skl2.im + Skl1.im * Skl2.re;
  return Wynik;
}

LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;
  Wynik = (Skl1 * SZ(Skl2)) / (MZ(Skl2)*MZ(Skl2));
  return Wynik;
}
