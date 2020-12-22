#include <cstdio>

char keyboard[5][16] = { 
  "`1234567890-=",
  "QWERTYUIOP[]\\",
  "ASDFGHJKL;'",
  "ZXCVBNM,./",
  "  \n\n"
};
char mapping[256];

int main() {
  char c;
  for(int i=0; i<5; ++i) {
    for(int j=1; keyboard[i][j]!=0; ++j) {
      mapping[(int)keyboard[i][j]] = keyboard[i][j-1];
    }
  }
  while(true) {
    if (scanf("%c", &c)!=1)
      break;
    printf("%c", mapping[(int)c]);
  }
  return 0;
}			 
