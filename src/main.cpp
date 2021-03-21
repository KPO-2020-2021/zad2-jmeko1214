#include <iostream>
#include "BazaTestu.hh"
#include "LZespolona.hh"
#include "WyrazenieZesp.hh"

using namespace std;


int main(int argc, char **argv)
{

  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }

  
  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  WyrazenieZesp   WyrZ_PytanieTestowe;
  LZespolona TwojaOdp;
  LZespolona Wynik;
  
  
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe))
    {
      cout << ":? Podaj wynik operacji: "<< endl;
      cout << WyrZ_PytanieTestowe;
      cout << " = ";
      // Wynik = Oblicz(WyrZ_PytanieTestowe);
      cout << "   Twoja odpowiedz: ";
      for(int i=0; i<3; i++)   //pozwolenie na wprowadzenie 3 razy odpowiedzi
	{                      //w przypadku zlej formy wpisanej liczby zespolonej
	  cin>> TwojaOdp;
	  if(cin.fail())
	    {
	      cout << endl;
	      cout<<"  Blad zapisu liczby zespolonej. Sprobuj jeszcze raz."<<endl;
	      cout<< endl << "   Twoja odpowiedz: ";
	      cin.clear();
	      cin.ignore(500, '\n');
	    }
	  else break;
	}
      if(TwojaOdp==Oblicz(WyrZ_PytanieTestowe))
	{
	  cout<< ":) Odpowiedz poprawna" << endl << endl;
        }
      else if(TwojaOdp!=Oblicz(WyrZ_PytanieTestowe))
	{
	  Wynik=Oblicz(WyrZ_PytanieTestowe);
	  cout<< ":( Blad. Prawidlowym wynikiem jest: " << Wynik << endl;
	}
    }
  
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;

}
