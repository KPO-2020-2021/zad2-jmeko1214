#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"
#include "WyrazenieZesp.hh"

TEST_CASE("Test LZespolona dzielenie przez skalar 1") {
    LZespolona x, y;
    double t = 2;
    
    x.re = 2;
    x.im = 2;

    y.re = 1;
    y.im = 1;
   
    CHECK(x/t == y);
}

TEST_CASE("Test LZespolona dzielenie przez skalar - standardowe z przyblizeniem") {
    LZespolona x, y;
    double t = 3;
    
    x.re = 1;
    x.im = 1;

    y.re = 0.3333;
    y.im = 0.3333;
   
    CHECK(x/t == y);
}

TEST_CASE("Test LZespolona - dzielenie rowna sie") {
  LZespolona x, y, z;
    z.re = 1;
    z.im = 0;
    
    x.re = 2;
    x.im = 1;

    y.re = 2;
    y.im = 1;
   
    CHECK(x/z == y);
}

TEST_CASE("Test LZespolona dzielenie przez skalar - zero") {
    LZespolona x;
    double t = 0;
    
    x.re = 2;
    x.im = 2;
 
   WARN_THROWS(x/t);
}
/*
TEST_CASE("Test LZespolona - dodaj") {
  WyrazenieZesp x={{1,2}, Op_Dodaj, {2,1}};
  LZespolona y;

  y.re = 3;
  y.im = 3;
 
  CHECK(Oblicz(x)==y);
  }

TEST_CASE("Test LZespolona - odejmij") {
   WyrazenieZesp x={{1,2}, Op_Odejmij, {2,1}};
   LZespolona y;

  y.re = -1;
  y.im = 1;
 
  CHECK(Oblicz(x)==y);
}

TEST_CASE("Test LZespolona - mnoz"){
WyrazenieZesp x={{1,2}, Op_Mnoz, {2,0}};
  LZespolona y;

  y.re = 2;
  y.im = 4;
 
  CHECK(Oblicz(x)==y);
}

TEST_CASE("Test LZespolona - dziel") {
  WyrazenieZesp x={{4,2}, Op_Dziel, {2,0}};
  LZespolona y;

  y.re = 2;
  y.im = 1;
 
  CHECK(Oblicz(x)==y);
}
*/


TEST_CASE("Test LZespolona - sprzezenie") {
  LZespolona x={3,4}, y={3,-4};
  /*
    x.re = 2;
    x.im = 2;

    y.re = x.re;
    y.im =-x.im;*/
   
  CHECK(sprzezenie(x) == y);
}

TEST_CASE("Test LZespolona - modul") {
  LZespolona x={2,1};
    double t=5;
    
    //x.re = 2;
    //x.im = 1;  
   
    CHECK(modul2(x) == t);
}

TEST_CASE("LZespolona - wyswietlanie standard") {
  LZespolona x;
     
    x.re = 2;
    x.im = 2;

    std::ostringstream out;

    out << x;
    std::cout << out.str() << std::endl;
    
    CHECK( "(2+2i)" == out.str() );
}

TEST_CASE("LZespolona - wczytywanie standard") {
  LZespolona x;

  std::istringstream in("(5.0+5.5i)");
  in >> x;
  std::ostringstream out;
  out << x;

  CHECK( "(5+5.5i)" == out.str() );
}

TEST_CASE("LZespolona - wyswietlanie zaokraglanie") {
  LZespolona x;
     
    x.re = 2.0/3.0;
    x.im = 2.0/3.0;

    std::ostringstream out;

    out << x;
    std::cout << out.str() << std::endl;
    
    CHECK( "(0.6667+0.6667i)" == out.str() );
}


