#include <cstdio>

int board[9][9];
int row[9][9];
int col[9][9];
int quad[3][3][9];

void clear() {
  for(int i=0; i<9; ++i)
    for(int j=0; j<9; ++j) {
      row[i][j] = 0;
      col[i][j] = 0;
    }
  for(int i=0; i<3; ++i)
    for(int j=0; j<3; ++j)
      for(int k=0; k<9; ++k)
	quad[i][j][k]=0;
}

void read_input() {
  for(int i=0; i<9; ++i)
    for(int j=0; j<9; ++j) {
      scanf(" %d", &board[i][j]);
      --board[i][j];
    }
}

bool is_valid() {
  for(int i=0; i<9; ++i)
    for(int j=0; j<9; ++j) {
      // estamos olhando para board[i][j]
      int x = board[i][j];
      if (row[i][x] > 0)
	return false;
      row[i][x]++;
      if (col[j][x] > 0)
	return false;
      col[j][x]++;
      if (quad[i/3][j/3][x] > 0)
	return false;
      quad[i/3][j/3][x]++;
    }
  return true;
}

int main() {
  int n;
  scanf(" %d", &n);
  for(int i=1; i<=n; ++i) {
    clear();
    read_input();
    printf("Instancia %d\n", i);
    if (is_valid())
      printf("SIM\n\n");
    else
      printf("NAO\n\n");
  }
  return 0;
}
