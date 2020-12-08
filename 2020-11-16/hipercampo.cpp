#include <cstdio>
#include <cmath>
const int maxn = 128;

struct point_t {
  int x, y;
  int rank;
  int degree_in;
};

int cross(point_t a, point_t b) {
  int r = a.x*b.y - a.y*b.x;
  if (r > 0)
    return 1;
  else if (r < 0)
    return -1;
  else
    return 0;
}
point_t operator-(const point_t a, const point_t b) {
  return point_t{a.x-b.x, a.y-b.y};
}
point_t vet[maxn];
int mtx[maxn][maxn];

void remove_node(int x, int n) {
  for(int i=0; i<n; ++i) {
    if (mtx[x][i]) {
      --vet[i].degree_in;
      mtx[x][i] = 0;
    }
  }
}

int main() {
  int n;
  point_t A, B;
  scanf(" %d %d %d", &n, &A.x, &B.x);
  A.y=B.y=0;
  for(int i=0; i<n; ++i) {
    scanf(" %d %d", &vet[i].x, &vet[i].y);
  }
  
  for(int i=0; i<n; ++i) {
    for(int j=0; j<n; ++j) {
      if (i!=j) {
	if (cross(vet[i]-A, vet[j]-A)<0
	    && cross(vet[i]-B, vet[j]-B)>0) {
	  mtx[i][j] = 1;
	  vet[j].degree_in++;
	}
      }
    }
  }
  
  int current_rank = 1;
  int remaining_nodes = n;
  while(remaining_nodes > 0) {
    for(int i=0; i<n; ++i)
      if (vet[i].rank == 0 && vet[i].degree_in == 0) {
	vet[i].rank = current_rank;
	remaining_nodes--;
	remove_node(i, n);
      }
    ++current_rank;
  }
  printf("%d\n", current_rank-1);
  return 0;
}
