#include <cstdio>

int main() {
  int n;
  int previous = 0;
  int current;
  bool possible = true;
  scanf(" %d", &n);
  for(int i=0; i<n; ++i) {
    scanf(" %d", &current);
    if (current - previous > 8)
      possible = false;
    previous = current;
  }
  printf("%c\n", possible?'S':'N');
  return 0;
}
