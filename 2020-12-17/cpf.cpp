#include <cstdio>
#include <cstring>
#include <cctype>

char cpf[32];

int main() {
  while(scanf(" %s", cpf)==1) {
    int b1=0;
    int b2=0;
    int c=1;
    for(int i=0; c<10; ++i) {
      if (isdigit(cpf[i])) {
	b1 = (b1 + (cpf[i]-'0')*c)%11;
	b2 = (b2 + (cpf[i]-'0')*(10-c))%11;
	++c;
      }
    }
    if (b1==10)
      b1=0;
    if (b2==10)
      b2=0;
    int len = strlen(cpf);
    if (cpf[len-1]==b2+'0' && cpf[len-2]==b1+'0')
      printf("CPF valido\n");
    else
      printf("CPF invalido\n");
  }
  return 0;
}
