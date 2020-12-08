#include <cstdio>
#include <map>
#include <string>
#include <vector>
#include <regex>
using namespace std;

char buffer[2048];

bool read_line() {
  if (!fgets(buffer, 2047, stdin))
    return false;
  if (buffer[0] == '\n')
    return false;
  return true;
}

void add_fields(map<string, string>* p) {
  int n=0;
  char key[32], value[32];
  while(buffer[n]!='\n') {
    int x;
    sscanf(buffer+n, " %[^:]:%s%n", key, value, &x);
    n+=x;
    p->insert(make_pair(string(key),string(value)));
  }
}

bool read_passport(map<string, string>* p) {
  p->clear();
  int n_lines=0;
  while(read_line()) {
    ++n_lines;
    add_fields(p);
  }
  return n_lines > 0;
}

bool validate_year(string s, int lb, int ub) {
  int x;
  if (s.size()!=4)
    return false;
  if (sscanf(s.c_str(), "%d", &x)!=1)
    return false;
  return x>=lb && x <=ub;
}

bool validate_height(string s) {
  int x;
  char unit[32];
  if (sscanf(s.c_str(), "%d%s", &x, unit)!=2)
    return false;
  if (strcmp(unit, "cm")==0)
    return x>=150 && x <= 193;
  if (strcmp(unit, "in")==0)
    return x>=59 && x <= 76;
  return false;
}

bool validate_regex(string s, const char* pattern) {
  regex re(pattern, regex_constants::extended);
  if (regex_search(s, re))
    return true;
  return false;
}

bool is_valid(map<string, string>* p) {
  vector<string> req = {
    "byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid",
  };
  for(string key : req) {
    if (p->find(key)==p->end())
      return false;
  }
  if (!validate_year((*p)["byr"], 1920, 2002)) return false;
  if (!validate_year((*p)["iyr"], 2010, 2020)) return false;
  if (!validate_year((*p)["eyr"], 2020, 2030)) return false;
  if (!validate_height((*p)["hgt"])) return false;
  if (!validate_regex((*p)["hcl"], "^#[0-9a-f]{6}$")) return false;
  if (!validate_regex((*p)["ecl"], "^(amb|blu|brn|gry|grn|hzl|oth)$")) return false;
  if (!validate_regex((*p)["pid"], "^[0-9]{9}$")) return false;
  return true;
}

int main() {
  int valid = 0;
  map<string, string> p;
  while(read_passport(&p)) {
    if (is_valid(&p))
      ++valid;
  }
  printf("%d\n", valid);
  return 0;
}
