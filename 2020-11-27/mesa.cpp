#include <cstdio>

const int maxn = 1024;
int table[maxn];

int count_redirects(int target) {
  int c=0;
  int x = target;
  while(table[x]!=target) {
    ++c;
    x = table[x];
  }
  return c;
}

int main() {
  int n, q;
  scanf(" %d", &n);
  for(int i=1; i<=n; ++i)
    table[i] = i;
  scanf(" %d", &q);
  for(int i=0; i<q; ++i) {
    int q_type, a, b;
    scanf(" %d", &q_type);
    if (q_type==1) {
      scanf(" %d %d", &a, &b);
      int tmp = table[a];
      table[a] = table[b];
      table[b] = tmp;
    }
    else {
      scanf(" %d", &a);
      printf("%d\n", count_redirects(a));
    }
  }
  return 0;
}
