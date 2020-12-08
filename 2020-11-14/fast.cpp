#include <cstdio>

int turn;
bool finished;

int points[2];
int games[2];

bool won_game() {
  if (points[turn] == 10)
    return true;
  return points[turn] >= 5 && points[turn] - points[1-turn] >= 2;
}

void count_point() {
  points[turn]++;
  if (won_game()) {
    games[turn]++;
    points[0]=0;
    points[1]=0;
    if (games[turn] == 2)
      finished = true;
  }
}

void print_score() {
  if (finished) {
    printf("%d", games[0]);
    if (games[0] == 2)
      printf(" (winner)");
    printf(" - ");
    printf("%d", games[1]);
    if (games[1] == 2)
      printf(" (winner)");
    printf("\n");
  } else {
    printf("%d (%d", games[0], points[0]);
    if (turn == 0)
      printf("*");
    printf(") - ");
    printf("%d (%d", games[1], points[1]);
    if (turn == 1)
      printf("*");
    printf(")\n");
  }
}

int main() {
  char str[256];
  scanf(" %s", str);
  turn = 0;
  finished = false;
  points[0] = points[1] = 0;
  games[0] = games[1] = 0;
  for(int i=0; str[i]; ++i) {
    if (str[i]=='S') {
      count_point();
    } else if (str[i]=='R') {
      turn = 1-turn;
      count_point();
    } else {
      print_score();
    }
  }
  return 0;
}
