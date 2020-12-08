#include <cstdio>

const int maxn = 1024;

bool bit[maxn];
int msb = 0;

int fib[maxn];

void convert_to_bit(int n) {
  msb=0;
  while(fib[msb]<=n) {
    ++msb;
  }
  for(int i=msb; i>=0; --i) {
    if (n>=fib[i]) {
      bit[i] = true;
      n-=fib[i];
    } else {
      bit[i] = false;
    }
  }
}

void rshift() {
  for(int i=0; i<msb; ++i) {
    bit[i]=bit[i+1];
  }
}

int convert_from_bit() {
  int n = 0;
  for(int i=0; i<msb; ++i) {
    if (bit[i])
      n+=fib[i];
  }
  return n;
}

int main() {
  fib[0]=1;
  fib[1]=2;
  for(int i=2; fib[i-1]<=25000; ++i) {
    fib[i] = fib[i-1]+fib[i-2];
  }
  int n;
  scanf(" %d", &n);
  for(int i=0; i<n; ++i) {
    int x;
    scanf(" %d", &x);
    convert_to_bit(x);
    rshift();
    printf("%d\n", convert_from_bit());
  }
  return 0;
}
