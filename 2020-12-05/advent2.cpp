#include <cstdio>
#include <set>
using namespace std;

int convert(char str[]) {
  int t=0;
  for(int i=0; str[i]; ++i) {
    t *= 2;
    if (str[i]=='B' || str[i]=='R')
      ++t;
  }
  return t;
}

int main() {
  int greatest=-1;
  char bp[30];
  set<int> s;
  while(scanf(" %s", bp)==1) {
    int x = convert(bp);
    s.insert(x);
    if (x > greatest)
      greatest = x;
  }
  for(int i=0; i<greatest; ++i) {
    if (s.count(i-1)==1 && s.count(i)==0 && s.count(i+1))
      printf("%d\n", i);
  }
  return 0;
}
