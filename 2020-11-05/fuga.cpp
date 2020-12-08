#include <cstdio>

int main() {
  int n, m, xi, yi, xf, yf;
  int light_sq, dark_sq;
  bool start_dark, end_dark;
  int total;

  scanf(" %d %d", &n, &m);
  n=(n+1)/2;
  m=(m+1)/2;
  scanf(" %d %d", &xi, &yi);
  scanf(" %d %d", &xf, &yf);
  
  light_sq = n*m/2;
  dark_sq = (n*m+1)/2;
  
  xi /= 2; // fix coords
  yi /= 2;
  
  xf /= 2;
  yf /= 2;

  start_dark = (xi+yi)%2==0;
  end_dark = (xf+yf)%2==0;

  if (start_dark != end_dark) {
    total = 2*light_sq;
  } else if (start_dark && end_dark) {
    total = dark_sq + dark_sq-1;
  } else { // !start_dark && !end_dark
    total = light_sq + light_sq-1;
  }
  printf("%d\n", 2*total-1);
  return 0;
}
