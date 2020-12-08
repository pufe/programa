#include <cstdio>
#include <cmath>

const double pi = 4*atan(1);

int main() {
  double d = sqrt(3) - 1;
  double cc = pi/12 - sin(pi/12)*cos(pi/12);
  double a1 = d*d/2.0 + 4*cc;
  double a3 = 8*(1/2.0 - sqrt(3)/8.0 - pi/12);
  double a2 = 1-a1-a3;
  double f;
  while(scanf(" %lf", &f)==1) {
    printf("%.3lf %.3lf %.3lf\n", a1*f*f, a2*f*f, a3*f*f);
  }
  return 0;
}
