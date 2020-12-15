#include <cstdio>

struct instruction_t {
  char op;
  int arg;
  bool exec;
};

instruction_t code[1024];
char buffer[1024];

int main() {
  int n, x;
  while(scanf(" %s %d", buffer, &x)==2) {
    code[n].op = buffer[0];
    code[n].arg = x;
    code[n].exec = false;
    ++n;
  }
  int ip=0;
  int acc=0;
  while(!code[ip].exec) {
    code[ip].exec = true;
    switch(code[ip].op) {
    case 'a':
      acc += code[ip].arg;
      ++ip;
      break;
    case 'n':
      ++ip;
      break;
    case 'j':
      ip += code[ip].arg;
    }
  }
  printf("%d\n", acc);
  return 0;
}
