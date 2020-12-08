/*
  ID: pufepro1
  LANG: C++
  TASK: milk
*/
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

struct farm_t {
  int price;
  int qty;
  bool operator<(farm_t o) {
    return price<o.price;
  }
};
const int maxn = 5050;
farm_t farm[maxn];

int main() {
  FILE *fin  = fopen("milk.in", "r");
  FILE *fout = fopen("milk.out", "w");

  int n, m;
  fscanf(fin, " %d %d", &n, &m);
  for(int i=0; i<m; ++i)
    fscanf(fin, " %d %d", &farm[i].price, &farm[i].qty);
  sort(farm, farm+m);
  int total=0;
  for(int i=0; i<m; ++i) {
    if (n > farm[i].qty) {
      n -= farm[i].qty;
      total += farm[i].price * farm[i].qty;
    }
    else {
      total += farm[i].price * n;
      n = 0;
    }
  }
  fprintf(fout, "%d\n", total);
  return 0;
}
