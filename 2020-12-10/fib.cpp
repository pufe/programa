#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int base = 1000000;

struct bignum_t {
  vector<int> d;
  void print() {
    if (d.size()==0)
      printf("0");
    else {
      printf("%d", d[d.size()-1]);
      for(int i=d.size()-2; i>=0; --i) {
	printf("%06d", d[i]);
      }
    }
  }
};

bignum_t operator+(const bignum_t a, const bignum_t b) {
  bignum_t c;
  int carry=0;
  c.d.resize(max(a.d.size(), b.d.size()));
  for(int i=0; i<(int)c.d.size(); ++i) {
    c.d[i]=carry;
    if (i<(int)a.d.size())
      c.d[i]+=a.d[i];
    if (i<(int)b.d.size())
      c.d[i]+=b.d[i];
    carry = c.d[i]/base;
    c.d[i] %= base;
  }
  if (carry > 0)
    c.d.push_back(carry);
  return c;
}

bool operator<(const bignum_t a, const bignum_t b) {
  if (a.d.size() != b.d.size())
    return a.d.size() < b.d.size();
  for(int i=a.d.size()-1; i>=0; --i)
    if (a.d[i]!=b.d[i])
      return a.d[i]<b.d[i];
  return false;
}

bignum_t read_bignum(char str[]) {
  int n = strlen(str);
  bignum_t r;
  r.d.resize((n+5)/6);
  //printf("debug str=%s\n", str);
  for(int i=n, j=0; i>0; i-=6, ++j) {
    str[i]=0;
    int start = max(i-6, 0);
    sscanf(str+start, "%6d", &r.d[j]);
  }
  /*printf("debug num=");
  r.print();
  printf("\n\n");*/
  
  return r;
}

char as[128], bs[128];

int main() {
  vector<bignum_t> fib;
  fib.push_back(bignum_t{{1}});
  fib.push_back(bignum_t{{2}});
  for(int i=2; ;++i) {
    fib.push_back(fib[i-1]+fib[i-2]);
    if (fib[i].d.size() > 17) {
      break;
    }
  }
  while(true) {
    scanf(" %s %s", as, bs);
    if (as[0]=='0' && bs[0]=='0')
      break;
    bignum_t a = read_bignum(as);
    bignum_t b = read_bignum(bs);
    auto it_a = lower_bound(fib.begin(), fib.end(), a);
    auto it_b = upper_bound(fib.begin(), fib.end(), b);
    printf("%ld\n", it_b-it_a);
  }
  return 0;
}
