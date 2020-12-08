#include <cstdio>

const int maxn = 128;

char mtx[maxn][maxn];
int di[] = {0, 0, -1, 1};
int dj[] = {1, -1, 0, 0};

int main() {
  int n, m, k;
  int pi, pj;
  int dir;
  int total;
  while(true) {
    scanf(" %d %d %d", &n, &m, &k);
    if (n==0 && m==0 && k==0)
      break;
    dir = 0;
    total = 0;
    for(int i=0; i<n; ++i) {
      for(int j=0; j<m; ++j) {
	scanf("%c", &mtx[i][j]);
	if (mtx[i][j] == '<') {
	  pi = i;
	  pj = j;
	  mtx[i][j] = ' ';
	}
      }
      scanf("%*c");
    }
    for(int i=0; i<k; ++i) {
      char cmd;
      scanf(" %c", &cmd);
      if (cmd == 'R')
	dir = 0;
      else if (cmd == 'L')
	dir = 1;
      else if (cmd == 'U')
	dir = 2;
      else if (cmd == 'D')
	dir = 3;
      else {
	int ni = pi + di[dir];
	int nj = pj + dj[dir];
	if (mtx[ni][nj] == '*') {
	  total++;
	  pi = ni;
	  pj = nj;
	  mtx[ni][nj] = ' ';
	} else if (mtx[ni][nj] == ' ') {
	  pi = ni;
	  pj = nj;
	}
      }
    }
    printf("%d\n", total);
  }
  return 0;
}
