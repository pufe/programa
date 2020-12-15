#include <cstdio>

const int maxn = 10100;

int degree[maxn];

bool all_even(int n) {
  for(int i=0; i<n; ++i)
    if (degree[i]%2==1)
      return false;
  return true;
}

int main() {
  int num_tests;
  int n, m;
  for(scanf(" %d", &num_tests); num_tests>0; --num_tests) {
    scanf(" %d %d", &n, &m);
    for(int i=0; i<n; ++i)
      degree[i]=0;
    for(int i=0; i<m; ++i) {
      int a, b;
      scanf(" %d %d", &a, &b);
      degree[a]++;
      degree[b]++;
    }
    if (all_even(n))
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}
