#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include <iostream>

using namespace std;

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


/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */

/*przeciazenia operatorow*/
bool  operator == (LZespolona  Skl1,  LZespolona  Skl2);
bool  operator != (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator / (LZespolona Skl1, double Skl2);  //liczba zespolona przez skalar
LZespolona sprzezenie (LZespolona Skl);
double modul2 (LZespolona Skl);

/*przeciazenie operatorow wczytania i wyswietlania klasy LZespolona*/
ostream & operator << (ostream &StrmWyj, const LZespolona &LZesp);
istream & operator >> (istream &StrmWej, LZespolona &LZesp);


#endif
