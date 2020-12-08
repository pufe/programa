#include <cstdio>

const int maxn = 100100;
const int maxd = 100001000;

int cycle[maxn];

int compute(int n, int days) {
  int total = 0;
  for(int i=0; i<n; ++i) {
    total += days/cycle[i];
  }
  return total;
}

int search(int n, int lb, int ub, int goal) {
  if (ub - lb <= 1)
    return ub;
  int mid = (lb+ub)/2;
  int coins = compute(n, mid);
  if (coins < goal) {
    return search(n, mid, ub, goal);
  } else {
    return search(n, lb, mid, goal);
  }
}

int main() {
  int n, f;
  scanf(" %d %d", &n, &f);
  for(int i=0; i<n; ++i) {
    scanf(" %d", &cycle[i]);
  }
  printf("%d\n", search(n, 0, maxd, f));
  return 0;
}
