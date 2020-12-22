#include <cstdio>

int main() {
  char str[50];
  int v;
  while(true) {
    scanf(" %s", str);
    if (str[0] == '-')
      break;
    else if (str[1] == 'x') {
      // hexa
      sscanf(str+2, "%x", &v);
      printf("%d\n", v);
    }
    else {
      // dec
      sscanf(str, "%d", &v);
      printf("0x%X\n", v);
    }
  }
  return 0;
}
