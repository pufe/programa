#include <cstdio>

const int maxn = 32;
int bank[maxn];

bool no_bank_negative(int n) {
  for(int i=1; i<=n; ++i)
    if (bank[i]<0)
      return false;
  return true;
}

int main() {
  int n, m;
  while(true) {
    scanf(" %d %d", &n, &m);
    if (n==0 && m==0)
      break;
    for(int i=1; i<=n; ++i) {
      scanf(" %d", &bank[i]);
    }

    for(int i=0; i<m; ++i) {
      int d, c, v;
      scanf(" %d %d %d", &d, &c, &v);
      bank[d]-=v;
      bank[c]+=v;
    }
    
    if (no_bank_negative(n))
      printf("S\n");
    else
      printf("N\n");
  }
  return 0;
}
