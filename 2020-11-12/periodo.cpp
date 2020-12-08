#include <cstdio>
#include <cstring>

char str[100100];

void increment(int pos, char *s) {
  if (s[pos] == '9') {
    s[pos] = '0';
    increment(pos-1, s);
  } else {
    s[pos]++;
  }
}
bool is_lteq(int p, char *s, int n) {
  for(int i=p; i<n; ++i) {
    if (s[i] < s[i-p])
      return true;
    else if (s[i] > s[i-p])
      return false;
  }
  return true;
}
void repeat_10(int p, int times) {
  for(int i=0; i<times; ++i) {
    printf("1");
    for(int j=0; j<p-1; ++j)
      printf("0");
  }
}
void repeat_prefix(int p, char *s, int times) {
  for(int i=0; i<times; ++i) {
    for(int j=0; j<p; ++j)
      printf("%c", s[j]);
  }
}
int main() {
  int p, n;
  char *begin;
  str[0] = '0';
  scanf(" %d", &p);
  scanf(" %s", str+1);
  n = strlen(str);
  increment(n-1, str);
  if (str[0] == '0') {
    begin = str+1;
    --n;
  } else {
    begin = str;
  }
  if (n % p > 0) {
    repeat_10(p, (n+p-1)/p);
  } else if (is_lteq(p, begin, n)) {
    repeat_prefix(p, begin, n/p);
  } else {
    increment(p-1, begin);
    repeat_prefix(p, begin, n/p);
  }
  printf("\n");
  return 0;
}
