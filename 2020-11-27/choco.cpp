#include <cstdio>

int main() {
  int n;
  int limit=2, qt=1;
  scanf(" %d", &n);
  while(n>=limit) {
    limit*=2;
    qt*=4;
  }
  printf("%d\n", qt);
  return 0;
}
