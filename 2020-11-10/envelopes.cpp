#include <cstdio>

int main() {
  int n;
  scanf(" %d", &n);
  for(int i=0; i<n; ++i) {
    int x1, y1, x2, y2;
    scanf(" %d %d %d %d", &x1, &y1, &x2, &y2);
    if (x1 < x2 && y1 < y2) {
      printf("S\n");
    } else if (x1 < y2 && y1 < x2) {
      printf("S\n");
    } else {
      printf("N\n");
    }
  }
  return 0;
}
