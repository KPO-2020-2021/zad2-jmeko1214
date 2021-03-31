#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "Statystyki.hh"

TEST_CASE("test Statystyka - obliczanie procent"){

  Statystyka Test;
  double y=50.0;
  Test.liczba_dobrych=2;
  Test.liczba_odp=4;
  //procent=(x.liczba_dobrych/y.liczba_odp)*100;
  //x=3;
  //y=4;
  //procent=(x/y)*100;
  //std::ostringstream out;

  //out << y;
  //std::cout << out.str() << std::endl;
  
  CHECK(Procent_dobrych(test) == y );
}
