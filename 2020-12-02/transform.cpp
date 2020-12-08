/*
  ID: pufepro1
  LANG: C++
  TASK: transform
*/
#include <cstdio>
#include <cstdlib>

struct mtx_t {
  int n;
  char c[12][12];
};

mtx_t rotate(const mtx_t a) {
  mtx_t b;
  b.n = a.n;
  for(int i=0; i<a.n; ++i)
    for(int j=0; j<a.n; ++j)
      b.c[i][j]=a.c[a.n-1 - j][i];
  return b;
}
mtx_t reflect(const mtx_t a) {
  mtx_t b;
  b.n = a.n;
  for(int i=0; i<a.n; ++i)
    for(int j=0; j<a.n; ++j)
      b.c[i][j] = a.c[i][a.n-1 - j];
  return b;
}
bool equals(const mtx_t a, const mtx_t b) {
  if (a.n != b.n)
    return false;
  for(int i=0; i<a.n; ++i)
    for(int j=0; j<a.n; ++j)
      if (a.c[i][j]!=b.c[i][j])
	return false;
  return true;
}
int search(mtx_t a, mtx_t b) {
  int c=0;
  for(int j=0; j<3; ++j) {
    ++c;
    a = rotate(a);
    if (equals(a, b))
      return c;
  }
  ++c;
  a = rotate(a);
  a = reflect(a);
  if (equals(a, b))
    return c;
  ++c;
  for(int j=0; j<3; ++j) {
    a = rotate(a);
    if (equals(a, b))
      return c;
  }
  ++c;
  a = rotate(a);
  a = reflect(a);
  if (equals(a, b))
    return c;
  return 7;
}

int main() {
  FILE *fin  = fopen("transform.in", "r");
  FILE *fout = fopen("transform.out", "w");
  int n;
  mtx_t original;
  mtx_t modified;
  fscanf(fin, " %d", &n);
  original.n = n;
  modified.n = n;

  for(int i=0; i<n; ++i)
    for(int j=0; j<n; ++j)
      fscanf(fin, " %c", &original.c[i][j]);

  for(int i=0; i<n; ++i)
    for(int j=0; j<n; ++j)
      fscanf(fin, " %c", &modified.c[i][j]);

  int x = search(original, modified);
  fprintf(fout, "%d\n", x);
  return 0;
}
