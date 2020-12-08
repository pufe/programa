#include <cstdio>
#include <algorithm>
using namespace std;

int n, m;
int c[4];

bool possible() {
  if (n==1 || m == 1) {
    return true;
  } else if (n==2) {
    return c[1]-c[0] >= m-1;
  } else {
    if (c[1]-c[0]<m-1)
      return false;
    if (c[2]-c[1]<m-1)
      return false;
    if (c[2]-c[0]<(m-1)*(m-1))
      return false;
    return true;
  }
}

int main() {
  while(scanf(" %d %d", &n, &m)==2) {
    for(int i=0; i<n; ++i) {
      scanf(" %d", &c[i]);
    }
    sort(c, c+n);
    if (possible()) {
      printf("Lucky Denis!\n");
    } else {
      printf("Try again later, Denis...\n");
    }
  }
}
