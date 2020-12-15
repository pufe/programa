#include <cstdio>
#include <cstdint>
#include <set>
using namespace std;

const int maxn = 1024;
int64_t vet[maxn];

bool is_sum_of_two(multiset<int64_t> s, int64_t x) {
  for(auto a : s) {
    int64_t b = x-a;
    if (b==a) {
      if (s.count(b)>=2)
	return true;
    } else {
      if (s.count(b)>=1)
	return true;
    }
  }
  return false;
}

int main() {
  int n=0;
  while(scanf(" %ld", &vet[n])==1)
    ++n;
  multiset<int64_t> active;
  for(int i=0; i<25; ++i)
    active.insert(vet[i]);
  for(int i=25; i<n; ++i) {
    if (!is_sum_of_two(active, vet[i]))
      printf("%ld\n", vet[i]);
    active.erase(active.find(vet[i-25]));
    active.insert(vet[i]);
  }
  return 0;
}
