#include <cstdio>

int main() {
  int counter=0;
  int area, n;
  const int threshold = 40000000;
  scanf(" %d %d", &area, &n);
  for(int i=0; i<n; ++i) {
    int f;
    scanf(" %d", &f);
    if (f*area >= threshold)
      ++counter;
  }
  printf("%d\n", counter);
  return 0;
}
