#include <cstdio>

typedef long long int big;

big gcd(big a, big b) {
  if (b==0)
    return a;
  return gcd(b, a%b);
}

big lcm(big a, big b) {
  return a*b/gcd(a, b);
}

const int maxn = 200100;
int card[maxn];
bool found[maxn];

int find_cycle(int x, int d, int t) {
  found[x]=true;
  while(card[x]!=t) {
    x = card[x];
    found[x]=true;
    ++d;
  }
  return d;
}

int main() {
  int n;
  big total=1;
  scanf(" %d", &n);
  for(int i=0; i<n/2; ++i) {
    card[2*i]=n/2+i;
    card[2*i+1]=i;
    found[2*i]=false;
    found[2*i+1]=false;
  }
  for(int i=0; i<n; ++i) {
    if (!found[i]) {
      total = lcm(total, find_cycle(i, 1, i));
    }
  }
  printf("%lld\n", total);
  return 0;
}
