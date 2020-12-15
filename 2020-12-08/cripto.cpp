#include <cstdio>

int main() {
  int x;
  char palavra[1024];
  char minusculas[1024];
  int m=0;
  scanf(" %d", &x);
  for(int i=0; i<x; ++i) {
    scanf(" %s", palavra);
    m=0;
    for(int j=0; palavra[j]; ++j) {
      if (palavra[j]<='z' && palavra[j]>='a') {
	minusculas[m++]=palavra[j];
      }
    }
    for(int j=m-1; j>=0; --j)
      printf("%c", minusculas[j]);
    printf("\n");
  }
  return 0;
}
