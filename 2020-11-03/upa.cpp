#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 100100;
bool eliminated[maxn] = {};
vector<int> adj[maxn];

int main() {
  int n, m;
  int u, v;
  int c=0;
  scanf(" %d %d", &n, &m);
  for(int i=0; i<m; ++i) {
    scanf(" %d %d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for(int i=n; i>0; --i) {
    if (!eliminated[i]) {
      ++c;
      for(auto j : adj[i]) {
	eliminated[j]=true;
      }
    }
  }
  printf("%d\n", c);
  bool first=true;
  for(int i=1; i<=n; ++i) {
    if (!eliminated[i]) {
      if (first) {
	printf("%d", i);
	first=false;
      }
      else {
	printf(" %d", i);
      }
    }
  }
  printf("\n");
  return 0;
}
