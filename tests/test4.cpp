#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "Statystyki.hh"

TEST_CASE("test Statystyka - obliczanie procent"){

  Statystyka Test;
  double y=50.0;
  Test.liczba_dobrych=2;
  std::cout<<Test.liczba_dobrych<<std::endl;
  Test.liczba_odp=4;
  std::cout << Test.liczba_odp<<std::endl;
  std::cout<< Procent_dobrych(Test) << std::endl;
  
  CHECK(Procent_dobrych(Test) == y );
}
