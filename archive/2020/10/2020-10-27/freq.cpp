/*
 0  1  2  3  4  5
[0, 2, 1, 0, 1, 2]

6
1
1
2
5
5
4


*/


#include <cstdio>

const int max_x = 2000;
int arr[max_x+1] = {};

int main() {
  int n, x;
  scanf(" %d", &n);
  for(int i=0; i<n; ++i) {
    scanf(" %d", &x);
    arr[x]++;
  }
  for(int i=0; i<=max_x; ++i) {
    if (arr[i] > 0) {
      printf("%d aparece %d vez(es)\n", i, arr[i]);
    }
  }
  return 0;
}
