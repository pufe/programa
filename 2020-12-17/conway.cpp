#include <cstdio>

bool current[22][22][15];
bool next_state[22][22][15];

int count_around(int x, int y, int z) {
  int total = 0;
  for(int i=-1; i<2; ++i)
    for(int j=-1; j<2; ++j)
      for(int k=-1; k<2; ++k)
	if (i!=0 || j!=0 || k!=0)
	  if (current[x+i][y+j][z+k])
	    ++total;
  return total;
}

void simulate() {
  for(int i=1; i<21; ++i)
    for(int j=1; j<21; ++j)
      for(int k=1; k<14; ++k) {
	int c = count_around(i, j, k);
	if (current[i][j][k] && (c==2 || c==3))
	  next_state[i][j][k]=true;
        else if (!current[i][j][k] && c==3)
          next_state[i][j][k]=true;
        else
          next_state[i][j][k]=false;
      }
  for(int i=1; i<21; ++i)
    for(int j=1; j<21; ++j)
      for(int k=1; k<14; ++k)
	current[i][j][k] = next_state[i][j][k];
}

int main() {
  for(int i=7; i<15; ++i)
    for(int j=7; j<15; ++j) {
      char c;
      scanf(" %c", &c);
      current[i][j][7] = (c=='#');
    }
  for(int i=0; i<6; ++i)
    simulate();
  int total = 0;
  for(int i=0; i<22; ++i)
    for(int j=0; j<22; ++j)
      for(int k=0; k<15; ++k)
	if (current[i][j][k])
	  ++total;
  printf("%d\n", total);
  return 0;
}
