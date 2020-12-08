#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1024;
int vet[maxn];

int main() {
  int n, low, up;
  int c=0;
  scanf(" %d %d %d", &n, &low, &up);
  for(int i=0; i<n; ++i) {
    scanf(" %d", &vet[i]);
  }
  sort(vet, vet+n);
  for(int i=0; i<n; ++i) {
    int x = vet[i];
    int* lp = lower_bound(vet, vet+n, low-vet[i]);
    int* hp = upper_bound(vet, vet+n, up-vet[i]);
    c += hp - lp;
    if (x+x >= low && x+x <= up)
      --c;
  }
  printf("%d\n", c/2);
  return 0;
}
