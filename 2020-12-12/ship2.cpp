#include <cstdio>
#include <cmath>

const double pi = 4*atan(1);


int main() {
  double x=0, y=0;
  double wx=10, wy=1;
  char op;
  int arg;
  while(scanf(" %c%d", &op, &arg)==2) {
    switch(op) {
    case 'N': wy+=arg; break;
    case 'S': wy-=arg; break;
    case 'E': wx+=arg; break;
    case 'W': wx-=arg; break;
    case 'F':
      x+=arg*wx;
      y+=arg*wy;
      break;
    case 'R':
      arg=-arg;
    case 'L':
      double theta = arg*pi/180.0;
      double nwx = wx*cos(theta) - wy*sin(theta);
      double nwy = wy*cos(theta) + wx*sin(theta);
      wx = nwx;
      wy = nwy;
      break;
    }
  }
  printf("%lf\n", std::abs(x)+std::abs(y));
  return 0;
}
