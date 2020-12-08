/*
  ID: pufepro1
  LANG: C++
  TASK: beads
*/
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int maxn = 1024;

char str[maxn];
int l_red[maxn], r_red[maxn], l_blue[maxn], r_blue[maxn];

int main () {
  FILE *fin  = fopen ("beads.in", "r");
  FILE *fout = fopen ("beads.out", "w");

  int n;
  fscanf(fin, " %d", &n);
  fscanf(fin, " %s", str+1);
  for(int i=1; i<=n; ++i) {
    str[i+n] = str[i];
  }
  str[2*n+1] = 0;
  n*=2;
  for(int i=1; i<=n; ++i) {
    if (str[i] != 'b') {
      l_red[i] = l_red[i-1]+1;
    }
    if (str[i] != 'r') {
      l_blue[i] = l_blue[i-1]+1;
    }
  }
  for(int i=n; i>0; --i) {
    if (str[i] != 'b') {
      r_red[i] = r_red[i+1]+1;
    }
    if (str[i] != 'r') {
      r_blue[i] = r_blue[i+1]+1;
    }
  }
  int best = 0;
  for(int i=1; i<n; ++i) {
    int result = max(l_red[i], l_blue[i]) + 
      max(r_red[i+1], r_blue[i+1]);
    best = max(best, result);
  }
  if (best > n/2)
    best = n/2;
  fprintf(fout, "%d\n", best);
  return 0;
}
