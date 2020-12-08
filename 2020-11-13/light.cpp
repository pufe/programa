#include <cstdio>
#include <algorithm>
using namespace std;

const int inf=0x3fff3fff;
char mtx[10][10];
int n, m, k;

int di[] = {1, -1, 0, 0};
int dj[] = {0, 0, 1, -1};

int count_lamps() {
  int c=0;
  for(int i=1; i<=n; ++i)
    for(int j=1; j<=m; ++j)
      if (mtx[i][j]=='*')
	++c;					
  return c;
}
bool search_lamp(int line, int col) {
  for(int d=0; d<4; ++d) {
    int i=line+di[d];
    int j=col+dj[d];
    while (mtx[i][j]=='.' || mtx[i][j]=='*') {
      if (mtx[i][j]=='*')
	return true;
      i+=di[d];
      j+=dj[d];
    }
  }
  return false;
}
int count_around(int line, int col) {
  int c=0;
  for(int d=0; d<4; ++d) {
    int i=line+di[d];
    int j=col+dj[d];
    if (mtx[i][j]=='*')
      ++c;
  }
  return c;
}
bool check_square(int line, int col) {
  if (mtx[line][col] == '.')
    return search_lamp(line, col);
  else if (mtx[line][col] == '*')
    return !search_lamp(line, col);
  else if (mtx[line][col] != '#')
    return count_around(line, col)==mtx[line][col]-'0';
  return true;
}

bool is_valid() {
  for(int i=1; i<=n; ++i)
    for(int j=1; j<=m; ++j)
      if (!check_square(i, j))
	return false;
  return true;
}

int search(int line, int col) {
  int s = inf;
  if (line > n) {
    /*for(int i=0; i<=n+1; ++i) {
      for(int j=0; j<=m+1; ++j)
	printf("%c", mtx[i][j]);
      printf("\n");
    }
    printf("---\n");*/
    if (is_valid())
      return count_lamps();
    else
      return inf;
  }
  if (col > m) {
    return search(line+1, 1);
  }
  if (mtx[line][col] != '.')
    return search(line, col+1);
  mtx[line][col] = '*';
  if (check_square(line, col) && check_square(line-1, col)) {
    s = min(s, search(line, col+1));
  }
  mtx[line][col] = '.';
  if (mtx[line-1][col]>='0' && mtx[line-1][col]<='4') {
    if (check_square(line-1, col))
      s = min(s, search(line, col+1));
  } else {
    s = min(s, search(line, col+1));
  }
  return s;
}

int main() {
  while(true) {
    scanf(" %d %d", &n, &m);
    if (n==0 && m==0)
      break;
    for(int i=0; i<=n+1; ++i)
      for(int j=0; j<=m+1; ++j)
	if (i==0 || i==n+1 || j==0 || j==m+1)
	  mtx[i][j]='#';
	else
	  mtx[i][j]='.';
    scanf(" %d", &k);
    for(int i=0; i<k; ++i) {
      int line, col, kind;
      scanf(" %d %d %d", &line, &col, &kind);
      if (kind == -1)
	mtx[line][col] = '#';
      else
	mtx[line][col] = '0'+kind;
    }
    int solution;
    solution = search(1,1);
    if (solution < inf)
      printf("%d\n", solution);
    else
      printf("No solution\n");
  }
  return 0;
}
