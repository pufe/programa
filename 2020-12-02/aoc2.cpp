#include <cstdio>

int count_occurrences(char c, char str[]) {
  int total = 0;
  for(int i=0; str[i]; ++i)
    if (str[i]==c)
      ++total;
  return total;
}

int main() {
  int lb, ub;
  char c;
  char str[50];
  int valid_pw = 0;
  while(scanf("%d-%d %c: %s", &lb, &ub, &c, str)==4) {
    int x = 0;
    if (str[lb-1]==c)
      ++x;
    if (str[ub-1]==c)
      ++x;
    if (x==1)
      ++valid_pw;
  }
  printf("%d\n", valid_pw);
  return 0;
}
