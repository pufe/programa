#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 200;
int vet[maxn];
int diff[5];

int main() {
  int n=0;
  int biggest=0;
  vet[0]=0;
  ++n;
  while(scanf(" %d", &vet[n])==1) {
    biggest=max(biggest, vet[n]);
    ++n;
  }
  vet[n++]=biggest+3;
  sort(vet, vet+n);
  for(int i=0; i<n-1; ++i) {
    diff[vet[i+1]-vet[i]]++;
  }
  printf("%d %d %d %d\n", diff[0], diff[1], diff[2], diff[3]);
  printf("%d\n", diff[1]*diff[3]);
  return 0;
}
