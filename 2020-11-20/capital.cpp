#include <cstdio>

int main() {
  int a, b, c, d;
  scanf(" %d %d %d %d", &a, &b, &c, &d);
  if (a*b == c*d)
    printf("S\n");
  else if (a*c == b*d)
    printf("S\n");
  else if (a*d == b*c)
    printf("S\n");
  else
    printf("N\n");
  return 0;
}
