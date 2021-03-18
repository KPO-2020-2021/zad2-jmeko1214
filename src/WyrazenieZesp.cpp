#include "WyrazenieZesp.hh"
#include <iostream>

using namespace std;

/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */

void Wyswietl(WyrazenieZesp WyrZ)
{
  cout << LZespolona << WyrZ << endl;
}

LZespolona Oblicz(WyrazenieZesp  WyrZ)
{
  LZespolona Wynik;
  switch(WyrZ.Op)
    {
    case Operator::Op_Dodaj:
      {
	Wynik=WyrZ.Arg1+WyrZ.Arg2;
	return Wynik;
	break;
      }
    case Operator::Op_Odejmij:
      {
	Wynik=WyrZ.Arg1-WyrZ.Arg2;
	return Wynik;
	break;
      }
    case Operator::Op_Mnoz:
      {
	Wynik=WyrZ.Arg1*WyrZ.Arg2;
	return Wynik;
	break;
      }
    case Operator::Op_Dziel:
      {
	Wynik=WyrZ.Arg1/WyrZ.Arg2;
	return Wynik;
	break;
      }
    default:
      {
	cout<<"Nie rozpoznano dzialania"<<endl;
	Wynik.re=0;
	Wynik.im=0;
	return Wynik;
	break;
      }
    }

}
