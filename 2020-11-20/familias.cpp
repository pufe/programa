#include <cstdio>

struct family_t {
  int repr;
  int rank;
};

const int maxn = 100100;
family_t family[maxn];

int uf_find(int n) {
  if (family[n].repr != n)
    family[n].repr = uf_find(family[n].repr);
  return family[n].repr;
}

bool uf_union(int a, int b) {
  int aa = uf_find(a);
  int bb = uf_find(b);
  if (aa == bb) {
    return false;
  }
  if (family[aa].rank > family[bb].rank) {
    family[bb].repr = aa;
  } else if (family[bb].rank > family[aa].rank) {
    family[aa].repr = bb;
  } else {
    family[aa].rank++;
    family[bb].repr = aa;
  }
  return true;
}

int main() {
  int n, m;
  int total;
  scanf(" %d %d", &n, &m);
  for(int i=1; i<=n; ++i) {
    family[i].repr = i;
    family[i].rank = 0;
  }
  total = n;
  for(int i=0; i<m; ++i) {
    int a, b;
    scanf(" %d %d", &a, &b);
    if (uf_union(a, b))
      --total;
  }
  printf("%d\n", total);
  return 0;
}
