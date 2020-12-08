#include <cstdio>

int cost[10] = {
  6, 2, 5, 5, 4,
  5, 6, 3, 7, 6
};

const int maxn = 100100;
const int MOD = 1000007;
int qz[maxn];
int q[maxn];

int main() {
  qz[0] = 1;
  for(int i=1; i<maxn; ++i) {
    qz[i] = 0;
    q[i] = 0;
    for(int j=0; j<10; ++j) {
      if (cost[j] <= i) {
	qz[i] = (qz[i] + qz[i-cost[j]]) % MOD;
	if (j>0) {
	  q[i] = (q[i] + qz[i-cost[j]]) % MOD;
	}
      }
    }
  }
  q[6]++;
  int n;
  scanf(" %d", &n);
  for(int i=0; i<n; ++i) {
    int x;
    scanf(" %d", &x);
    printf("%d\n", q[x]);
  }
  return 0;
}
