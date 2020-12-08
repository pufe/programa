#include <cstdio>
#include <map>
#include <functional>
#include <algorithm>
using namespace std;

typedef unsigned long long int bit;
const int maxn = 100100;
bit elfo[maxn];

int msb(bit x) {
  int c=0;
  while (x>1) {
    x/=2;
    ++c;
  }
  return c;
}

int mtx_rank(int n) {
  int r=0;
  for(int i=0; i<n; ++i) {
    if (elfo[i]!=0) {
      ++r;
      bit b = 1LL<<msb(elfo[i]);
      for(int j=i+1; j<n; ++j) {
	if (elfo[j] & b) {
	  elfo[j]^=elfo[i];
	}
      }
      sort(elfo+i+1, elfo+n, greater<bit>());
    }
  }
  return r;
}

int main() {
  map<char, int> m;
  int c=0;
  for(char x='a'; x<='z'; ++x)
    m[x] = c++;
  for(char x='A'; x<='Z'; ++x)
    m[x] = c++;
  for(char x='0'; x<='9'; ++x)
    m[x] = c++;
  
  int tests;
  char str[70];

  scanf(" %d", &tests);
  for(int t=0; t<tests; ++t) {
    int n, d=1;
    scanf(" %d", &n);
    for(int i=0; i<n; ++i) {
      scanf(" %s", str);
      elfo[i] = 0;
      for(int j=0; str[j]; ++j) {
	elfo[i] |= 1LL<<m[str[j]];
      }
    }
    sort(elfo, elfo+n, greater<bit>());
    for(int i=1; i<n; ++i) {
      if (elfo[i]!=elfo[i-1])
	++d;
    }
    int r = mtx_rank(n);
    printf("%llu\n", (1LL<<r)-1-d);
  }
  return 0;
}
