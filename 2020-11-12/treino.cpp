#include <cstdio>
#include <set> //multiset
using namespace std;

const int maxn = 100100;
int vet[maxn];
int cost[maxn];

int main() {
  int n, base, rate;
  scanf(" %d %d", &n, &base);
  for(int i=0; i<n; ++i) {
    scanf(" %d", &vet[i]);
  }
  scanf(" %d", &rate);
  for(int i=0; i<n; ++i) {
    scanf(" %d", &cost[i]);
  }
  multiset<int> q;
  int level = 0;
  long long int total = 0;
  bool impossible = false;
  for(int i=0; i<n; ++i) {
    q.insert(cost[i]);
    int level_required = (vet[i]-base+rate-1)/rate;
    if (level_required-level > int(q.size()))
      impossible = true;
    else {
      while(level < level_required) {
	total += *q.begin();
	q.erase(q.begin());
	++level;
      }
    }
  }
  if (impossible)
    printf("-1\n");
  else
    printf("%lld\n", total);
  return 0;
}
