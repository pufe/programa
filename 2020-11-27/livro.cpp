#include <cstdio>

int main() {
  int p, q, d, t;
  while(true) {
    scanf(" %d", &q);
    if (q==0)
      break;
    scanf(" %d %d", &d, &p);
    t = p*q*d/(p-q);

      printf("%d paginas\n", t);
  }
  return 0;
}
