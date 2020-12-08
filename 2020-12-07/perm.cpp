#include <cstdio>
const int maxn = 100100;
int v[maxn];

bool ambiguous(int n) {
  for(int i=1; i<=n; ++i)
    if (v[v[i]] != i)
      return false;
  return true;
}

int main() {
  int n;
  while(true) {
    scanf(" %d", &n);
    if (n==0)
      break;
    for(int i=1; i<=n; ++i)
      scanf(" %d", &v[i]);
    if (!ambiguous(n))
      printf("not ");
    printf("ambiguous\n");
  }
  return 0;
}
