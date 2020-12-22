#include <cstdio>

bool current[22][22][15][15];
bool next_state[22][22][15][15];

int count_around(int x, int y, int z, int w) {
  int total = 0;
  for(int i=-1; i<2; ++i)
    for(int j=-1; j<2; ++j)
      for(int k=-1; k<2; ++k)
	for(int l=-1; l<2; ++l)
	  if (i!=0 || j!=0 || k!=0 || l!=0)
	    if (current[x+i][y+j][z+k][w+l])
	      ++total;
  return total;
}

void simulate() {
  for(int i=1; i<21; ++i)
    for(int j=1; j<21; ++j)
      for(int k=1; k<14; ++k)
	for(int l=1; l<14; ++l) {
	  int c = count_around(i, j, k, l);
	  if (current[i][j][k][l] && (c==2 || c==3))
	    next_state[i][j][k][l]=true;
	  else if (!current[i][j][k][l] && c==3)
	    next_state[i][j][k][l]=true;
	  else
	    next_state[i][j][k][l]=false;
	}
  for(int i=1; i<21; ++i)
    for(int j=1; j<21; ++j)
      for(int k=1; k<14; ++k)
	for(int l=1; l<14; ++l)
	  current[i][j][k][l] = next_state[i][j][k][l];
}

int main() {
  for(int i=7; i<15; ++i)
    for(int j=7; j<15; ++j) {
      char c;
      scanf(" %c", &c);
      current[i][j][7][7] = (c=='#');
    }
  for(int i=0; i<6; ++i)
    simulate();
  int total = 0;
  for(int i=0; i<22; ++i)
    for(int j=0; j<22; ++j)
      for(int k=0; k<15; ++k)
	for(int l=0; l<15; ++l)
	  if (current[i][j][k][l])
	    ++total;
  printf("%d\n", total);
  return 0;
}
