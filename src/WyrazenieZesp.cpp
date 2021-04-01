#include <iostream>
#include <cstdlib>
#include "WyrazenieZesp.hh"
#include "LZespolona.hh"


using namespace std;

/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */
/*
void Wyswietl(WyrazenieZesp WyrZ)
{
  if(WyrZ.Arg1.re==0)
    {
      if(WyrZ.Arg1.im==0)
	{
	  cout<<"0";
	}
      else
	{
	  cout<<"("<<showpos<<WyrZ.Arg1.im<<noshowpos<<"i)";
	}
    }
  else
    {
      if(WyrZ.Arg1.im==0)
	{
	  cout<<"("<<WyrZ.Arg1.re<<")";
	}
      else
	{
	  cout<<"("<<WyrZ.Arg1.re<<showpos<<WyrZ.Arg1.im<<noshowpos<<"i)";
	}
    }
    }*/

LZespolona Oblicz(WyrazenieZesp  WyrZ)
{
  LZespolona Wynik;
  switch(WyrZ.Op)
    {
    case Operator::Op_Dodaj:
      {
	Wynik= operator + (WyrZ.Arg1,WyrZ.Arg2);
	return Wynik;
	break;
      }
    case Operator::Op_Odejmij:
      {
        Wynik= operator - (WyrZ.Arg1,WyrZ.Arg2);
	return Wynik;
	break;
      }
    case Operator::Op_Mnoz:
      {
        Wynik= operator * (WyrZ.Arg1,WyrZ.Arg2);
	return Wynik;
	break;
      }
    case Operator::Op_Dziel:
      {
        Wynik= operator / (WyrZ.Arg1,WyrZ.Arg2);
	return Wynik;
	break;
      }
    case Operator::Op_PlusRowna:
      {
        Wynik= operator += (WyrZ.Arg1,WyrZ.Arg2);
	return Wynik;
	break;
      }
    case Operator::Op_DzielRowna:
      {
        Wynik= operator /= (WyrZ.Arg1,WyrZ.Arg2);
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

ostream & operator << (ostream & StrmWyj, const WyrazenieZesp & LZesp)
{
  StrmWyj << LZesp.Arg1;
  if(StrmWyj.fail())
    {
      return StrmWyj;
    }
  if(LZesp.Op==Operator::Op_Dodaj)
    {
      StrmWyj << "+";
    }
  else if(LZesp.Op==Operator::Op_Odejmij)
    {
      StrmWyj << "-";
    }
  else if(LZesp.Op==Operator::Op_Mnoz)
    {
      StrmWyj << "*";
    }
  else if(LZesp.Op==Operator::Op_Dziel)
    {
      StrmWyj << "/";
    }
  else if(LZesp.Op==Operator::Op_PlusRowna)
    {
      StrmWyj << "+=";
    }
  else if(LZesp.Op==Operator::Op_DzielRowna)
    {
      StrmWyj << "/=";
    }
  if(StrmWyj.fail())
    {
      return StrmWyj;
    }
  StrmWyj << LZesp.Arg2;
  if(StrmWyj.fail())
    {
      return StrmWyj;
    }
  return StrmWyj;
 
}

istream & operator >> (istream & StrmWej, Operator & Op)
{
  char znak;
  StrmWej >> znak;
  switch(znak)
    {
    case '+':
      {
	switch(znak)
	  {
	  case' ':
	    {
	      Op = Op_Dodaj;
	      break;
	    }
	  case '=':
	    {
	      Op = Op_PlusRowna;
	      break;
	    }
	  }
      }
    case '-':
      {
        Op = Op_Odejmij;
	break;
      }
    case '*':
      {
        Op = Op_Mnoz;
	break;
      }
    case '/':
      {
	switch(znak)
	  {
	  case ' ':
	    {
	      Op = Op_Dziel;
	      break;
	    }
	  case '=':
	    {
	      Op = Op_DzielRowna;
	      break;
	    }
	  }
      }      
    default:
      {
	StrmWej.setstate(ios::failbit);
	return StrmWej;
      }
    }
  return StrmWej;
}


istream & operator >> (istream & StrmWej, WyrazenieZesp & wyraz)
{
  StrmWej >> wyraz.Arg1;
  if(StrmWej.fail())
    {
      return StrmWej;
    }
  StrmWej >> wyraz.Op;
  if(StrmWej.fail())
    {
      return StrmWej;
    }
  StrmWej >> wyraz.Arg2;
  if(StrmWej.fail())
    {
      return StrmWej;
    }
  return StrmWej;
}
