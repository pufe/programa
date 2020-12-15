#include <cstdio>
#include <set>
using namespace std;

const int maxn = 666;
set<int> dp[maxn][maxn]; 
// dp[i][j] = todos os nímeros alcançáveis
// com i pedras numa pilha e j divisões

int nim[maxn];

int mex(set<int>& s) {
  for(int x=0; ;x++)
    if (s.count(x)==0)
      return x;
  return -1;
}

int main() {
  int n, m, k;
  scanf(" %d %d %d", &n, &m, &k);
  nim[1]=0;
  for(int q=1; q<=k; ++q)
    dp[1][q].insert(0);
  for(int i=2; i<=n; ++i) {
    for(int q=2; q<=k; ++q) {
      for(int j=1; j<i; ++j) {
	for(auto v : dp[i-j][q-1]) { // n^4 log(n) (?!)
	  dp[i][q].insert(nim[j]^v);
	}
      }
    }
    nim[i]=mex(dp[i][k]);
    printf("nim(%d) = %d\n", i, nim[i]);
    dp[i][1].insert(nim[i]);
  }
  return 0;
}
