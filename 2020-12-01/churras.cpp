#include <cstdio>
#include <algorithm>
using namespace std;

struct meat_t {
  char name[25];
  int d;
  bool operator<(meat_t o) {
    return d < o.d;
  }
};

meat_t meat[15];

int main() {
  int n;
  while(scanf(" %d", &n)==1) {
    for(int i=0; i<n; ++i) {
      scanf(" %s %d", meat[i].name, &meat[i].d);
    }
    sort(meat, meat+n);
    for(int i=0; i<n; ++i) {
      if (i>0)
	printf(" ");
      printf("%s", meat[i].name);
    }
    printf("\n");
  }
  return 0;
}
