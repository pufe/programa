#include <cstdio>
#include <cmath>

const double pi = 4*atan(1);


int main() {
  double x=0, y=0;
  double dir=0;
  char op;
  int arg;
  while(scanf(" %c%d", &op, &arg)==2) {
    switch(op) {
    case 'N': y+=arg; break;
    case 'S': y-=arg; break;
    case 'E': x+=arg; break;
    case 'W': x-=arg; break;
    case 'F':
      x+=arg*cos(dir);
      y+=arg*sin(dir);
      break;
    case 'L':
      dir+=arg*pi/180.0;
      break;
    case 'R':
      dir-=arg*pi/180.0;
      break;
    }
  }
  printf("%lf\n", std::abs(x)+std::abs(y));
  return 0;
}
