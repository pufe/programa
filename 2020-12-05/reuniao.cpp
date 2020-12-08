#include <cstdio>
#include <algorithm>
using namespace std;

const int inf = 0x3fff3fff;
const int maxn = 128;
int mtx[maxn][maxn];

int main() {
  int n, m;
  int a, b, d;
  scanf(" %d %d", &n, &m);
  for(int i=0; i<n; ++i)
    for(int j=0; j<n; ++j)
      if (i==j)
	mtx[i][j] = 0;
      else
	mtx[i][j] = inf;
  for(int k=0; k<m; ++k) {
    scanf(" %d %d %d", &a, &b, &d);
    mtx[a][b] = min(mtx[a][b], d);
    mtx[b][a] = min(mtx[b][a], d);
  }
  //floyd-warshall
  for(int k=0; k<n; ++k)
    for(int i=0; i<n; ++i)
      for(int j=0; j<n; ++j)
	mtx[i][j] = min(mtx[i][j], mtx[i][k]+mtx[k][j]);
  
  int best=inf;
  for(int i=0; i<n; ++i) {
    int greatest=0;
    for(int j=0; j<n; ++j)
      greatest=max(greatest, mtx[i][j]);
    best=min(best, greatest);
  }
  printf("%d\n", best);
  return 0;
}
