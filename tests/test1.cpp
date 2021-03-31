#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"

TEST_CASE("test LZespolona Suma"){
    LZespolona x, y, z;
    LZespolona a, b, c;
    LZespolona k, l, m;
    LZespolona d, e, f;

    x.re = 0; y.re = 0; z.re = 0;
    x.im = 0; y.im = 0; z.im = 0;
    CHECK(x+y == z);

    a.re = 1; b.re = 1; c.re = 2;
    a.im = 1; b.im =-3; c.im = -2;
    CHECK(a+b == c);

    k.re = 1.01; l.re = 1; m.re = 2.01;
    k.im = 1.07; l.im =-3; m.im = -1.93;
    CHECK(k+l == m);

    d.re = 1.00001; e.re = 1; f.re = 2.00001;
    d.im = 1.00001; e.im =-3; f.im = -1.99999;
    CHECK(d+e == f);
}

TEST_CASE("test LZespolona Roznica"){
    LZespolona x, y, z;
    LZespolona a, b, c;
    LZespolona k, l, m;
    LZespolona d, e, f;

    x.re = 1; y.re = 1; z.re = 0;
    x.im = 1; y.im =-3; z.im = 4;
    CHECK(x-y == z);

    a.re = 1.02; b.re = 1.01; c.re = 0.01;
    a.im = 1.02; b.im =-3.02; c.im = 4.04;
    CHECK(a-b == c);

    k.re = 0; l.re = 0; m.re = 0;
    k.im = 0; l.im = 0; m.im = 0;
    CHECK(k-l == m);

    d.re = 1.00001; e.re = 0.00009; f.re = 0.9999;
    d.im = 1.00001; e.im =-3.00002; f.im = 4;
    CHECK(d-e == f);
}

TEST_CASE("test LZespolona Mnozenie"){
    LZespolona x, y, z;
    LZespolona a, b, c;
    LZespolona k, l, m;

    x.re = 0; y.re = 0; z.re = 0;
    x.im = 0; y.im = 0; z.im = 0;
    CHECK(x*y == z);

    a.re = 1; b.re = 2; c.re = 2;
    a.im = 1; b.im = 0; c.im = 2;
    CHECK(a*b == c);

    k.re = 1; l.re = 0; m.re = 0;
    k.im = 0; l.im = 1; m.im = 1;
    CHECK(k*l == m);
}

TEST_CASE("test LZespolona operator =="){
  LZespolona x, y;

  x.re=2; y.re=2;
  x.im=2; y.im=2;

  CHECK(x == y);
}


  
  

