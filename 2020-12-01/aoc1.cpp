#include <cstdio>
const int maxn = 300;

int main() {
  int v[maxn];
  int n=0;
  while(scanf(" %d", &v[n])==1) {
    ++n;
  }
  for(int i=0; i<n; ++i)
    for(int j=i+1; j<n; ++j) {
      if (v[i]+v[j]==2020)
	printf("%d+%d=2020, prod=%d\n", v[i], v[j], v[i]*v[j]);
    }
  return 0;
}
