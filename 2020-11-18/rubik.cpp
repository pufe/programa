#include <cstdio>

struct cubelet_t {
  int vet[6];
  int& up() { return vet[0]; }
  int& down() { return vet[1]; }
  int& front() { return vet[2]; }
  int& back() { return vet[3]; }
  int& left() { return vet[4]; }
  int& right() {return vet[5]; }
  void rotate(int a, int b) {
    int tmp = vet[a];
    vet[a] = vet[b];
    vet[b] = vet[a^1];
    vet[a^1] = vet[b^1];
    vet[b^1] = tmp;
  }
  void rotate_up() { rotate(4, 2); }
  void rotate_down() { rotate(2, 4); }
  void rotate_left() { rotate(2, 0); }
  void rotate_right() { rotate(0, 2); }
  void rotate_front() { rotate(5, 0); }
  void rotate_back() { rotate(0, 5); }
};

struct cube_t {
  cubelet_t vet[3][3][3]; // d->u, l->r, b->f
  void rotate_up() {
    for(int i=0; i<3; ++i)
      for(int j=0; j<3; ++j)
	vet[2][i][j].rotate_up();
    cubelet_t tmp = vet[2][0][0];
    vet[2][0][0] = vet[2][0][2];
    vet[2][0][2] = vet[2][2][2];
    vet[2][2][2] = vet[2][2][0];
    vet[2][2][0] = tmp;
    // ...
  }
};
