#include <cstdio>
#include <deque>
using namespace std;

void solve(int n) {
  deque<int> cards;
  deque<int> discards;
  for(int i=1; i<=n; ++i) {
    cards.push_back(i);
  }
  while(cards.size() > 1) {
    discards.push_back(cards.front());
    cards.pop_front();
    cards.push_back(cards.front());
    cards.pop_front();
  }
  printf("Discarded cards:");
  for(int i=0; i<n-1; ++i) {
    if (i>0)
      printf(",");
    printf(" %d", discards[i]);
  }
  printf("\nRemaining card: %d\n", cards.front());
}

int main() {
  int n;
  while(true) {
    scanf(" %d", &n);
    if (n==0)
      break;
    solve(n);
  }
  return 0;
}
