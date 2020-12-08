#include <cstdio>

const int max_x = 100100;

bool possible[max_x] = {};

int main() {
  int x, n;
  int v;
  scanf(" %d %d", &x, &n);
  possible[0] = true;
  for(int i=0; i<n; ++i) {
    scanf(" %d", &v);
    for(int j=x; j>=v; --j) {
      possible[j] = possible[j] || possible[j-v];
    }
  }
  if (possible[x])
    printf("SIM\n");
  else
    printf("NAO\n");
  return 0;
}
