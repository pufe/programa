#include <cstdio>

char cmd[128];
char str[32];

int main() {
  int t;
  for(scanf(" %d", &t); t>0; --t) {
    int n, p=0;
    scanf(" %d", &n);
    for(int i=1; i<=n; ++i) {
      scanf(" %s", str);
      if (str[0]=='S') {
	int x;
	scanf(" AS %d", &x);
	str[0] = cmd[x];
      }
      cmd[i] = str[0];
      if (cmd[i]=='L')
	--p;
      else
	++p;
    }
    printf("%d\n", p);
  }
  return 0;
}
