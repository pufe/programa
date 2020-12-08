#include <cstdio>

int convert(char str[]) {
  int t=0;
  for(int i=0; str[i]; ++i) {
    t *= 2;
    if (str[i]=='B' || str[i]=='R')
      ++t;
  }
  return t;
}

int main() {
  int greatest=-1;
  char bp[30];
  while(scanf(" %s", bp)==1) {
    int x = convert(bp);
    if (x > greatest)
      greatest = x;
  }
  printf("%d\n", greatest);
  return 0;
}
