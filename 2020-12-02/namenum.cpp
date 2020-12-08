/*
  ID: pufepro1
  LANG: C++
  TASK: namenum
*/
#include <cstdio>
#include <cstdlib>
#include <map>
#include <string>
#include <vector>
using namespace std;

char convert_char(char c) {
  char alpha[] = "ABCDEFGHIJKLMNOPRSTUVWXY";
  for(int i=0; alpha[i]; ++i)
    if (alpha[i]==c)
      return i/3+'2';
  return c;
}

string convert(char name[30]) {
  char raw_number[30];
  int i;
  for(i=0; name[i]; ++i) {
    raw_number[i] = convert_char(name[i]);
  }
  raw_number[i]=0;
  return string(raw_number);
}

int main() {
  FILE *fin  = fopen("namenum.in", "r");
  FILE *fout = fopen("namenum.out", "w");
  FILE *dict = fopen("dict.txt", "r");
  map<string, vector<string> > m;
  char name[30];
  while(fscanf(dict, " %s", name)==1) {
    string number = convert(name);
    if (m.find(number)==m.end()) {
      m[number] = vector<string>{};
    }
    m[number].push_back(string(name));
  }
  char raw_number[30];
  fscanf(fin, " %s", raw_number);
  string number = string(raw_number);
  if (m.find(number)==m.end())
    fprintf(fout, "NONE\n");
  else {
    for(auto s : m[number]) {
      fprintf(fout, "%s\n", s.c_str());
    }
  }

  return 0;
}
