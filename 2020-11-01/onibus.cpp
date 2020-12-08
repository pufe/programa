#include <cstdio>
#include <queue>
using namespace std;

const int inf = 1000000;
const int maxn = 505;

struct linha_t {
  bool has[maxn];
  int q;
  int station[maxn];
};

linha_t linha[maxn];
int min_dist[maxn];

void bfs(int start, int m) {
  queue<int> q;
  min_dist[start] = 0;
  q.push(start);
  while(!q.empty()) {
    int v = q.front();
    //printf("debug: %d %d\n", v, min_dist[v]);
    q.pop();
    for(int i=0; i<m; ++i) {
      if (linha[i].has[v]) {
	for(int j=0; j<linha[i].q; ++j) {
	  int x = linha[i].station[j];
	  if (min_dist[x] > min_dist[v]+1) {
	    min_dist[x] = min_dist[v]+1;
	    q.push(x);
	  }
	}
      }
    }
  }
}

void debug_linha(int i, int n) {
  printf("linha %d\n", i);
  printf("%d\n", linha[i].q);
  for(int j=0; j<n; ++j)
    printf("%d", linha[i].has[j]? 1 : 0);
  printf("\n");
  for(int j=0; j<linha[i].q; ++j) {
    printf(" %d", linha[i].station[j]);
  }
  printf("\n\n");
}

int main() {
  int n, m, start, end;
  scanf(" %d %d %d %d", &n, &m, &start, &end);
  --start;
  --end;
  for(int i=0; i<n; ++i) {
    min_dist[i] = inf;
  }
  for(int i=0; i<m; ++i) {
    scanf(" %d", &linha[i].q);
    for(int j=0; j<n; ++j) {
      linha[i].has[j] = false;
    }
    for(int j=0; j<linha[i].q; ++j) {
      scanf(" %d", &linha[i].station[j]);
      linha[i].station[j]--;
      linha[i].has[linha[i].station[j]] = true;
    }
    //debug_linha(i, n);
  }
  
  bfs(start, m);
  printf("%d\n", min_dist[end]);
  return 0;
}
