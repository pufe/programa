#include <cstdio>

const int maxn = 128;
int d[maxn];
char line[maxn];

int main() {
  int p = 1000;
  int n;
  for(int i=0; i<4; ++i) {
    scanf(" %s", line);
    n=0;
    for(int j=0; line[j]; ++j) {
      d[j] += p*(line[j]-'0');
      ++n;
    }
    p/=10;
  }
  for(int i=1; i<n-1; ++i) {
    printf("%c", (d[i]*d[0]+d[n-1])%257);
  }
  printf("\n");
  return 0;
}
