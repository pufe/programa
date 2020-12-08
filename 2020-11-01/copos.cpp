#include <cstdio>

char mtx[3][4] = {
  "BAC",
  "ACB",
  "CBA"
};

int main() {
  int n;
  char c;
  int x;
  scanf(" %d %c", &n, &c);
  for(int i=0; i<n; ++i) {
    scanf(" %d", &x);
    --x;
    c = mtx[c-'A'][x];
  }
  printf("%c\n", c);
  return 0;
}
