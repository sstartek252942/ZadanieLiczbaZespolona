#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
};


bool Wczytaj (LZespolona & Skl);
LZespolona Utworz (double re, double im);
void Wyswietl (LZespolona);

/*
 * Dalej powinny pojawic sie zapowiedzi definicji bez przeciazen operatorow
 */

LZespolona  SZ (LZespolona  Skl);
double	  MZ (LZespolona  Skl);

/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */


bool  operator == (LZespolona  Skl1,  LZespolona  Skl2);
bool  operator != (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona  operator / (LZespolona  Skl,  double  a);

LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2);

#endif
