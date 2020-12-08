#include <cstdio>
#include <cstring>

const int maxn = 1024;

struct number_t {
  int digit[maxn];
  int size;
};

number_t number;
char str[maxn];

void divide() {
  for(int i=number.size-1; i>=0; --i) {
    if (i>0 && number.digit[i] % 2 == 1)
      number.digit[i-1] += 10;
    number.digit[i]/=2;
  }
  if (number.digit[number.size-1]==0)
    --number.size;
}

int main() {
  int t, n, c;
  scanf(" %d", &t);
  for(int i=0; i<t; ++i) {
    scanf(" %s", str);
    n = strlen(str);
    for(int j=0; j<n; ++j)
      number.digit[j] = str[n-j-1] - '0';
    number.size = n;
    c=0;
    while(number.size > 0) {
      if (number.digit[0] % 2 == 1)
	++c;
      divide();
    }
    printf("%d\n", c);
  }
  return 0;
}
