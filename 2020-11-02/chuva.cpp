#include <cstdio>

const int maxn = 505;
char mtx[maxn][maxn];

void debug(int n, int m) {
  for(int i=0; i<=n+2; ++i) {
    for(int j=0; j<=m+1; ++j)
      printf("%c", mtx[i][j]);
    printf("\n");
  }
}

void dfs(int i, int j) {
  mtx[i][j]='o';
  if (mtx[i+1][j] == '#') {
    if (mtx[i][j+1] == '.')
      dfs(i, j+1);
    if (mtx[i][j-1] == '.')
      dfs(i, j-1);
  } else if (mtx[i+1][j] == '.') {
    dfs(i+1, j);
  }
}

int main() {
  int n, m;
  int start_i, start_j;

  scanf(" %d %d", &n, &m);
  for(int i=1; i<=n; ++i) {
    for(int j=1; j<=m; ++j) {
      scanf(" %c", &mtx[i][j]);
      if (mtx[i][j] == 'o') {
	start_i = i;
	start_j = j;
      }
    }
  }
  for(int j=0; j<=m+1; ++j) {
    mtx[0][j] = '#';
    mtx[n+1][j] = '.';
    mtx[n+2][j] = '#';
  }
  for(int i=0; i<=n+2; ++i) {
    mtx[i][0] = '#';
    mtx[i][m+1] = '#';
  }
  dfs(start_i, start_j);
  for(int i=1; i<=n; ++i) {
    for(int j=1; j<=m; ++j)
      printf("%c", mtx[i][j]);
    printf("\n");
  }
  return 0;
}
