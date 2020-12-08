#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct hand_t {
  int v[4];
  int set, pair, single;
  void setup(int a, int b, int c) {
    v[0] = a;
    v[1] = b;
    v[2] = c;
    set=0;
    pair=0;
    single=0;
    sort(v, v+3);
    if (v[0] == v[2]) {
      set = v[0];
    } else if (v[0] == v[1]) {
      pair = v[0];
      single = v[2];
    } else if (v[1] == v[2]) {
      pair = v[1];
      single = v[0];
    }
  }
};

bool operator<(const hand_t a, const hand_t b) {
  if (a.set != b.set)
    return a.set < b.set;
  if (a.pair != b.pair)
    return a.pair < b.pair;
  return a.single < b.single;
}

int main() {
  int a, b, c;
  hand_t x;
  vector<hand_t> hand;
  for(int i=1; i<=13; ++i) {
    for(int j=1; j<=13; ++j) {
      x.setup(i, i, j);
      hand.push_back(x);
    }
  }
  sort(hand.begin(), hand.end());
  while(true){ 
    scanf(" %d %d %d", &a, &b, &c);
    if (a==0 && b==0 && c==0)
      break;
    x.setup(a, b, c);
    auto it = upper_bound(hand.begin(), hand.end(), x);
    if (it == hand.end())
      printf("*\n");
    else
      printf("%d %d %d\n", it->v[0], it->v[1], it->v[2]);
  }
  return 0;
}
