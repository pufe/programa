#include <stdio.h>

int main() {
  int m, n;
  while(scanf(" %d %d", &m, &n)==2) {
    printf("%d\n", n*m+(n-1)*n/2);
  }
  return 0;
}
