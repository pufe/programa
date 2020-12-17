#include <cstdio>
#include <queue>
using namespace std;

const int maxn = 1024;
int mtx[maxn][maxn];

int main() {
  int h, w, n;
  queue<int> q;
  while(true) {
    scanf(" %d %d %d", &h, &w, &n);
    if (h==0 && w==0 && n==0)
      break;
    for(int i=0; i<h; ++i)
      for(int j=0; j<w; ++j)
	scanf(" %d", &mtx[i][j]);
    for(int i=0; i<n; ++i) {
      int x;
      scanf(" %d", &x);
      q.push(x);
    }
    for(int j=w-1; j>=0; --j)
      for(int i=h-1; i>=0; --i) {
	if (mtx[i][j] == 0) {
	  if (!q.empty()) {
	    mtx[i][j] = q.front();
	    q.pop();
	  }
	}
      }
    while(!q.empty())
      q.pop();
    for(int i=0; i<h; ++i) {
      printf("%d", mtx[i][0]);
      for(int j=1; j<w; ++j)
	printf(" %d", mtx[i][j]);
      printf("\n");
    }
  }
  return 0;
}
