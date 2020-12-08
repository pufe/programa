#include <cstdio>
#include <algorithm>
using namespace std;

int dp[1024];


int main() {
  int n, c;
  int w, v;
  int test=1;
  while(true){
    scanf(" %d %d", &n, &c);
    if (n==0 && c==0)
      break;
    printf("Caso %d: ", test++);
    for(int i=0; i<=c; ++i)
      dp[i]=0;
    for(int i=0; i<n; ++i) {
      scanf(" %d %d", &w, &v);
      for(int j=c; j>=w; --j)
	dp[j] = max(dp[j], dp[j-w]+v);
    }
    printf("%d\n", dp[c]);
  }
  return 0;
}
