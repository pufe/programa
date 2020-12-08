#include <cstdio>
#include <unordered_set>
using namespace std;
const int maxn = 300;

int main() {
  unordered_set<int> s;
  int v[maxn];
  int n=0;
  while(scanf(" %d", &v[n])==1) {
    s.insert(v[n]);
    ++n;
  }
  for(int i=0; i<n; ++i)
    for(int j=i+1; j<n; ++j) {
      int f = 2020-v[i]-v[j];
      if (s.count(f)>0)
	printf("%d+%d+%d=2020, prod=%d\n", v[i], v[j], f, v[i]*v[j]*f);
    }
  return 0;
}
