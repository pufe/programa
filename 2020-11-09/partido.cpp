#include <cstdio>
#include <cmath>
const int maxn = 32;
struct partido_t {
  int votos;
  int eleitos;
};
partido_t partido[maxn];

int melhor_partido(int n) {
  int melhor = 0;
  double avg = -1;
  for(int i=0; i<n; ++i) {
    if (partido[i].eleitos > 0) {
      double x = double(partido[i].votos);
      x /= double(partido[i].eleitos+1);
      if (x > avg) {
	melhor = i;
	avg = x;
      }
    }
  }
  return melhor;
}
int main() {
  int vagas, n;
  int total = 0;
  int qe;
  scanf(" %d %d", &vagas, &n);
  for(int i=0; i<n; ++i) {
    scanf(" %d", &partido[i].votos);
    total += partido[i].votos;
  }
  qe = int(floor(double(total)/double(vagas)+0.5));
  printf("%d %d\n", total, qe);
  for(int i=0; i<n; ++i) {
    partido[i].eleitos = partido[i].votos/qe;
    vagas -= partido[i].eleitos;
  }
  while(vagas>0) {
    int x = melhor_partido(n);
    partido[x].eleitos++;
    vagas--;
  }
  for(int i=0; i<n; ++i) {
    printf("Partido %d: %d\n", i+1, partido[i].eleitos);
  }
  return 0;
}
