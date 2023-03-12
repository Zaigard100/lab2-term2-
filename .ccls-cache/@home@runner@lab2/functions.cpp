#include <fstream>
#include <iostream>

using std::cout;

char task(int a[], int b[], int *c, unsigned n) {
  for (unsigned i = 0; i < n; i++) {
    if (i < 30) {
      if (a[i] < 0) {
        return 'a';
      }
    }
    if (i < 40) {
      if (b[i] < 0) {
        return 'b';
      }
    }
    if (c[i] < 0) {
      return 'c';
    }
  }
  return 'e';
}
