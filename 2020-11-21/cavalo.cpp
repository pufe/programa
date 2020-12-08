#include <cstdio>
#include <utility>
#include <set>
using namespace std;

typedef pair<int, int> coord;

coord dir[9] = {
  {0, 0},
  {1, 2}, {2, 1}, {2, -1}, {1, -2},
  {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}
};

void operator+=(coord& a, const coord b) {
  a.first += b.first;
  a.second += b.second;
}

int main() {
  set<coord> holes = {{1, 3}, {2, 3}, {2, 5}, {5, 4}};
  coord knight = {4, 3};
  int n;
  int moves = 0;
  bool alive = true;
  scanf(" %d", &n);
  for(int i=0; i<n; ++i) {
    int x;
    scanf(" %d", &x);
    knight += dir[x];
    if (alive)
      ++moves;
    if (holes.count(knight) > 0)
      alive = false;
  }
  printf("%d\n", moves);
  return 0;
}
