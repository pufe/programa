#include <cstdio>

const int maxn = 128;
int line[maxn];
int col[maxn];

int main() {
  bool col_low = true;
  bool col_hi = true;
  bool line_low = true;
  bool line_hi = true;
  int n, m;

  while(true) {
    scanf(" %d %d", &n, &m);
    if (n==0 && m==0)
      break;
    for(int i=0; i<n; ++i)
      line[i]=0;
    for(int j=0; j<m; ++j)
      col[j]=0;
    
    col_low = true;
    col_hi = true;
    line_low = true;
    line_hi = true;

    for(int i=0; i<n; ++i)
      for(int j=0; j<m; ++j) {
	int x;
	scanf(" %d", &x);
	line[i]+=x;
	col[j]+=x;
      }
    
    for(int i=0; i<n; ++i) {
      if (line[i]==0)
	line_low=false;
      if (line[i]==m)
	line_hi=false;
    }
    
    for(int j=0; j<m; ++j) {
      if (col[j]==0)
	col_low=false;
      if (col[j]==n)
	col_hi=false;
    }

    printf("%d\n", line_low+line_hi+col_low+col_hi);
  }
  return 0;
}
