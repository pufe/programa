#include <cstdio>
#include <map>
#include <vector>
using namespace std;

int reverse(int x) {
  int r=0;
  for(int i=0; i<10; ++i) {
    r*=2;
    r+=x&1;
    x/=2;
  }
  return r;
}

struct tile_t {
  char mtx[11][11];
  int border[4];
  int id;
  void calculate_borders() {
    border[0]=0;
    for(int i=0; i<10; ++i) {
      border[0]*=2;
      border[0]+=(mtx[0][i]=='#');
      border[2]*=2;
      border[2]+=(mtx[9][9-i]=='#');
      border[1]*=2;
      border[1]+=(mtx[9-i][0]=='#');
      border[3]*=2;
      border[3]+=(mtx[i][9]=='#');
    }
  }
  void rotate() {
    char tmp[11][11];
    for(int i=0; i<10; ++i)
      for(int j=0; j<10; ++j)
	tmp[j][9-i] = mtx[i][j];
    for(int i=0; i<10; ++i)
      for(int j=0; j<10; ++j)
	mtx[i][j] = tmp[i][j];
    int aux=border[0];
    for(int i=0; i<3; ++i)
      border[i]=border[i+1];
    border[3]=aux;
  }
  void rotate_times(int x) {
    for(int i=0; i<x; ++i)
      rotate();
  }
  void flip_v() {
    char tmp[11][11];
    for(int i=0; i<10; ++i)
      for(int j=0; j<10; ++j)
	tmp[i][9-j] = mtx[i][j];
    for(int i=0; i<10; ++i)
      for(int j=0; j<10; ++j)
	mtx[i][j] = tmp[i][j];
    border[0]=reverse(border[0]);
    border[2]=reverse(border[2]);
    int aux = border[1];
    border[1] = reverse(border[3]);
    border[3] = reverse(aux);
  }
  void flip_h() {
    char tmp[11][11];
    for(int i=0; i<10; ++i)
      for(int j=0; j<10; ++j)
	tmp[9-i][j] = mtx[i][j];
    for(int i=0; i<10; ++i)
      for(int j=0; j<10; ++j)
	mtx[i][j] = tmp[i][j];
    border[1]=reverse(border[1]);
    border[3]=reverse(border[3]);
    int aux = border[0];
    border[0] = reverse(border[2]);
    border[2] = reverse(aux);
  }
};

tile_t tile[150];
int jigsaw[12][12];
char image[100][100];
char aux_image[100][100];
map<int, vector<tuple<int, int, bool> > > b;
char monster[3][21] = {
  "                  # ",
  "#    ##    ##    ###",
  " #  #  #  #  #  #   "
};

bool is_dragon(int x, int y) {
  for(int i=0; i<3; ++i)
    for(int j=0; j<20; ++j)
      if (monster[i][j]=='#' && image[x+i][y+j]=='.')
	return false;
  return true;
}
void replace_dragon(int x, int y) {
  for(int i=0; i<3; ++i)
    for(int j=0; j<20; ++j)
      if (monster[i][j]=='#')
	image[x+i][y+j]='O';
}
bool replace_dragons() {
  bool r = false;
  for(int i=0; i+3<=96; ++i)
    for(int j=0; j+20<=96; ++j)
      if (is_dragon(i, j)) {
	r = true;
	replace_dragon(i, j);
      }
  return r;
}
int count_hash() {
  int c=0;
  for(int i=0; i<96; ++i)
    for(int j=0; j<96; ++j)
      if (image[i][j]=='#')
	++c;
  return c;
}
void debug() {
  for(int i=0; i<12; ++i) {
    printf("+");
    for(int j=0; j<12; ++j) {
      printf("----------------+");
    }
    printf("\n|");
    for(int j=0; j<12; ++j) {
      printf("      %04d      |", tile[jigsaw[i][j]].border[0]);
    }
    printf("\n|");
    for(int j=0; j<12; ++j) {
      int c = jigsaw[i][j];
      printf(" %04d-%04d-%04d |", 
	     tile[c].border[1], tile[c].id, tile[c].border[3]);
    }
    printf("\n|");
    for(int j=0; j<12; ++j) {
      printf("      %04d      |", tile[jigsaw[i][j]].border[2]);
    }
    printf("\n");
  }
  printf("+");
  for(int j=0; j<12; ++j) {
    printf("----------------+");
  }
  printf("\n");
}


