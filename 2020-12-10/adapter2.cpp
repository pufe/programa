#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 200;
int vet[maxn];
int64_t ways[maxn];

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
  ways[0]=1L;
  for(int i=1; i<n; ++i) {
    //printf("~v[%d] = %d\n", i, vet[i]);
    for(int j=i-1; j>=0 && vet[i]-vet[j]<=3; --j) {
      //printf("~~v[%d] = %d\n", j, vet[j]);
      ways[i]+=ways[j];
    }
  }
  for(int i=n-11; i<n; ++i)
    printf("%ld\n", ways[i]);
  return 0;
}
