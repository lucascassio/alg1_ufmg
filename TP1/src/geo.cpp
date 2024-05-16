#include "../include/geo.hpp"
// Coeficiente da reta orientada de p para q.
double Geo::RelativeInclination(Ponto p, Ponto q) {
  return atan2(q.y - p.y, q.x - p.x);
}
