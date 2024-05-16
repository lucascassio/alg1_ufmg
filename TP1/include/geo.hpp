#ifndef GEO_HPP
#define GEO_HPP

#include "iostream"
#include <math.h>

struct Ponto {
  double x, y;
};

class Geo {
  public:
  // Coeficiente da reta orientada de p para q.
  double RelativeInclination(Ponto p, Ponto q);
};

#endif