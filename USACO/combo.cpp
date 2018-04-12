/*
ID: wizard.1
LANG: C++11
TASK: combo
*/
#include <iostream>
#include <fstream>

using namespace std;

int N = 5; // Tolerance 
int M = 5; // Dial size

ifstream fi ("combo.in" );
ofstream fo ("combo.out");

typedef struct {
  int upper;
  int lower;
} dial;

int mod(int n, int m) {
  return n < 0 ? mod(n + m, m) : n % m;
}

dial create(int upper, int lower) {
  dial d;
  d.upper = upper;
  d.lower = lower;
  return d;
}

  bool contains(dial * d, int n) {
  for (int i = 0; i < N; i++)
    if (n == (d->upper + i) % M)
      return true;
  return false;
}

int count(int a, int b) {
  int i = 0;
  while (b != (a + i) % M) i++;
  return i + 1;
}

int range(dial * a, dial * b) {
  if (contains(a, b->upper) && contains(a, b->lower))
    return N;
  if (contains(a, b->upper))
    return count(b->upper, a->lower);
  if (contains(a, b->lower))
    return count(a->upper, b->lower);
  return 0;
}

int main() {
  int  aux;
  fi  >> M;
  dial a[3];
  dial b[3];
  for (int i = 0; i < 3; i++) {
    fi >> aux;
    a[i] = create(mod(aux - 2, M), mod(aux + 2, M));
  }
  for (int i = 0; i < 3; i++) {
    fi >> aux;
    b[i] = create(mod(aux - 2, M), mod(aux + 2, M));
  }
  if (M <= 5)
    fo << M * M * M << "\n";
  else {
    int total = 1;
    for (int i = 0; i < 3; i++)
      total *= range(&a[i], &b[i]);
    fo << 250 - total << "\n";
  }
  return 0;
}
