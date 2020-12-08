#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int huge;
const huge inf = 100010001000LL;
const int maxn = 200200;

struct interval {
  huge begin, end;
  vector<huge> bonus;
  huge best_distance() {
    if (bonus.empty())
      return 0;
   
    huge left = 2*(*bonus.rbegin() - begin);
    huge right = 2*(end - *bonus.begin());
    huge best = min(left, right);
    huge through = end - begin;
    best = min(best, through);
    
    for(unsigned i=1; i<bonus.size(); ++i) {
      huge current = 2*(bonus[i-1] - begin + end - bonus[i]);
      best = min(best, current);
    }
    
    return best;
  }
  void debug() {
    printf("%lld ~ %lld\n", begin, end);
    printf("%lu:", bonus.size());
    for(auto i : bonus)
      printf(" %lld", i);
    printf("\n%lld\n\n", best_distance());
  }
};
interval ring[maxn];

int main() {
  int n, m;
  scanf(" %d %d", &n, &m);
  ring[0].begin = -inf;
  ring[n].end = inf;
  for(int i=0; i<n; ++i) {
    scanf(" %lld", &ring[i].end);
    ring[i+1].begin = ring[i].end;
  }
  int current_ring=0;

  for(int i=0; i<m; ++i) {
    huge current_bonus;
    scanf(" %lld", &current_bonus);
    while(current_bonus > ring[current_ring].end)
      ++current_ring;
    ring[current_ring].bonus.push_back(current_bonus);
  }
  huge total=0;
  for(int i=0; i<=n; ++i) {
    // ring[i].debug();
    total+=ring[i].best_distance();
  }
  printf("%lld\n", total);
  return 0;
}
