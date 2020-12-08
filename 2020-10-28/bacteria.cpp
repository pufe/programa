#include <cstdio>
#include <cstring>

int main() {
  char bacteria[200], seq[200];
  while(true) {
    if (scanf(" %s %s", bacteria, seq)!=2)
      break;
    if (strstr(bacteria, seq))
      printf("Resistente\n");
    else
      printf("Nao resistente\n");
  }
  return 0;
}
