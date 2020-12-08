/*
  ID: pufepro1
  LANG: C++
  TASK: friday
*/
#include <cstdio>
#include <cstdlib>

int week[7]; // sat=0, sun=1, mon=2 ... fri=6

int month[12] = {31, 28, 31, 30, 31, 30,
		 31, 31, 30, 31, 30, 31};
int regular_year[7];
int leap_year[7];

bool is_leap(int year) {
  if (year % 400 == 0)
    return true;
  if (year % 100 == 0)
    return false;
  if (year % 4 == 0)
    return true;
  return false;
}

void calculate_regular_year() {
  int dow = 0;
  for(int i=0; i<12; ++i) {
    regular_year[(dow+12)%7]++;
    dow += month[i];
  }
}
void calculate_leap_year() {
  int dow = 0;
  for(int i=0; i<12; ++i) {
    leap_year[(dow+12)%7]++;
    if (i==1)
      ++dow;
    dow += month[i];
  }
}

int main () {
  FILE *fin  = fopen ("friday.in", "r");
  FILE *fout = fopen ("friday.out", "w");

  int year = 1900;
  int dow = 2;
  int n;
  fscanf(fin, " %d", &n);

  calculate_regular_year();
  calculate_leap_year();
  
  for(int i=0; i<n; ++i) {
    if (is_leap(year)) {
      for(int j=0; j<7; ++j)
	week[(j+dow)%7]+=leap_year[j];
      dow += 366;
      dow %= 7;
    } else {
      for(int j=0; j<7; ++j)
	week[(j+dow)%7]+=regular_year[j];
      dow += 365;
      dow %= 7;
    }
    // printf(" dow = %d\n", dow);
    // for(int i=0; i<7; ++i) {
    //   printf(" %d", week[i]);
    // }
    // printf("\n");
    ++year;
  }
  for(int i=0; i<7; ++i) {
    if (i>0)
      fprintf(fout, " ");
    fprintf(fout, "%d", week[i]);
  }
  fprintf(fout, "\n");
  return 0;
}
