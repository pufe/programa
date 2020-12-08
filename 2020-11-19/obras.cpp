#include <cstdio>
#include <algorithm>
using namespace std;

enum state_t {
  before_work,
  vacationing,
  working,
};

const int maxn = 220;

bool work[maxn][maxn];

int main() {
  int test=1;
  while(true) {
    int n, m = 0;
    int total = 0;
    scanf(" %d", &n);
    if (n==0)
      break;
    for(int i=0; i<n; ++i) {
      int x;
      scanf(" %d", &x);
      m = max(m, x);
      for(int j=0; j<maxn; ++j) {
	work[i][j]= j<x;
      }
    }
    int hire, fire, salary, vacation;
    scanf(" %d %d %d %d", &hire, &fire, &salary, &vacation);
    int vacation_limit = (fire+hire)/vacation;
    for(int j=0; j<m; ++j) {
      state_t s = before_work;
      int num_vacation=0;
      for(int i=0; i<n; ++i) {
	switch(s) {
	case before_work:
	  if (work[i][j]) {
	    s = working;
	    total += hire;
	    total += salary;
	  }
	  break;
	case vacationing:
	  if (work[i][j]) {
	    s = working;
	    if (num_vacation > vacation_limit) {
	      total += fire+hire;
	    } else {
	      total += num_vacation*vacation;
	    }
	    num_vacation = 0;
	    total += salary;
	  }
	  else {
	    ++num_vacation;
	  }
	  break;
	case working:
	  if (work[i][j]) {
	    total += salary;
	  }
	  else {
	    s = vacationing;
	    num_vacation=1;
	  }
	  break;
	}
      }
      total+=fire;
    }
    printf("Instancia %d\n", test++);
    printf("%d\n\n", total);
  }
  return 0;
}
