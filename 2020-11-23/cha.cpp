#include <cstdio>

int main() {
  int c, x, t=0;
  scanf(" %d", &c);
  for(int i=0; i<5; ++i) {
    scanf(" %d", &x);
    if (x==c)
      ++t;
  }
  printf("%d\n", t);
  return 0;
}
