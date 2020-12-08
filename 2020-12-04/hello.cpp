#include <cstdio>

int main() {
  char buffer[1024];
  fgets(buffer, 1023, stdin);
  printf("Hello, World.\n");
  printf("%s", buffer);
  return 0;
}
