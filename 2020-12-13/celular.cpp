#include <cstdio>
#include <cstdint>
#include <cmath>
#include <vector>
using namespace std;

typedef long long int num;
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
  void print() {
    for(int i=0; i<n; ++i) {
      for(int j=0; j<n; ++j)
	printf(" %lld", v[i][j]);
      printf("\n");
    }
    printf("---\n");
  }
  num sum() {
    num t = 0;
    for(int i=0; i<n; ++i)
      for(int j=0; j<n; ++j)
	t=(t+v[i][j])%mod;
    return t;
  }
};
matrix_t r, m, aux;

int index(int x, int y, int n) {
  int d = (n+1)/2;
  if (x >= d) x = n-x-1;
  if (y >= d) y = n-y-1;
  int a = min(x, y);
  int b = max(x, y);
  int k = b*(b+1)/2+a;
  return k;
}

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

void exponentiate(matrix_t& a, int p, int n) {
  r.n = a.n;
  r.zero();
  for(int x=0; x<n; ++x)
    for(int y=0; y<n; ++y) {
      int i=index(x, y, n);
      r.v[i][i]++;
    }
  while(p>0) {
    if (p%2==1)
      r *= a;
    a *= a;
    p /= 2;
  }
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
  int d = (n+1)/2;
  m.n = d*(d+1)/2;
  m.zero();
  for(int x1=0; x1<d; ++x1)
    for(int y1=0; y1<=x1; ++y1) {
      int i1 = index(x1, y1, n);
      for(int x2=0; x2<n; ++x2)
	for(int y2=0; y2<n; ++y2)
	  if (connected(x1, y1, x2, y2))
	    m.v[i1][index(x2,y2,n)]++;
    }
}

int main() {
  int n, p;
  while(true) {
    scanf(" %d %d", &n, &p);
    if (n==0 && p==0)
      break;
    generate(n);
    exponentiate(m, p-1, n);
    printf("%lld\n", r.sum());
  }
  return 0;
}
