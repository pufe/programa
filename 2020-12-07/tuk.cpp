#include <cstdio>

typedef long long int big;

int main() {
  int t, c, d;
  big r;
  for(scanf(" %d", &t); t>0; --t) {
    scanf(" %d %d", &c, &d);
    r=1;
    for(int i=0; i<c; ++i)
      r*=26;
    for(int i=0; i<d; ++i)
      r*=10;
    if (r==1)
      printf("0\n");
    else
      printf("%lld\n", r);
  }
  return 0;
}
