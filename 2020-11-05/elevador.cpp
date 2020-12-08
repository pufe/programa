#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 10100;
int vet[maxn];

int main() {
  int n;
  bool possible = true;
  scanf(" %d", &n);
  for(int i=0; i<n; ++i) {
    scanf(" %d", &vet[i]);
  }
  vet[n]=0; // elevador vazio
  sort(vet, vet+n+1);
  for(int i=1; i<=n; ++i) {
    if (vet[i] - vet[i-1] > 8)
      possible = false;
  }
  printf("%c\n", possible?'S':'N');
  return 0;
}
