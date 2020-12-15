#include <cstdio>
#include <set>
using namespace std;

const int maxv = 17000000;
const int maxp = 3000000;

bool composite[maxv];
int prime[maxp];

int mpex(set<int> &s, int p) {
  for(int i=0; i<p; ++i)
    if (s.count(prime[i])==0)
      return prime[i];
  return -1;
}

int main() {
  set<int> s;
  int p=0;
  prime[p++]=1;
  for(int i=2; i<maxv; ++i) {
    if (!composite[i]) {
      prime[p++]=i;
      int64_t j = i;
      j*=i;
      for(;j<maxv; j+=i)
	composite[(int)j]=true;
    }
  }
  int num_tests;
  for(scanf(" %d", &num_tests); num_tests>0; --num_tests) {
    int n;
    scanf(" %d", &n);
    s.clear();
    for(int i=0; i<n; ++i) {
      int x;
      scanf(" %d", &x);
      s.insert(x);
    }
    printf("%d\n", mpex(s, p)-1);
  }
  return 0;
}
