#include <cstdio>
#include <map>
using namespace std;

int starting_numbers[6] = {1,20,11,6,12,0};

int main() {
  map<int, int> m;
  int turn = 1;
  int next_number=0;
  for(int i=0; i<6; ++i) {
    //printf("%d -> %d\n", turn, starting_numbers[i]);
    if (m.find(starting_numbers[i])==m.end())
      next_number = 0;
    else
      next_number = turn - m[starting_numbers[i]];
    m[starting_numbers[i]] = turn;
    ++turn;
  }
  while(turn <= 30000000) {
    if (turn == 30000000) {
      printf("%d -> %d\n", turn, next_number);
      break;
    }
    int tmp;
    if (m.find(next_number)==m.end())
      tmp = 0;
    else
      tmp = turn - m[next_number];
    m[next_number] = turn;
    next_number = tmp;
    ++turn;
  }
  return 0;
}
