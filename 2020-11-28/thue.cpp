#include <cstdio>

const int maxn = 10100;
char str[maxn];
char alphabet[4] = "012";

bool valid(int x) {
  for(int i=1; i<=(x+1)/2; ++i) {
    bool collide = true;
    for(int j=0; j<i; ++j) {
      if (str[x-j]!=str[x-i-j]) {
	collide = false;
	break;
      }
    }
    if (collide)
      return false;
  }
  return true;
}

bool generate(int x) {
  if (x > 5000)
    return true;
  for(int i=0; i<3; ++i) {
    str[x] = alphabet[i];
    if (valid(x)) {
      if (generate(x+1))
	return true;
    }
  }
  return false;
}

int main() {
  int n;
  if (!generate(0)) {
    printf("deu ruim\n");
  }
  while(true) {
    scanf(" %d", &n);
    if (n==0)
      break;
    for(int i=0; i<n; ++i) {
      printf("%c", str[i]);
    }
    printf("\n");
  }
  return 0;
}
