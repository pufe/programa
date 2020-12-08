#include <cstdio>

typedef long long unsigned int bit;

int main() {
  int n;
  scanf(" %d", &n);
  for(int i=0; i<n; ++i) {
    int x;
    scanf(" %d", &x);
    bit q = (1ULL << (x-1)) - 1 + (1ULL << (x-1));
    bit grams = q/12;
    bit kg = grams/1000;
    printf("%llu kg\n", kg);
  }
  return 0;
}
