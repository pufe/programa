#include <cstdio>

int N[20];

int main() {
  for(int i=0; i<20; ++i) {
    scanf(" %d", &N[i]);
  }
  for(int i=0; i<10; ++i) {
    int tmp = N[i];
    N[i] = N[20-1 - i];
    N[20-1 - i] = tmp;
  }
  for(int i=0; i<20; ++i) {
    printf("N[%d] = %d\n", i, N[i]);
  }
  return 0;
}
