#include <cstdio>
#include <cmath>
#define PI 3.14159265358979323846  /* pi */
const double radius = 6378;

struct point_t {
  double x, y, z;
  void read() {
    double lat, lon;
    scanf(" %lf %lf", &lat, &lon);
    lat *= PI / 180.0;
    lon *= PI / 180.0;
    x = radius * cos(lat) * cos(lon);
    y = radius * cos(lat) * sin(lon);
    z = radius * sin(lat);
  }
  double dot(point_t o) {
    return x*o.x + y*o.y + z*o.z;
  }
  point_t cross(point_t o) {
    return point_t {
      y*o.z-z*o.y,
      z*o.x-x*o.z,
      x*o.y-y*o.x
    };
  }
  double len() {
    return sqrt(dot(*this));
  }
};

double get_angle(point_t a, point_t b) {
  return fabs(atan2(a.cross(b).len(),a.dot(b)));
}

int main() {
  int n;
  point_t satellite;
  point_t city;
  double height;
  double limit;
  int test_case=1;
  char name[72];
  while(true) {
    scanf(" %d", &n);
    if (n==0)
      break;
    printf("Test case %d:\n", test_case++);
    satellite.read();
    scanf(" %lf", &height);
    limit = acos(radius / (radius+height));
    //    printf("limit = %lf\n", limit);
    for(int i=0; i<n; ++i) {
      scanf(" %s", name);
      city.read();
      double theta = get_angle(city, satellite);
      //printf("%s -> %lf\n", name, theta);
      if (theta <= limit)
	printf("%s\n", name);
    }
    printf("\n");
  }
  return 0;
}
