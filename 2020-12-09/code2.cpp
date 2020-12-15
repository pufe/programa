#include <cstdio>
#include <cstdint>
#include <utility>
#include <algorithm>
using namespace std;

const int maxn = 1024;
int64_t vet[maxn];

pair<bool, int> find_sum(int start, int n, int64_t target) {
  int64_t total=0;
  for(int i=start; i<n; ++i) {
    total+=vet[i];
    if (total==target)
      return make_pair(true, i);
    if (total > target)
      return make_pair(false, 0);
  }
  return make_pair(false, 0);
}

int main() {
  int n=0;
  int64_t target=375054920L;
  printf("%ld\n", target);
  while(scanf(" %ld", &vet[n])==1)
    ++n;
  for(int start=0; start<n; ++start) {
    auto it = find_sum(start, n, target);
    if (it.first) {
      int end = it.second;
      printf("%d~%d\n", start, end);
      int64_t min_v = vet[start], max_v = vet[start];
      for(int i=start+1; i<=end; ++i) {
	min_v = min(min_v, vet[i]);
	max_v = max(max_v, vet[i]);
      }
      printf("%ld + %ld = %ld\n", min_v, max_v, min_v+max_v);
    }
  }
  return 0;
}
