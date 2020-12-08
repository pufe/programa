#include <cstdio>

int main() {
  int n;
  double price;
  int grams;
  double best;
  scanf(" %d", &n);
  for(int i=0; i<n; ++i) {
    scanf(" %lf %d", &price, &grams);
    price = price*1000/grams;
    if (i==0 || price < best)
      best = price;
  }
  printf("%.2lf\n", best);
  return 0;
}
