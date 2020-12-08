#include <cstdio>

int main() {
  int t;
  char str[64];
  int d;
  scanf(" %d", &t);
  for(int i=0; i<t; ++i) {
    scanf(" %s %d", str, &d);
    for(int j=0; str[j]; ++j)
      str[j] = (str[j]-'A'-d+26)%26+'A';
    printf("%s\n", str);
  }
  return 0;
}
