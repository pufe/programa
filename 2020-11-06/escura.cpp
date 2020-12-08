#include <cstdio>
#include <vector>
#include <set>
#include <utility> // pair
using namespace std;

const int maxn = 200100;

struct node_t {
  int dist;
  bool visited;
  vector<pair<int,int> > adj; // destino, custo
};

node_t node[maxn];

void remove_from(set<pair<int, int> > &s, int x) {
  auto it = s.find(make_pair(node[x].dist, x));
  if (it != s.end()) {
    s.erase(it);
  }
}

int prim(int start) {
  int total=0;
  node[start].dist=0;
  set<pair<int, int> > s; // custo, node
                          // e tipo priority_queue
  s.insert(make_pair(node[start].dist, start));
  while(!s.empty()) {
    int current = s.begin()->second;
    total += node[current].dist;
    node[current].visited=true;
    s.erase(s.begin());
    for(auto it : node[current].adj) {
      int next = it.first;
      int cost = it.second;
      if (!node[next].visited) {
	if (node[next].dist == -1) {
	  node[next].dist = cost;
	  s.insert(make_pair(node[next].dist, next));
	} else if (node[next].dist > cost) {
	  remove_from(s, next);
	  node[next].dist = cost;
	  s.insert(make_pair(node[next].dist, next));
	}
      }
    }
  }
  return total;
}

int main() {
  int n, m;
  int x, y, z;
  int total;
  while(true) {
    scanf(" %d %d", &n, &m);
    if (n==0 && m==0)
      break;
    total = 0;
    for(int i=0; i<n; ++i) {
      node[i].dist= -1; // -1 special value
      node[i].adj.clear();
      node[i].visited=false;
    }
    for(int i=0; i<m; ++i) {
      scanf(" %d %d %d", &x, &y, &z);
      node[x].adj.push_back(make_pair(y, z));
      node[y].adj.push_back(make_pair(x, z));
      total += z;
    }
    printf("%d\n", total-prim(0));
  }
  return 0;
}
