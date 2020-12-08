#include <cstdio>

int main() {
  int v, p;
  scanf(" %d %d", &v, &p);
  for(int i=0; i<p; ++i) {
    if (i < v%p) {
      printf("%d\n", v/p + 1);
    }
    else {
      printf("%d\n", v/p);
    }
  }
  return 0;
}
