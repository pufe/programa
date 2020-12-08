#include <cstdio>
#include <stack> // stack<>
#include <utility> // pair<>
using namespace std;

const int maxn = 1024;
int mtx[maxn][maxn] = {};

void dfs(int i, int j, int c) {
  stack<pair<int, int> > st;
  mtx[i][j]=c;
  st.push(make_pair(i, j));

  while(!st.empty()) {
    pair<int, int> p = st.top();
    st.pop();
    i = p.first;
    j = p.second;
    
    if (mtx[i+1][j]==-1) {
      mtx[i+1][j]=c;
      st.push(make_pair(i+1, j));
    }
    if (mtx[i-1][j]==-1) {
      mtx[i-1][j]=c;
      st.push(make_pair(i-1, j));
    }
    if (mtx[i][j+1]==-1) {
      mtx[i][j+1]=c;
      st.push(make_pair(i, j+1));
    }
    if (mtx[i][j-1]==-1) {
      mtx[i][j-1]=c;
      st.push(make_pair(i, j-1));
    }
  } 
}

int main() {
  int n, m;
  int regions=0;

  scanf(" %d %d", &n, &m);
  for(int i=1; i<=n; ++i) {
    for(int j=1; j<=m; ++j) {
      scanf(" %d", &mtx[i][j]);
      if (mtx[i][j]==1)
	mtx[i][j]=-1;
    }
  }
  for(int i=1; i<=n; ++i) {
    for(int j=1; j<=m; ++j) {
      if (mtx[i][j] == -1) {
	dfs(i, j, ++regions);
      }
    }
  }
  printf("%d\n", regions);
  return 0;
}
