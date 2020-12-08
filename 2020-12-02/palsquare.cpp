/*
  ID: pufepro1
  LANG: C++
  TASK: palsquare
*/
#include <cstdio>
#include <cstdlib>

FILE *fin;
FILE *fout;

bool is_palindrome(int x, int base) {
  int digits[30];
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

void print_digit(int x) {
  fprintf(fout, "%c", "0123456789ABCDEFGHIJKL"[x]);
}

void print_base(int x, int base) {
  if (x<base)
    print_digit(x);
  else {
    print_base(x/base, base);
    print_digit(x%base);
  }
}

int main() {
  fin  = fopen("palsquare.in", "r");
  fout = fopen("palsquare.out", "w");

  int base;
  fscanf(fin, " %d", &base);
  for(int i=1; i<=300; ++i) {
    if (is_palindrome(i*i, base)) {
      print_base(i, base);
      fprintf(fout, " ");
      print_base(i*i, base);
      fprintf(fout, "\n");
    }
  }
  return 0;
}
