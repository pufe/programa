#include <cstdio>

bool is_prime(int x) {
  if (x==2)
    return true;
  if (x%2==0)
    return false;
  for(long long int i=3; i*i <= x; i+=2) {
    if (x%i==0)
      return false;
  }
  return true;
}

int main() {
  int n, x;
  scanf(" %d", &n);
  for(int i=0; i<n; ++i) {
    scanf(" %d", &x);
    if (!is_prime(x))
      printf("Not ");
    printf("Prime\n");
  }
  return 0;
}
