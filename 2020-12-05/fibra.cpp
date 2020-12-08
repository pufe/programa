#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 500;
const int inf = 0x3fff3fff;

int mtx[maxn][maxn];
bool visited[maxn];
int dist[maxn];

int cheapest_unvisited(int n) {
  int d = inf;
  int x = -1;
  for(int i=0; i<n; ++i) {
    if (!visited[i]) {
      if (dist[i]<d) {
	d = dist[i];
	x = i;
      }
    }
  }
  return x;
}

int mst(int n) {
  int total = 0;
  dist[0] = 0;
  for(int i=0; i<n; ++i) {
    int x = cheapest_unvisited(n);
    visited[x] = true;
    total += dist[x];
    for(int j=0; j<n; ++j) {
      dist[j] = min(dist[j], mtx[x][j]);
    }
  }
  return total;
}

int main() {
  int n;
  int cost = 0;
  scanf(" %d", &n);

  for(int i=0; i<n; ++i) {
    visited[i]=false;
    dist[i]=inf;
  }
       
  for(int i=0; i<n; ++i)
    for(int j=0; j<n; ++j) {
      if (i<=j) {
	scanf(" %d", &mtx[i][j]);
	mtx[j][i] = mtx[i][j];
      }
      else {
	int x;
	scanf(" %d", &x);
	if (x==1) {
	  cost += mtx[i][j];
	  mtx[i][j] *= -1;
	  mtx[j][i] *= -1;
	}
      }
    }
  printf("%d\n", cost+mst(n));
  return 0;
}
