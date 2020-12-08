#include <cstdio>
#include <cstring>
#include <algorithm>

struct suffix_t {
  int pos;
  int rank, rank_delta, next_rank;
};

const int maxn = 100100;

char str[maxn];
suffix_t suffix[maxn];
int order[maxn];

bool cmp(const int a, const int b) {
  if (suffix[a].rank != suffix[b].rank)
    return suffix[a].rank < suffix[b].rank;
  return suffix[a].rank_delta < suffix[b].rank_delta;
}

void debug(int n) {
  for(int i=0; i<n; ++i) {
    int j = order[i];
    printf("%3d: %c %d %d -> %d\n", j, str[j], 
	   suffix[j].rank, suffix[j].rank_delta,
	   suffix[j].next_rank);
  }
  printf("---\n");
}
int main() {
  int n, delta;
  scanf(" %s", str);
  n = strlen(str);
  for(int i=0; i<n; ++i) {
    order[i] = i;
    suffix[i].next_rank = str[i];
  }
  delta=1;
  while(delta < n) {
    for(int i=0; i<n; ++i) {
      suffix[i].rank = suffix[i].next_rank;
      suffix[i].rank_delta = suffix[(i+delta)%n].next_rank;
    }
    //debug(n);
    std::sort(order, order+n, cmp);
    int current_rank = 0;
    suffix[order[0]].next_rank = 0;
    for(int i=1; i<n; ++i) {
      int current = order[i];
      int prev = order[i-1];
      if (suffix[current].rank != suffix[prev].rank ||
	  suffix[current].rank_delta != suffix[prev].rank_delta)
	++current_rank;
      suffix[current].next_rank = current_rank;
    }
    delta *= 2;
  }
  int count = 1;
  int min = order[n-1];
  for(int i=n-2; i>=0; --i) {
    int j = order[i];
    if (suffix[j].next_rank != suffix[min].next_rank)
      break;
    else if (j < min)
      min = j;
    ++count;
  }
  printf("%d %d\n", count, min+1);
  return 0;
}
