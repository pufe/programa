#include <cstdio>

int main() {
  int b, t, m;
  scanf(" %d %d", &b, &t);
  m = b+t;
  if (m == 160) 
    printf("0\n");
  else if (m > 160)
    printf("1\n");
  else
    printf("2\n");
  return 0;
}
