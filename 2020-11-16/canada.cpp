#include <cstdio>

int main() {
  long long int v;
  char str[100];
  int p=1;
  while(scanf(" %s", str)==1) {
    printf("Palavra %d\n", p++);
    v=0;
    for(int i=0; str[i]; ++i) {
      v<<=1;
      if (str[i]=='b')
	v++;
    }
    printf("%lld\n\n", v);
  }
  return 0;
}
