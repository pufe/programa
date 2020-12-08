#include <cstdio>

struct circle_t {
  double x, y;
  bool contains(double px, double py) {
    double dx = px-x;
    double dy = py-y;
    return dx*dx+dy*dy<=1;
  }
};

int main() {
  int pa1=0, pa2=0, pa3=0;
  circle_t c[4] = {{0,0}, {0,1}, {1, 1}, {1, 0}};
  for(int i=0; i<3000; ++i) {
    for(int j=0; j<3000; ++j) {
      int t=0;
      for(int k=0; k<4; ++k)
	if (c[k].contains(i/3000.0, j/3000.0))
	  ++t;
      if (t<=2)
	++pa3;
      else if (t>=4)
	++pa1;
      else
	++pa2;
    }
  }
  double a1 = pa1/9e6, a2=pa2/9e6, a3=pa3/9e6;
  double x;
  while(scanf(" %lf", &x)==1) {
    printf("%.3lf %.3lf %.3lf\n", a1*x*x, a2*x*x, a3*x*x);
  }
  return 0;
}
