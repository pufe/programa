#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define PPP 13
#define DSP 17

struct node_t {
  int cc;
  int party;
  int cost;
  vector<node_t*> adj;
};

struct cc_t {
  int dsp;
  int ppp;
  int cost;
};

const int maxn = 110;
node_t dsp[maxn];
node_t ppp[maxn];
cc_t cc[2*maxn];

void dfs(node_t *p, int color) {
  if (p->cc == 0) {
    p->cc = color;
    if (p->party == PPP)
      cc[color].ppp++;
    else
      cc[color].dsp++;
    cc[color].cost += p->cost;
    for(auto j : p->adj)
      dfs(j, color);
  }
}
const int maxb = 10010;
int dp[maxb];

int knapsack(int n, int b, int party) {
  for(int i=0; i<=b; ++i)
    dp[i]=0;
  for(int i=1; i<=n; ++i) {
    int value = cc[i].dsp - cc[i].ppp;
    if (party == DSP)
      value *= -1;
    for(int j=b; j>=cc[i].cost; --j) {
      dp[j] = max(dp[j], dp[j-cc[i].cost]+value);
    }
  }
  return dp[b];
}

int main() {
  int dsp_size, ppp_size, r, budget;
  int cc_size=0;
  scanf(" %d %d %d %d", &dsp_size, &ppp_size, &r, &budget);
  for(int i=1; i<=dsp_size; ++i) {
    scanf(" %d", &dsp[i].cost);
    dsp[i].party = DSP;
    dsp[i].cc = 0;
  }
  for(int i=1; i<=ppp_size; ++i) {
    scanf(" %d", &ppp[i].cost);
    ppp[i].party = PPP;
    ppp[i].cc = 0;
  }
  for(int i=0; i<r; ++i) {
    int x, y;
    scanf(" %d %d", &x, &y);
    dsp[x].adj.push_back(&ppp[y]);
    ppp[y].adj.push_back(&dsp[x]);
  }
  for(int i=1; i<=dsp_size; ++i) {
    if (dsp[i].cc == 0) {
      ++cc_size;
      dfs(&dsp[i], cc_size);
    }
  }
  for(int i=1; i<=ppp_size; ++i) {
    if (ppp[i].cc == 0) {
      ++cc_size;
      dfs(&ppp[i], cc_size);
    }
  }
  printf("%d %d\n",
	 dsp_size + knapsack(cc_size, budget, DSP),
	 ppp_size + knapsack(cc_size, budget, PPP));
  return 0;
}
