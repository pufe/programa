#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 128;
int cost[maxn];

int main() {
  int num_tests;
  scanf(" %d", &num_tests);
  for(int t=0; t<num_tests; ++t) {
    int money, num_ingredients, num_recipes;
    int most_cakes = 0;
    scanf(" %d %d %d", &money, &num_ingredients, &num_recipes);
    for(int i=0; i<num_ingredients; ++i)
      scanf(" %d", &cost[i]);
    for(int i=0; i<num_recipes; ++i) {
      int c=0;
      int qt, x, times;
      scanf(" %d", &qt);
      for(int j=0; j<qt; ++j) {
	scanf(" %d %d", &x, &times);
	c += cost[x]*times;
      }
      most_cakes = max(most_cakes, money/c);
    }
    printf("%d\n", most_cakes);
  }
  return 0;
}
