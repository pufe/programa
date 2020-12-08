#include <cstdio>
#include <algorithm>
using namespace std;
typedef unsigned long long big;

big mtx[22][22];
int width[22];

int len(big x) {
  if (x<10)
    return 1;
  return 1+len(x/10);
}

int main() {
  int current = 4;
  int tests;
  scanf(" %d", &tests);
  for(int t=0; t<tests; ++t) {
    int n;
    scanf(" %d", &n);
    for(int i=0; i<n; ++i)
      width[i] = 0;

    for(int i=0; i<n; ++i) 
      for(int j=0; j<n; ++j) {
	scanf(" %llu", &mtx[i][j]);
	mtx[i][j]*=mtx[i][j];
	width[j] = max(width[j], len(mtx[i][j]));
      }

    if (t>0)
      printf("\n");
    printf("Quadrado da matriz #%d:\n", current++);
    for(int i=0; i<n; ++i) {
      for(int j=0; j<n; ++j) {
	if (j>0)
	  printf(" ");
	printf("%*llu", width[j], mtx[i][j]);
      }
      printf("\n");
    }
  }
  return 0;
}
