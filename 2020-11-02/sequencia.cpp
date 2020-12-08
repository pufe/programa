#include <cstdio>

int main() {
  int n, atual, anterior, total;
  scanf(" %d", &n);
  anterior = 0;
  total = 0;
  for(int i=0; i<n; ++i) {
    scanf(" %d", &atual);
    if (atual!=anterior)
      ++total;
    anterior = atual;
  }
  printf("%d\n", total);
  return 0;
}
