#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 1024;

struct event_t {
  bool is_true;
  bool is_root;
  vector<int> implies;
  vector<int> causes;
  int cookie;
};

event_t event[maxn];

void dfs(int i, int root) {
  event[i].cookie = root;
  event[i].causes.push_back(root);
  for(auto j : event[i].implies) {
    if (event[j].cookie != root)
      dfs(j, root);
  }
}

bool contains(int a, int b) {
  unsigned pa=0, pb=0;
  while(pa < event[a].causes.size() 
	&& pb < event[b].causes.size()) {
    if (event[a].causes[pa] < event[b].causes[pb]) {
      pa++;
    } else if (event[a].causes[pa] == event[b].causes[pb]) {
      pa++;
      pb++;
    } else {
      return false;
    }
  }
  return pb >= event[b].causes.size();
}

int main() {
  int n, m, v;
  scanf(" %d %d %d", &n, &m, &v);

  for(int i=1; i<=n; ++i) { // setup nodes
    event[i].is_true = false;
    event[i].is_root = true;
    event[i].cookie = 0;
  }
  
  for(int i=0; i<m; ++i) { // read graph
    int a, b;
    scanf(" %d %d", &a, &b);
    event[a].implies.push_back(b);
    event[b].is_root = false;
  }
  
  for(int i=1; i<=n; ++i) { // sets causes
    if (event[i].is_root) {
      dfs(i, i);
    }
  }
  
  for(int i=0; i<v; ++i) { // known events
    int x;
    scanf(" %d", &x);
    if (!event[x].is_true) {
      event[x].is_true = true;
      for(int j=1; j<=n; ++j) // deductions
	if (!event[j].is_true && contains(j, x)) {
	  event[j].is_true = true;
	}
    }
  }

  bool first=true;
  for(int i=1; i<=n; ++i) {
    if (event[i].is_true) {
      if (first) {
	printf("%d", i);
	first = false;
      } else {
	printf(" %d", i);
      }
    }
  }
  printf("\n");
  return 0;
}
