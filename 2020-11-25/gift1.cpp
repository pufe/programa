/*
  ID: pufepro1
  LANG: C++
  TASK: gift1
*/
#include <cstdio>
#include <string>
#include <map>
#include <vector>
using namespace std;

struct person_t {
  string name;
  int balance;
};

int main() {
  FILE *fin  = fopen ("gift1.in", "r");
  FILE *fout = fopen ("gift1.out", "w");

  vector<person_t> person;
  int n;
  fscanf(fin, " %d", &n);
  person.resize(n);
  map<string, int> m;
  char buffer[32];

  for(int i=0; i<n; ++i) {
    fscanf(fin, " %s", buffer);
    person[i].name = string(buffer);
    m[person[i].name] = i;
  }

  for(int i=0; i<n; ++i) {
    fscanf(fin, " %s", buffer);
    string str = string(buffer);
    int giver = m[str];
    int amount, q;
    fscanf(fin, " %d %d", &amount, &q);
    if (q > 0)
      amount /= q;
    for(int j=0; j<q; ++j) {
      fscanf(fin, " %s", buffer);
      str = string(buffer);
      int receiver = m[str];
      person[giver].balance -= amount;
      person[receiver].balance += amount;
    }
  }
  
  for(int i=0; i<n; ++i) {
    fprintf(fout, "%s %d\n", 
	    person[i].name.c_str(),
	    person[i].balance);
  }
  return 0;
}
