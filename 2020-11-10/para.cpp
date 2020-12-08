#include <cstdio>

int perm[6][3] = {
  {0, 1, 2},
  {0, 2, 1},
  {1, 0, 2},
  {1, 2, 0},
  {2, 0, 1},
  {2, 1, 0}
};
		  
struct para_t {
  int dim[3];
  int orientacao;
  int pegar(int x) {
    int pos = perm[orientacao][x];
    return dim[pos];
  }
  void ler() {
    scanf(" %d %d %d", &dim[0], &dim[1], &dim[2]);
  }
};

bool caber(para_t p1, para_t p2) {
  return p1.pegar(0)<p2.pegar(0) && p1.pegar(1)<p2.pegar(1);
}

bool caber_rotacionado(para_t p1, para_t p2) {
  for(int i=0; i<6; ++i)
    for(int j=0; j<6; ++j) {
      p1.orientacao = i;
      p2.orientacao = j;
      if (caber(p1, p2))
	return true;
    }
  return false;
}

int main() {
  int n;
  para_t p1, p2;
  scanf(" %d", &n);
  for(int i=0; i<n; ++i) {
    p1.ler();
    p2.ler();
    int resp = 0;
    if (caber_rotacionado(p1, p2))
      ++resp;
    if (caber_rotacionado(p2, p1))
      resp+=2;
    printf("%d\n", resp);
  }
  return 0;
}
