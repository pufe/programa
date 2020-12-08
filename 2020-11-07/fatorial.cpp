#include <cstdio>

int greatest_factorial(int n) {
  int v=1;
  int i=2;
  while(i*v <= n) {
    v *= i;
    i++;
  }
  return v;
}

int main() {
  int n, c=0;
  scanf(" %d", &n);
  while(n>0) {
    c++;
    n -= greatest_factorial(n);
  }
  printf("%d\n", c);
  return 0;
}