void fill_jigsaw(int corner) {
  jigsaw[0][0]=corner;
  while(b[tile[corner].border[0]].size()==2
	|| b[tile[corner].border[1]].size()==2) {
    tile[corner].rotate();
  }
  for(int i=1; i<12; ++i) {
    int current = jigsaw[0][i-1];
    bool matched = false;
    for(auto x : b[tile[current].border[3]]) {
      int p = get<0>(x);
      if (p != current) {
	int r = get<1>(x);
	bool f = get<2>(x);
	tile[p].rotate_times((r+3)%4);
	if (!f)
	  tile[p].flip_h();
	if (tile[current].border[3]!=
	    reverse(tile[p].border[1])) {
	  printf("deu ruim %d %d\n", 0, i);
	  debug();
	  throw "deu ruim";
	}
	jigsaw[0][i]=p;
	matched = true;
	break;
      }
    }
    if (!matched) {
      printf("wat %d %d\n", 0, i);
      debug();
      throw "wat";
    }
  }
  for(int j=0; j<12; ++j) {
    for(int i=1; i<12; ++i) {
      int current = jigsaw[i-1][j];
      bool matched = false;
      for(auto x : b[tile[current].border[2]]) {
	int p = get<0>(x);
	if (p != current) {
	  int r = get<1>(x);
	  bool f = get<2>(x);
	  tile[p].rotate_times(r);
	  if (!f)
	    tile[p].flip_v();
	  if (tile[current].border[2]
	      !=reverse(tile[p].border[0])) {
	    printf("deu ruim %d %d\n", i, j);
	    debug();
	    throw "deu ruim";
	  }
	  jigsaw[i][j]=p;
	  matched = true;
	  break;
	}
      }
      if (!matched) {
	printf("wat %d %d\n", i, j);
	debug();
	throw "wat";
      }
    }
  }
}
void copy_mtx(int x, int y) {
  int p = jigsaw[x][y];
  for(int i=0; i<8; ++i)
    for(int j=0; j<8; ++j)
      image[8*x+i][8*y+j]=tile[p].mtx[1+i][1+j];
}
void rotate_image() {
  for(int i=0; i<96; ++i)
    for(int j=0; j<96; ++j)
      aux_image[95-j][i] = image[i][j];
  for(int i=0; i<96; ++i)
    for(int j=0; j<96; ++j)
      image[i][j] = aux_image[i][j];
}
void flip_image() {
  for(int i=0; i<96; ++i)
    for(int j=0; j<96; ++j)
      aux_image[i][95-j] = image[i][j];
  for(int i=0; i<96; ++i)
    for(int j=0; j<96; ++j)
      image[i][j] = aux_image[i][j];
}

int main() {
  tile[0].id = 0;
  for(int i=0; i<4; ++i)
    tile[0].border[i]=0;
  int n=1;
  while(true) {
    if (scanf(" Tile %d:", &tile[n].id)!=1)
      break;
    for(int i=0; i<10; ++i)
      scanf(" %s", tile[n].mtx[i]);
    tile[n].calculate_borders();
    for(int i=0; i<4; ++i) {
      int x = tile[n].border[i];
      b[x].push_back(make_tuple(n, i, false));
      b[reverse(x)].push_back(make_tuple(n, i, true));
    }
    ++n;
  }
  for(int i=1; i<n; ++i) {
    int edges=0;
    for(int j=0; j<4; ++j)
      if (b[tile[i].border[j]].size()==1)
	++edges;
    if (edges == 2) {
      fill_jigsaw(i);
      break;
    }
  }
  for(int i=0; i<12; ++i)
    for(int j=0; j<12; ++j)
      copy_mtx(i, j);
  
  for(int i=0; i<4; ++i) {
    for(int j=0; j<2; ++j) {
      if (replace_dragons()) {	
	goto finish;
      }
      flip_image();
    }
    rotate_image();
  }
 finish:
  for(int i=0; i<96; ++i) {
    for(int j=0; j<96; ++j)
      printf("%c", image[i][j]);
    printf("\n");
  }
  printf("\n");

  printf("%d\n", count_hash());

  return 0;
}
