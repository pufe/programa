#include <cstdio>
#include <cstdint>

typedef long long int num;

const num mod = (1L<<31)-1;

num exp_mod(num base, num ex) {
  num r=1;
  while(ex>0) {
    //    printf("%ld %ld %ld\n", r, base, ex);
    if (ex%2==1) {
      r = (r*base)%mod;
    }
    ex>>=1;
    base=(base*base)%mod;
  }
  return r;
}

int main() {
  num r;
  scanf(" %lld", &r);
  printf("%lld\n", exp_mod(3, r));
  return 0;
}
