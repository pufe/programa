#include <cstdio>
#include <vector>
#include <utility>
#include <set>
using namespace std;

const int maxn = 505;
const int inf = 0x3fff3fff;

struct node_t {
  bool visited;
  int country;
  int dist;
  vector<pair<int, int> > adj;
  vector<int> r_adj;
};

node_t original[maxn];
node_t reduced[maxn];

void clear_node(node_t &v) {
  v.visited = false;
  v.country = 0;
  v.dist = inf;
  v.adj.clear();
  v.r_adj.clear();
}

void Visit(int x, vector<int> &L) {
  if (!original[x].visited) {
    original[x].visited=true;
    for(auto j : original[x].adj) {
      Visit(j.first, L);
    }
    L.push_back(x);
  }
}

void Assign(int u, int c) {
  if (original[u].country == 0) {
    original[u].country = c;
    for(auto j : original[u].r_adj) {
      Assign(j, c);
    }
  }
}

void kosaraju(int n) {
  int c=0;
  vector<int> L;
  for(int i=1; i<=n; ++i) {
    Visit(i, L);
  }
  for(int i=n-1; i>=0; --i) {
    int u = L[i];
    if (original[u].country==0) {
      Assign(u, ++c);
    }
  }
}

void remove_from(set<pair<int, int> > &s, int x) {
  auto it = s.find(make_pair(reduced[x].dist, x));
  if (it != s.end()) {
    s.erase(it);
  }
}

void dijkstra(int start, int n) {
  for(int i=1; i<=n; ++i) {
    reduced[i].visited = false;
    reduced[i].dist = inf;
  }

  reduced[start].dist=0;
  set<pair<int, int> > s; // custo, node
                          // e tipo priority_queue
  s.insert(make_pair(reduced[start].dist, start));
  while(!s.empty()) {
    int current = s.begin()->second;
    reduced[current].visited=true;
    s.erase(s.begin());
    for(auto it : reduced[current].adj) {
      int next = it.first;
      int cost = reduced[current].dist + it.second;
      if (!reduced[next].visited) {
	if (reduced[next].dist == -1) {
	  reduced[next].dist = cost;
	  s.insert(make_pair(reduced[next].dist, next));
	} else if (reduced[next].dist > cost) {
	  remove_from(s, next);
	  reduced[next].dist = cost;
	  s.insert(make_pair(reduced[next].dist, next));
	}
      }
    }
  }
}

void debug(int n) {
  for(int i=1; i<=n; ++i) {
    printf("node %d c->%d\n", i, original[i].country);
  }  
}
int main() {
  int n, m;
  int x, y, z;
  while(true) {
    scanf(" %d %d", &n, &m);
    if (n==0 && m==0)
      break;
    for(int i=1; i<=n; ++i) {
      clear_node(original[i]);
      clear_node(reduced[i]);
    }
    for(int i=0; i<m; ++i) {
      scanf(" %d %d %d", &x, &y, &z);
      original[x].adj.push_back(make_pair(y, z));
      original[y].r_adj.push_back(x);
    }
    kosaraju(n);
    for(int i=1; i<=n; ++i) {
      for(auto j : original[i].adj) {
	int a = original[i].country;
	int b = original[j.first].country;
	reduced[a].adj.push_back(make_pair(b, j.second));
      }
    }
    scanf(" %d", &z);
    for(int i=0; i<z; ++i) {
      scanf(" %d %d", &x, &y);
      x = original[x].country;
      y = original[y].country;
      dijkstra(x, n);
      if (reduced[y].dist == inf) {
	printf("Nao e possivel entregar a carta\n");
      } else {
	printf("%d\n", reduced[y].dist);
      }
    }
    printf("\n");
  }
  return 0;
}
