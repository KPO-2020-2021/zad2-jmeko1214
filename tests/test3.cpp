#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "WyrazenieZesp.hh"

/*
TEST_CASE("WyrazenieZesp - wyswietlanie standard-dodawanie") {
  WyrazenieZesp x;

  std::ostringstream out;
    x.Arg1.re = 2;
    x.Arg1.im = 2;
    //x.Op = Operator::Op_Dodaj;
    out << x.Arg1;
    out << "+";
    x.Arg2.re = 2;
    x.Arg2.im = 0;
    out << x.Arg2;
    x.Op = Operator::Op_Dodaj;

    //std::ostringstream out;

    //out << x;
    std::cout << out.str() << std::endl;
    
    CHECK( "(2+2i)+(2+0i)" == out.str() );
}

TEST_CASE("WyrazenieZesp - wyswietlanie standard-odejmowanie") {
  WyrazenieZesp x;
     
    x.Arg1.re = 2;
    x.Arg1.im = 2;
    x.Arg2.re = 2;
    x.Arg2.im = 0;
    x.Op = Operator::Op_Odejmij;

    std::ostringstream out;

    out << x;
    std::cout << out.str() << std::endl;
    
    CHECK( "(2+2i)-(2+0i)" == out.str() );
}

TEST_CASE("WyrazenieZesp - wyswietlanie standard-mnozenie") {
  WyrazenieZesp x;
     
    x.Arg1.re = 2;
    x.Arg1.im = 2;
    x.Arg2.re = 2;
    x.Arg2.im = 0;
    x.Op = Operator::Op_Mnoz;

    std::ostringstream out;

    out << x;
    std::cout << out.str() << std::endl;
    
    CHECK( "(2+2i)*(2+0i)" == out.str() );
}

TEST_CASE("WyrazenieZesp - wyswietlanie standard-dzielenie") {
  WyrazenieZesp x;
     
    x.Arg1.re = 2;
    x.Arg1.im = 2;
    x.Arg2.re = 2;
    x.Arg2.im = 0;
    x.Op = Operator::Op_Dziel;

    std::ostringstream out;

    out << x;
    std::cout << out.str() << std::endl;
    
    CHECK( "(2+2i)/(2+0i)" == out.str() );
    }*/
/*
TEST_CASE("WyrazenieZesp - wczytywanie standard") {
  WyrazenieZesp x;

  std::istringstream in("(5.0+5.5i)");
  in >> x;
  std::ostringstream out;
  out << x;

  CHECK( "(5+5.5i)" == out.str() );
  }*/
