#include <cstdio>

bool looks_binary(int n, int b) {
  if (n<2)
    return true;
  if (n%b >= 2)
    return false;
  return looks_binary(n/b, b);
}

int count_bases(int n) {
  int c=0;
  for(int i=2; i<=n; ++i)
    if (looks_binary(n, i))
      ++c;
  return c;
}

int main() {
  int tests;
  scanf(" %d", &tests);
  for(int i=0; i<tests; ++i) {
    int n;
    scanf(" %d", &n);
    printf("%d\n", count_bases(n));
  }
  return 0;
}
