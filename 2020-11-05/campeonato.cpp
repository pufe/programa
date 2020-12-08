#include <cstdio>

char name[4][20] = {
  "oitavas",
  "quartas",
  "semifinal",
  "final"
};

int main() {
  int kung, lu;
  int player;
  int level=0;
  for(int i=0; i<16; ++i) {
    scanf(" %d", &player);
    if (player == 1)
      kung=i/2;
    else if (player == 9)
      lu=i/2;
  }
  while(kung!=lu) {
    ++level;
    kung /= 2;
    lu /= 2;
  }
  printf("%s\n", name[level]);
  return 0;
}
