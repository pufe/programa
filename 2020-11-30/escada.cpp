#include <cstdio>
#include <cmath>

int main() {
  int n, h, l, c;
  while(scanf(" %d %d %d %d", &n, &h, &c, &l)==4) {
    double diag = sqrt(h*h+c*c);
    printf("%.4lf\n", diag*l*n/10000.0);
  }
  return 0;
}
