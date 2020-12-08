#include <cstdio>
#include <cmath>
const double pi = 3.1415;

int main() {
  double r, q;
  scanf(" %lf %lf", &r, &q);
  double v = 4*pi*r*r*r/3.0;
  printf("%.0lf\n", floor(q/v));
  return 0;
}
