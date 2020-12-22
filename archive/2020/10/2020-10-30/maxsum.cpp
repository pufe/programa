#include <cstdio>
#include <climits>

const int maxn = 1000010;

int vet[maxn];

int main() {
  int t, n;
  int best_sum;
  scanf(" %d", &t);
  for(int i=0; i<t; ++i) {
    scanf(" %d", &n);
    best_sum = INT_MIN;
    for(int j=0; j<n; ++j) 
      scanf(" %d", &vet[j]);
    int sum=0;
    for(int start=0; start<n; ++start) {
      if (sum <= 0)
	sum = 0;
      sum += vet[start];
      if (sum > best_sum)
	best_sum = sum;
    }
    printf("%d\n", best_sum);
  }
  return 0;
}
