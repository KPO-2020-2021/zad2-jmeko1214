#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH


struct Statystyka {
  int liczba_odp;
  int liczba_dobrych;
};

Statystyka Inicjuj_staty(Statystyka &Test);
Statystyka Dodaj_dobra(Statystyka &Test);
Statystyka Dodaj_zla(Statystyka &Test);
double Procent_dobrych(Statystyka &Test);
int Liczba_zlych(Statystyka &Test);
void Wyswietl_statystyki(Statystyka &Test);

#endif
