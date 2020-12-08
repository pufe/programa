#include <cstdio>
#include <vector>
using namespace std;

bool is_square(int n) {
  for(int i=1; i*i<=n; ++i) {
    if (i*i == n)
      return true;
  }
  return false;
}

int hanoi(int n) {
  vector<int> h(n);
  int i=1;
  while(true) {
    bool found = false;
    for(int j=0; j<n; ++j) {
      if (h[j]==0 || is_square(h[j]+i)) {
	h[j]=i;
	++i;
	found = true;
	break;
      }
    }
    if (!found)
      return i-1;
  }
  return -1;
}

int main() {
  int t, n;
  for(scanf(" %d", &t); t>0; --t) {
    scanf(" %d", &n);
    printf("%d\n", hanoi(n));
  }
  return 0;
}
