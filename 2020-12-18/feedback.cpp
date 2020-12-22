#include <cstdio>
using namespace std;

int main() {
  char m[5][30] = {
    "",
    "Rolien",
    "Naej",
    "Elehcim",
    "Odranoel"
  };
  int n, x, t;
  for(scanf(" %d", &t); t>0; --t) {
    scanf(" %d", &n);
    for(int i=0; i<n; ++i) {
      scanf(" %d", &x);
      printf("%s\n", m[x]);
    }
  }
  return 0;
}
