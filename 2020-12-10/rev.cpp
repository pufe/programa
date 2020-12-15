#include <cstdio>
#include <cstdint>

typedef int64_t num;

const int maxn = 22;

num f[maxn], g[maxn];

int main() {
  f[0] = 0;
  f[1] = 0;
  g[0] = 0;
  g[1] = 0;
  num middle = 1;
  for(int i=2; i<maxn; ++i) {
    f[i] = middle*36;
    f[i] += 9*g[i-2];
    g[i] = middle*45;
    g[i] += 10*g[i-2];
    middle *= 10;
  }
  num x;
  scanf(" %lld", &x);
  printf("%lld\n", f[x]);
  return 0;
}
