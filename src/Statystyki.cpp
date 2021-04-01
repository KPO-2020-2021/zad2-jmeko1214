#include<iostream>

#include "Statystyki.hh"
#include "WyrazenieZesp.hh"

using namespace std;


Statystyka Inicjuj_staty(Statystyka & Test)
{
  Test.liczba_dobrych=0;
  Test.liczba_odp=0;
  return Test;
}

Statystyka Dodaj_dobra(Statystyka & Test)
{
  Test.liczba_dobrych++;
  Test.liczba_odp++;
  return Test;
}

Statystyka Dodaj_zla(Statystyka & Test)
{
  Test.liczba_odp++;
  return Test;
}

double Procent_dobrych(Statystyka & Test)
{
  double Procent;
  if(Test.liczba_odp!=0)
    {
        Procent = ((double)Test.liczba_dobrych/(double)Test.liczba_odp)*100;
    }
  return Procent;
}

int Liczba_zlych(Statystyka & Test)
{
  int liczba_zlych;
  liczba_zlych = Test.liczba_odp-Test.liczba_dobrych;
  return liczba_zlych;
}

void Wyswietl_statystyki(Statystyka & Test)
{
  cout<<"Liczba dobrych odpowiedzi: " << Test.liczba_dobrych << endl;
  cout<<"Liczba zlych odpowiedzi: " << Liczba_zlych(Test) << endl;
  cout<<"Wynik procentowy poprawnych odpowiedzi: " << Procent_dobrych(Test) << "%" << endl;
}
