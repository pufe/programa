#include <cstdio>
#include <cstdint>
#include <cmath>
#include <vector>
using namespace std;

typedef int64_t num;
const num mod = 1300031;
const int maxn = 230;

struct matrix_t {
  int n;
  num v[maxn][maxn];
  void zero() {
    for(int i=0; i<n; ++i)
      for(int j=0; j<n; ++j)
	v[i][j]=0;
  }
};
matrix_t r, m, aux;

void operator*=(matrix_t& a, matrix_t& b) {
  aux.n = a.n;
  for(int i=0; i<a.n; ++i)
    for(int j=0; j<b.n; ++j) {
      aux.v[i][j]=0;
      for(int k=0; k<a.n; ++k) {
	aux.v[i][j]+=(a.v[i][k]*b.v[k][j])%mod;
	aux.v[i][j]%=mod;
      }
    }
  for(int i=0; i<a.n; ++i)
    for(int j=0; j<a.n; ++j)
      a.v[i][j] = aux.v[i][j];
}

void exponentiate(matrix_t& a, int p) {
  r.n = a.n;
  for(int i=0; i<a.n; ++i)
    for(int j=0; j<a.n; ++j)
      r.v[i][j] = i==j ? 1 : 0;

  while(p>0) {
    if (p%2==1)
      r *= a;
    a *= a;
    p /= 2;
  }
}

int index(int x, int y, int n) {
  int a = min(x, y);
  int b = max(x, y);
  return b*(b+1)/2+a;
}

int gcd(int a, int b) {
  //printf("gcd(%d %d)\n", a, b);
  if (b==0)
    return a;
  return gcd(b, a%b);
}

bool connected(int x1, int y1, int x2, int y2) {
  int dx = abs(x1-x2);
  int dy = abs(y1-y2);
  return gcd(dx, dy)==1;
}

void generate(int n) {
  m.n = n*(n+1)/2;
  m.zero();
  for(int x1=0; x1<n; ++x1)
    for(int y1=0; y1<n; ++y1)
      for(int x2=0; x2<n; ++x2)
	for(int y2=0; y2<n; ++y2)
	  if (connected(x1, y1, x2, y2))
	    m.v[index(x1,y1,n)][index(x2,y2,n)]++;
}

num all_paths(int n) {
  num res=0;
  for(int x1=0; x1<n; ++x1)
    for(int y1=0; y1<n; ++y1)
      for(int x2=0; x2<n; ++x2)
	for(int y2=0; y2<n; ++y2)
	  res = (res + r.v[index(x1,y1,n)][index(x2,y2,n)])%mod;
  return res;
}

int main() {
  int n, p;
  while(true) {
    scanf(" %d %d", &n, &p);
    if (n==0 && p==0)
      break;
    generate(n);
    exponentiate(m, p-1);
    printf("%lld\n", all_paths(n));
  }
  return 0;
}
