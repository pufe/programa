#include <cstdio>
#define PI 3.14159265358979323846  /* pi */

double b, B, H;
double volume;

double fill_up_to(double h) {
  double C = b*H/(B-b);
  double r = b+h*(B-b)/H;
  double green = PI*r*r*(C+h)/3;
  double blue = PI*b*b*C/3;
  return green - blue;
}

double search(double lb, double ub) {
  if (ub - lb < 0.0001)
    return ub;
  double mid = (lb+ub)/2;
  double cup = fill_up_to(mid);
  if (cup > volume)
    return search(lb, mid);
  else
    return search(mid, ub);
}

int main() {
  int num_testes;
  for(scanf(" %d", &num_testes); num_testes>0; --num_testes) {
    int n;
    scanf(" %d %lf", &n, &volume);
    volume /= n;

    scanf(" %lf %lf %lf", &b, &B, &H);
    if (b == B) {
      printf("%.2lf\n", volume/(PI*B*B));
    } else {
      printf("%.2lf\n", search(0, H));
    }
  }
}
