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


std::istream & operator >>(std::istream & strm, LZespolona & Skl);
std::ostream & operator <<(std::ostream & strm, LZespolona Skl);

LZespolona Utworz (double re, double im);

/*
 * Dalej powinny pojawic sie zapowiedzi definicji bez przeciazen operatorow
 */

LZespolona  Sprzezenie (LZespolona  Skl);
double	  Modul (LZespolona  Skl);

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
