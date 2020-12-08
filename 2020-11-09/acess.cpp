#include <cstdio>

int main() {
  double h, c, l;
  while(true) {
    scanf(" %lf %lf %lf", &h, &c, &l);
    if (h==0 && c==0 && l==0)
      break;
    if ( c >= 12*h && l >= 0.8)
      printf("PROJETO SIMPLES\n");
    else
      printf("PROJETO ESPECIAL\n");
  }
  return 0;
}
