#include <cstdio>

int main() {
  int p1, c1, p2, c2;
  int v1, v2;
  scanf(" %d %d %d %d", &p1, &c1, &p2, &c2);
  v1 = p1*c1;
  v2 = p2*c2;
  if (v1 > v2)
    printf("-1\n");
  else if (v1 < v2)
    printf("1\n");
  else
    printf("0\n");
  return 0;
}
