#include <cstdio>

int main() {
  int limit, a, b;
  char op;
  scanf(" %d %d %c %d", &limit, &a, &op, &b);
  if (op == '+')
    a += b;
  else
    a *= b;
  if (a <= limit)
    printf("OK\n");
  else
    printf("OVERFLOW\n");
  return 0;
}
