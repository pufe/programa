#include <cstdio>
#include <cstring>
#include <cctype>
#include <map>
#include <algorithm>
using namespace std;

struct team_t {
  int goals;
  char name[10];
};
char name[3][10] = {"red", "blue", "green"};

bool operator<(const team_t a, const team_t b) {
  return a.goals > b.goals;
}

int main() {
  int tests;
  team_t team[4];
  map<char, int> m;
  
  for(scanf(" %d", &tests); tests>0; --tests) {
    for(int i=0; i<3; ++i) {
      team[i].goals = 0;
      strcpy(team[i].name, name[i]);
      m[toupper(name[i][0])] = i;
    }
    int n;
    scanf(" %d", &n);
    for(int i=0; i<n; ++i) {
      char a, b;
      scanf(" %c %c", &a, &b);
      int ia = m[a];
      int ib = m[b];
      team[ia].goals += (ib-ia+3)%3;
    }
    sort(team, team+3);
    if (team[0].goals == team[2].goals)
      printf("trempate\n");
    else if (team[0].goals == team[1].goals)
      printf("empate\n");
    else
      printf("%s\n", team[0].name);
  }
  return 0;
}
