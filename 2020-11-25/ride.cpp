/*
  ID: pufepro1
  LANG: C++
  TASK: ride
*/
#include <cstdio>
#include <cstdlib>

int convert(char *str) {
  int total=1;
  for(int i=0; str[i]; ++i)
    total = (total*(str[i]-'A'+1))%47;
  return total;
}

int main() {
  FILE *fin  = fopen ("ride.in", "r");
  FILE *fout = fopen ("ride.out", "w");
  char str1[10], str2[10];
  fscanf(fin, " %s %s", str1, str2);
  if (convert(str1) == convert(str2))
    fprintf(fout, "GO\n");
  else
    fprintf(fout, "STAY\n");
  return 0;
}
