#include <cstdio>

typedef long long unsigned int bit;

bit fat[24];

int main() {
  int n, m;
  fat[0]=1;
  for(bit i=1; i<=20; ++i) {
    fat[i] = fat[i-1]*i;
  }
  while(scanf(" %d %d", &n, &m)==2) {
    printf("%llu\n", fat[n]+fat[m]);
  }
  return 0;
}
