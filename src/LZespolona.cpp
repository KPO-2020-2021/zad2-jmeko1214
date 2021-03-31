#include "LZespolona.hh"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#define MIN_DIFF 0.0001

/*!
 * Realizuje porównanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwsza porównywana liczba zespolona,
 *    Skl2 - druga porównywana liczba zespolona.
 * Zwraca:
 *    True dla równych liczb zespolonych.
 */

void Wyswietl(LZespolona  WyrZ)
{
  cout << " (" << WyrZ.re << showpos << WyrZ.im << "i) " << noshowpos;
}

bool  operator == (LZespolona  Skl1,  LZespolona  Skl2)
{
  /*if ((Skl1.re == Skl2.re) && (Skl1.im == Skl2.im))
    return true;
  else
  return false;*/
  //alternatywnie, dla MIN_DIFF i wyników od użytkownika
  if(abs(Skl1.re - Skl2.re) <= MIN_DIFF && abs(Skl1.im - Skl2.im) <= MIN_DIFF)
    return true;
  else
    return false;
}

bool  operator != (LZespolona  Skl1,  LZespolona  Skl2)
{
  if (Skl1 == Skl2)
    return false;
  else
    return true;
}

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2){
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

/*!
 * Realizuje dzielenie liczby zespolonej przez skakar.
 * Argumenty:
 *    Skl1 - dzielona liczba zespolona,
 *    Skl2 - skalar-dzielnik.
 * Zwraca:
 *    Wynik dzielenia dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator / (LZespolona  Skl1,  double  Skl2){
  LZespolona  Wynik;
  if(Skl2==0)
    {
      cout<<"Blad! Nie mozna dzielic przez 0!"<<endl;
    }
  else
    {
      Wynik.re = Skl1.re / Skl2;
      Wynik.im = Skl1.im / Skl2;
    }
  return Wynik;
}

LZespolona sprzezenie (LZespolona Skl2)
{
  LZespolona Wynik;
  Wynik.re = Skl2.re;
  Wynik.im = -Skl2.im;
  return Wynik;
}

double modul2 (LZespolona Skl2)
{
  double Wynik;
  Wynik = (Skl2.re*Skl2.re) + (Skl2.im*Skl2.im);
  return Wynik;
}

LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;
  if(modul2(Skl2)==0)
    {
      cout<<"Blad! Nie mozna dzielic przez 0!"<<endl;
    }
  else
    {
      Wynik = (Skl1*sprzezenie(Skl2))/(modul2(Skl2));
    }
  return Wynik;
}

/*przeciozenie operatora wswietlania*/
ostream & operator << (ostream &StrmWyj, const LZespolona &LZesp)
{
  StrmWyj << setprecision(4)<< "(" << LZesp.re << showpos << LZesp.im <<noshowpos<<"i)";
  return StrmWyj;
}

/*przeciozenie operatora wczytania*/
istream & operator >> (istream &StrmWej, LZespolona &LZesp)
{
  char nawias, litera;
  StrmWej >> nawias;
  if(StrmWej.fail())
    {
      return StrmWej;
    }
  if(nawias != '(')
    {
      StrmWej.setstate(ios::failbit);
      return StrmWej;
    }
  StrmWej >> LZesp.re;
  if(StrmWej.fail())
    {
      return StrmWej;
    }
  StrmWej >> LZesp.im;
  if(StrmWej.fail())
    {
      return StrmWej;
    }
  StrmWej >> litera;
  if(StrmWej.fail())
    {
      return StrmWej;
    }
  if(litera != 'i')
    {
      StrmWej.setstate(ios::failbit);
      return StrmWej;
    }
  StrmWej >> nawias;
  if(StrmWej.fail())
    {
      return StrmWej;
    }
  if(nawias != ')')
    {
      StrmWej.setstate(ios::failbit);
      return StrmWej;
    }
  if(StrmWej.rdstate()==ios::failbit)
    {
      cerr<<"Blad zapisu liczby zespolonej!"<<endl;
      exit(0);
    }
  return StrmWej;  
}
