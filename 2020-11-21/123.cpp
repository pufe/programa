#include <cstdio>
#include <cstring>

bool matches(char a[], char b[]) {
  int errors = 0;
  for(int i=0; b[i]; ++i) {
    if (!a[i])
      return false;
    if (a[i] != b[i])
      ++errors;
  }
  return errors < 2;
}

int main() {
  char numbers[4][7] = {"zero", "one", "two", "three"};
  char input[7];
  int n;
  scanf(" %d", &n);
  for(int i=0; i<n; ++i) {
    scanf(" %s", input);
    for(int j=1; j<=3; ++j)
      if (matches(input, numbers[j]))
	printf("%d\n", j);
  }
  return 0;
}
