/*
  ID: pufepro1
  LANG: C++
  TASK: barn1
*/
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

const int maxn = 256;
bool stall[maxn];

int main() {
  FILE *fin  = fopen("barn1.in", "r");
  FILE *fout = fopen("barn1.out", "w");

  // code goes here
  int m, n, q;
  int total = 0;
  vector<int> space;
  fscanf(fin, " %d %d %d", &m, &n, &q);
  for(int i=0; i<=n; ++i)
    stall[i] = false;
  for(int i=0; i<q; ++i) {
    int x;
    fscanf(fin, " %d", &x);
    stall[x]=true;
  }
  
  int start = 0;
  int end = 0;
  for(int i=1; i<=n; ++i) {
    if (stall[i]) {
      if (start == 0)
	start = i;
      end = i;
    }
  }
  total = end - start + 1;
  int space_start = 0;
  int space_end = 0;
  for(int i=start; i<end; ++i) {
    if (stall[i] && !stall[i+1]) {
      space_start = i;
    } else if (!stall[i] && stall[i+1]) {
      space_end = i;
      space.push_back(space_end - space_start);
    }
  }
  sort(space.begin(), space.end(), greater<int>());
  for(int i=0; i<m-1 && i<(int)space.size(); ++i)
    total -= space[i];
  fprintf(fout, "%d\n", total);
  return 0;
}
