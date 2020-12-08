#include <cstdio>
#include <cstring>
#include <utility>
using namespace std;

char mtx[400][40];

int count_trees(int x, int y, int dx, int dy, int n, int m) {
  int c=0;
  while(x<n) {
    if (mtx[x][y]=='#')
      ++c;
    x+=dx;
    y+=dy;
    y%=m;
  }
  return c;
}

int main() {
  pair<int, int> dir[] = {{1, 1}, {1, 3}, {1, 5}, {1, 7}, {2, 1}};
  int n=0;
  while(scanf("%s", mtx[n])==1)
    ++n;
  int m = strlen(mtx[0]);
  long long int p = 1;
  for(int i=0; i<5; ++i) {
    int x = count_trees(0,0,dir[i].first,dir[i].second,n,m);
    printf("%d\n", x);
    p *= x;
  }
  printf("%lld\n", p);
  return 0;
}
