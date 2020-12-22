#include <cstdio>

bool reaches(int n, int v) {
  int pos = 0;
  while(v>0) {
    for(int i=0; i<v; ++i) {
      pos += v;
      if (pos==n)
	return true;
      if (pos>n)
	return false;
    }
    --v;
  }
  return false;
}

bool possible(int n, int v) {
  for(int i=1; i<=v; ++i)
    if (reaches(n, i))
      return true;
  return false;
}

int main() {
  while(true) {
    int n, v;
    scanf(" %d %d", &n, &v);
    if (n==0 && v==0)
      break;
    if (possible(n, v))
      printf("possivel\n");
    else
      printf("impossivel\n");
  }
  return 0;
}
