#include <cstdio>
#include <stack>
#include <utility>
#include <algorithm>
using namespace std;

const int maxn = 1024;

char mtx[maxn][maxn];
int vsum[maxn][maxn];
int rsum[maxn][maxn];
int n, m;

int find_square() {
  int r=0;
  stack<pair<int, int> > st; // where starts, height
  for(int i=1; i<=n; ++i) {
    for(int j=1; j<=m; ++j) {
      int start = j;
      while(!st.empty() && st.top().second > vsum[i][j]) {
	int width = j - st.top().first;
	int height = st.top().second;
	r = max(r, min(width, height));
	start = st.top().first;
	st.pop();
      }
      st.push(make_pair(start, vsum[i][j]));
    }
    while(!st.empty()) {
      int width = m - st.top().first + 1;
      int height = st.top().second;
      r = max(r, min(width, height));
      st.pop();
    }
  }
  return r;
}

bool is_empty_square(int i, int j, int s) {
  i--; j--;
  return rsum[i+s][j+s]-rsum[i][j+s]-rsum[i+s][j]+rsum[i][j]==0;
}

int main() {
  int nt;
  int s, q;
  for(scanf(" %d", &nt); nt>0; nt--) {
    scanf(" %d %d", &n, &m);
    for(int i=1; i<=n; ++i)
      for(int j=1; j<=m; ++j) {
	scanf(" %c", &mtx[i][j]);
	rsum[i][j]=rsum[i-1][j]+rsum[i][j-1]-rsum[i-1][j-1];
	vsum[i][j]=0;
	if (mtx[i][j]=='*')
	  ++rsum[i][j];
	else
	  vsum[i][j]=vsum[i-1][j]+1;
      }
    s = find_square();
    if (s==0)
      throw 1;
    q = 0;
    printf("The side of the square is %d and the locations are:\n",
	   s);
    for(int i=1; i<=n-s+1; ++i)
      for(int j=1; j<=m-s+1; ++j)
	if (is_empty_square(i, j, s)) {
	  printf("%d %d\n", i, j);
	  ++q;
	}
    printf("%d in total.\n", q);
  }
  return 0;
}
