#include <cstdio>

int calc(int budget, int dedalus) {
  if (dedalus <= budget)
    return dedalus;
  return 0;
}
int greatest(int budget) {
  int i;
  for(i=1; i<=budget && i<100000; i*=10)
    ;
  return i/10;
}

int main() {
  int n, m;
  int score=0, best=0;
  scanf(" %d %d", &n, &m);
  for(int i=0; i<m; ++i) {
    int budget, dedalus;
    scanf(" %d %d", &budget, &dedalus);
    for(int j=1; j<n; ++j) {
      int other;
      scanf(" %d", &other);
      budget -= other;
    }
    score += calc(budget, dedalus);
    best += greatest(budget);
  }
  printf("%d\n", best-score);
  return 0;
}
