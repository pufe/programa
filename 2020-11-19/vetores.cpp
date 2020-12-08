#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 5012;

struct vector_t {
  int v[maxn];
  int w;
  int& operator[](int x) {
    return v[x];
  }
  bool is_zero(int cols) {
    for(int i=0; i<cols; ++i)
      if (v[i]!=0)
	return false;
    return true;
  }
};

vector_t mtx[maxn];
int lines, cols;
int order[maxn];

bool cmp(const int a, const int b) {
  return mtx[a].w > mtx[b].w;
}

void subtract(int i, int j, int pivot) {
  int pi = mtx[i][pivot];
  int pj = mtx[j][pivot];
  for(int k=0; k<cols; ++k) {
    mtx[j][k] = mtx[j][k]*pi - mtx[i][k]*pj;
  }
}

void eliminate(int i) {
  int pivot = 0;
  int row = order[i];
  while(mtx[row][pivot]==0)
    ++pivot;
  for(int j=i+1; j<lines; ++j) {
    if (mtx[order[j]][pivot]!=0)
      subtract(row, order[j], pivot);
  }
}

void debug() {
  for(int i=0; i<lines; ++i) {
    for(int j=0; j<cols; ++j) {
      printf(" %2d", mtx[i][j]);
    }
    printf(" -> %d\n", mtx[i].w);
  }
  printf("---\n");
}

int main() {
  int total = 0;
  scanf(" %d %d", &lines, &cols);
  for(int i=0; i<lines; ++i) {
    for(int j=0; j<cols; ++j)
      scanf(" %d", &mtx[i][j]);
    scanf(" %d", &mtx[i].w);
    order[i]=i;
  }
  sort(order, order+lines, cmp);
  for(int i=0; i<lines; ++i) {
    int j=order[i];
    if (!mtx[j].is_zero(cols)) {
      total += mtx[j].w;
      eliminate(i);
    }
    //debug();
  }
  printf("%d\n", total);
  return 0;
}
