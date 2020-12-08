/*
  ID: pufepro1
  LANG: C++
  TASK: dualpal
*/
#include <cstdio>
#include <cstdlib>

bool is_palindrome(int x, int base) {
  int digits[50];
  int n=0;
  while(x>0) {
    digits[n++]=x%base;
    x/=base;
  }
  for(int i=0; i<n; ++i) {
    if (digits[i]!=digits[n-1-i])
      return false;
  }
  return true;
}

bool is_dual_palindrome(int x) {
  int c=0;
  for(int i=2; i<=10; ++i)
    if(is_palindrome(x, i))
      ++c;
  return c>=2;
}

int main() {
  FILE *fin  = fopen("dualpal.in", "r");
  FILE *fout = fopen("dualpal.out", "w");
  int n, s;
  fscanf(fin, " %d %d", &n, &s);
  while(n>0) {
    ++s;
    if (is_dual_palindrome(s)) {
      fprintf(fout, "%d\n", s);
      --n;
    }
  }
  return 0;
}
