#include <cstdio>

const int maxn = 1000100;

bool dp[maxn];

int mdc(int a, int b){ 
  if (b==0)
    return a;
  return mdc(b, a%b);
}

int main() {
  int tests;
  scanf(" %d", &tests);
  for(int t=0; t<tests; ++t) {
    int n, g=0, m=0;
    scanf(" %d", &n);
    for(int i=0; i<maxn; ++i)
      dp[i] = false;
    dp[0] = true;
    for(int i=0; i<n; ++i) {
      int x;
      scanf(" %d", &x);
      g = mdc(g, x);
      for(int j=x; j<maxn; ++j)
	dp[j] = dp[j] || dp[j-x];
    }
    for(int i=0; i<maxn; ++i)
      if (!dp[i])
	m = i;
    if (g>1)
      printf("-1\n");
    else
      printf("%d\n", m);
  }
  return 0;
}
