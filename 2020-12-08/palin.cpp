#include <cstdio>

char palavra[1024];
int c[32];

int main() {
  while(scanf(" %s", palavra)==1) {
    for(int i=0; i<26; ++i)
      c[i]=0;
    for(int i=0; palavra[i]; ++i)
      c[palavra[i]-'a']++;
    int q=-1;
    for(int i=0; i<26; ++i)
      if (c[i]%2==1)
	++q;
    if (q<0)
      q=0;
    printf("%d\n", q);
  }
  return 0;
}
