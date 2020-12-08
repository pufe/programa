#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
  int monica;
  int filhos[4];
  scanf(" %d %d %d", &monica, &filhos[0], &filhos[1]);
  filhos[2] = monica - filhos[0] - filhos[1];
  sort(filhos, filhos+3);
  printf("%d\n", filhos[2]);
  return 0;
}
