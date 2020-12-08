#include <cstdio>
#include <cstring>

const int maxn = 128;
char a[maxn], b[maxn];
int dp[maxn][maxn];

int main() {
  int na, nb;
  while(true) {
    if (fgets(a, maxn-1, stdin) == NULL)
      break;
    na = strlen(a);
    fgets(b, maxn-1, stdin);
    nb = strlen(b);
    a[na-1] = 0;
    --na;
    b[nb-1] = 0;
    --nb;
    int max = 0;
    for(int i=1; i<=na; ++i) {
      for(int j=1; j<=nb; ++j) {
	if (a[i-1]==b[j-1]) {
	  dp[i][j] = 1+dp[i-1][j-1];
	}
	else {
	  dp[i][j] = 0;
	}
	if (dp[i][j] > max)
	  max = dp[i][j];
      }
    }
    printf("%d\n", max);
  }
  return 0;
}
