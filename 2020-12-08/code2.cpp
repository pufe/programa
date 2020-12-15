#include <cstdio>
#include <utility>
using namespace std;

struct instruction_t {
  char op;
  int arg;
  bool exec;
};

instruction_t code[1024];
char buffer[1024];

pair<bool, int> simulate(int n) {
  int ip=0;
  int acc=0;

  for(int i=0; i<n; ++i)
    code[i].exec = false;

  while(ip>=0 && ip<n && !code[ip].exec) {
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

  return make_pair(ip==n, acc);
}

int main() {
  int n, x;
  while(scanf(" %s %d", buffer, &x)==2) {
    code[n].op = buffer[0];
    code[n].arg = x;
    code[n].exec = false;
    ++n;
  }
  for(int i=0; i<n; ++i) {
    if (code[i].op == 'j') {
      code[i].op = 'n';
      auto it = simulate(n);
      code[i].op = 'j';
      if (it.first)
	printf("(%d) -> %d\n", i, it.second);
    }
    if (code[i].op == 'n') {
      code[i].op = 'j';
      auto it = simulate(n);
      code[i].op = 'n';
      if (it.first)
	printf("(%d) -> %d\n", i, it.second);
    }
  }

  return 0;
}
