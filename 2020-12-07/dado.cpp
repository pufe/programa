#include <cstdio>
#include <set>
using namespace std;

struct player_t {
  int pos;
  bool jinxed;
};

player_t p[16];

int main() {
  int n, q, m;
  int winner;
  int current_player;
  set<int> traps;
  while(true) {
    scanf(" %d %d", &n, &m);
    if (n==0 && m==0)
      break;
    for(int i=0; i<n; ++i) {
      p[i].pos=0;
      p[i].jinxed=false;
    }
    traps.clear();
    for(int i=0; i<3; ++i) {
      int x;
      scanf(" %d", &x);
      traps.insert(x);
    }
    scanf(" %d", &q);
    current_player=0;
    for(int i=0; i<q; ++i) {
      int x, y;
      scanf(" %d %d", &x, &y);
      while(p[current_player].jinxed) {
	p[current_player].jinxed=false;
	current_player = (current_player+1)%n;
      }
      p[current_player].pos += x+y;
      if (traps.count(p[current_player].pos)>0)
	p[current_player].jinxed=true;
      if (p[current_player].pos > m)
	winner = current_player+1;
      /*printf("debug p%d -> %d %c\n", 
	     current_player,
	     p[current_player].pos,
	     p[current_player].jinxed ? '%' : ' ');*/
      current_player = (current_player+1)%n;
    }
    printf("%d\n", winner);
  }
  return 0;
}
