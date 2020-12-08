#include <cstdio>

const int maxn = 128;

char mtx[maxn][maxn];
int passes[maxn][maxn];

int dx[4] = {1, -1, 0,  0};
int dy[4] = {0,  0, 1, -1};

char search(int x, int y) {
  int dir = 2;
  while(mtx[x][y]!='*' && mtx[x][y]!='!') {
    switch(mtx[x][y]) {
    case '<': dir = 3; break;
    case '>': dir = 2; break;
    case '^': dir = 1; break;
    case 'v': dir = 0; break;
    }
    passes[x][y] ++;
    if (passes[x][y] >= 4)
      mtx[x][y] = '!';
    x += dx[dir];
    y += dy[dir];
  }
  return mtx[x][y];
}

int main() {
  int lines, cols;
  scanf(" %d %d", &cols, &lines);
  for(int i=0; i<=lines+1; ++i)
    for(int j=0; j<=cols+1; ++j) {
      mtx[i][j] = '!';
    }
  for(int i=1; i<=lines; ++i)
    for(int j=1; j<=cols; ++j)
      scanf(" %c", &mtx[i][j]);
  printf("%c\n", search(1, 1));
  return 0;
}
