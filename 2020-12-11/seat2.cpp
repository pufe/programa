#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 128;

char current[maxn][maxn];
char next_state[maxn][maxn];
int n, m;

void read_input() {
  n=0;
  while(scanf(" %s", current[n])==1) {
    ++n;
  }
  m = strlen(current[0]);
}

bool inside(int x, int y) {
  return x>=0 && x<n && y>=0 && y<m;
}

bool search(int x1, int y1, int x2, int y2) {
  int dx = x2-x1;
  int dy = y2-y1;
  while(inside(x2,y2)) {
    if (current[x2][y2]=='#')
      return true;
    if (current[x2][y2]=='L')
      return false;
    x2+=dx;
    y2+=dy;
  }
  return false;
}

int count_around(int x, int y) {
  int t=0;
  for(int i=max(0,x-1); i<=min(n-1,x+1); ++i)
    for(int j=max(0,y-1); j<=min(m-1,y+1); ++j)
      if (i!=x || j!=y)
	if (search(x, y, i, j))
	  ++t;
  return t;
}

void calculate_next() {
  for(int i=0; i<n; ++i)
    for(int j=0; j<m; ++j) {
      next_state[i][j] = current[i][j];
      if (current[i][j]=='L' && count_around(i, j)==0)
	next_state[i][j] = '#';
      else if (current[i][j]=='#' && count_around(i, j)>=5)
	next_state[i][j] = 'L';
    }
}

bool has_no_differences() {
  for(int i=0; i<n; ++i)
    for(int j=0; j<m; ++j)
      if (current[i][j] != next_state[i][j])
	return false;
  return true;
}
void copy_next_to_current() {
  for(int i=0; i<n; ++i)
    for(int j=0; j<m; ++j)
      current[i][j] = next_state[i][j];
}
int count_occupied_seats() {
  int t=0;
  for(int i=0; i<n; ++i)
    for(int j=0; j<m; ++j)
      if (current[i][j]=='#')
	++t;
  return t;
}

int main() {
  int t=0;
  read_input();
  while(true) {
    printf("debug -> %d\n", t++);
    calculate_next();
    if (has_no_differences())
      break;
    copy_next_to_current();
  }
  printf("%d\n", count_occupied_seats());
  return 0;
}
