#include <cstdio>
#include <cstring>

char lang[120][32];

bool all_equal(int n) {
  for(int i=1; i<n; ++i) {
    if (strcmp(lang[i-1], lang[i])!=0)
      return false;
  }
  return true;
}

int main() {
  int t, n;
  for(scanf(" %d", &t); t>0; --t) {
    scanf(" %d", &n);
    for(int i=0; i<n; ++i) {
      scanf(" %s", lang[i]);
    }
    if (all_equal(n)) {
      printf("%s\n", lang[0]);
    }
    else {
      printf("ingles\n");
    }
  }
  return 0;
}
