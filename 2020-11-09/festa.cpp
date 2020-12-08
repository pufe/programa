#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 1024;

struct node_t {
  int color;
  vector<int> adj;
};
node_t node[maxn];
bool dfs(int x, int c) {
  node[x].color = c;
  int nc = 3-c;
  for(auto j : node[x].adj) {
    if (node[j].color == c) {
      return false;
    } else if (node[j].color == 0) {
      if (!dfs(j, nc))
	return false;
    }
  }
  return true;
}
int main() {
  int n;
  int a, b;
  bool possible = true;
  scanf(" %d", &n);
  for(int i=1; i<=n; ++i) {
    node[i].color = 0;
  }
  while(true) {
    if (scanf(" %d %d", &a, &b)!=2)
      break;
    node[a].adj.push_back(b);
    node[b].adj.push_back(a);
  }
  for(int i=1; i<=n; ++i) {
    if (node[i].color == 0) {
      if (!dfs(i, 1))
	possible = false;
    }
  }
  if (possible)
    printf("FESTA!\n");
  else
    printf("Lascou...\n");
  return 0;
}
