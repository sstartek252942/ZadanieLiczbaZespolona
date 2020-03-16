#include <iostream>
#include <cmath>
#include "LZespolona.hh"

/****************************************Praca na liczbach zespolonych****************************************/

LZespolona Utworz (double re, double im)
{
  LZespolona Wynik;
  Wynik.re = re;
  Wynik.im = im;
  return Wynik;
}

/*Praca na operatorach przesuniecia*/

/*
 * Wczytywanie ze strumienia liczby zespolonej
 */
std::istream & operator >>(std::istream & strm, LZespolona & Skl)
{
  char znak;
  strm>>znak;
  if (znak != '(') 
    strm.setstate(std::ios::failbit); 
  strm>>Skl.re>>Skl.im>>znak;
  if (znak != 'i') 
    strm.setstate(std::ios::failbit); 
  strm>>znak;
  if (znak != ')') 
    strm.setstate(std::ios::failbit); 
  return strm;
}

/*
 * Przekazywanie do strumienia liczby zespolonej
 */
std::ostream & operator <<(std::ostream & strm, LZespolona Skl)
{
  strm << '(' << Skl.re << std::showpos << Skl.im << std::noshowpos << 'i' << ')';// << std::endl;
  return strm;
}


/****************************************Obliczenia****************************************/


/*~
 * Sprzezenie zespolone
 */
LZespolona Sprzezenie (LZespolona  Skl)
{
  Skl.im *= -1;
  return Skl;
}

/*~
 * Modul liczby zespolonej
 */
double Modul (LZespolona  Skl)
{
  return sqrt((Skl.re * Skl.re) + (Skl.im * Skl.im));
}

/*!
 * Praca na operatorach arytmetycznych
 */

LZespolona  operator / (LZespolona  Skl,  double  a)
{
  Skl.re /= a;
  Skl.im /= a;
  return Skl;
}

/*Operacje porownania liczb zespolonych*/

bool  operator == (LZespolona  Skl1,  LZespolona  Skl2)
{
  return (Skl1.im == Skl2.im && Skl1.re == Skl2.re);
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
  Wynik = (Skl1 * Sprzezenie(Skl2)) / (Modul(Skl2)*Modul(Skl2));
  return Wynik;
}
