#include <cstdio>
#include <vector>
using namespace std;

struct node_t {
  bool visited;
  int color;
  vector<int> adj;
  vector<int> r_adj;
};

const int maxn = 1024;
node_t original[maxn];
node_t reduced[maxn];

void clear(node_t *p) {
  p->visited = false;
  p->color = 0;
  p->adj.clear();
  p->r_adj.clear();
}

void dfs(int x, vector<int> *seq) {
  if (!original[x].visited) {
    original[x].visited = true;
    for(int j : original[x].adj)
      dfs(j, seq);
    seq->push_back(x);
  }
}
void set_color(int x, int c) {
  if (original[x].color == 0) {
    original[x].color = c;
    for(int j : original[x].r_adj)
      set_color(j, c);
  }
}
int kosaraju(int n) {
  int c=0;
  vector<int> seq;
  for(int i=1; i<=n; ++i) {
    if (!original[i].visited)
      dfs(i, &seq);
  }
  for(int i=n-1; i>=0; --i) {
    int x = seq[i];
    if (original[x].color == 0) {
      set_color(x, ++c);
    }
  }
  return c;
}

int main() {
  int n, m;
  int num_tests;
  int a, b;
  int cfc;
  int starting_points;
  scanf(" %d", &num_tests);
  for(int test=0; test<num_tests; ++test) {
    scanf(" %d %d", &n, &m);
    for(int i=1; i<=n; ++i) {
      clear(&original[i]);
      clear(&reduced[i]);
    }
    for(int i=0; i<m; ++i) {
      scanf(" %d %d", &a, &b);
      original[a].adj.push_back(b);
      original[b].r_adj.push_back(a);
    }
    cfc = kosaraju(n);
    for(int i=1; i<=n; ++i) {
      for(int j : original[i].adj) {
	a = original[i].color;
	b = original[j].color;
	if (a != b) {
	  reduced[a].adj.push_back(b);
	  reduced[b].r_adj.push_back(a);
	}
      }
    }
    starting_points = 0;
    for(int i=1; i<=cfc; ++i) {
      if (reduced[i].r_adj.empty())
	++starting_points;
    }
    if (starting_points == 1)
      printf("S\n");
    else
      printf("N\n");
  }
}
