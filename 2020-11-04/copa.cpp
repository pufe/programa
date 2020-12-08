#include <cstdio>

char name[5][20] = {
  "..",
  "oitavas",
  "quartas",
  "semifinal",
  "final"
};

int main() {
  int a, b;
  int c=0;
  scanf(" %d %d", &a, &b);
  --a; --b;
  while(a!=b) {
    ++c;
    a/=2;
    b/=2;
  }
  printf("%s\n", name[c]);
  return 0;
}
