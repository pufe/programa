#include <cstdio>

struct music_t {
  int duration;
  bool played;
};

const int maxm = 128;
music_t music[maxm];

int main() {
  int m, k, x;
  int missing_tracks;
  int total_time;
  while(scanf(" %d %d", &m, &k)==2) {
    total_time = 0;
    missing_tracks = m;
    for(int i=1; i<=m; ++i) {
      scanf(" %d", &music[i].duration);
      music[i].played = false;
    }
    for(int i=0; i<k; ++i) {
      scanf(" %d", &x);
      total_time += music[x].duration;
      if (!music[x].played) {
	--missing_tracks;
	if (missing_tracks == 0)
	  printf("%d\n", total_time);
	music[x].played=true;
      }
    }
    if (missing_tracks > 0)
      printf("-1\n");
  }
  return 0;
}
