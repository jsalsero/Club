#include <bits/stdc++.h>
using namespace std;

#define MAX 10005
int padre[ MAX ];
int rango[ MAX ];
int P[ MAX ];

void make (int n) {
  for (int i = 0; i < n; i++) {
    padre[ i ] = i;
    rango[ i ] = 0;
  }
}

int find (int x) {
  if (x == padre[ x ]) {
    return x;
  }
  return padre[x] = find( padre[x] );
}

void unionRank(int x, int y) {
  int xRoot = find(x);
  int yRoot = find(y);
  if (rango[xRoot] > rango[yRoot])
    padre[yRoot] = xRoot;
  else {
    padre[xRoot] = yRoot;
    if (rango[xRoot] == rango[yRoot])
      rango[yRoot]++;
  }
}

int root[ MAX ];
int numComponentes;
int getNumberCC(int n) {
  numComponentes = 0;
  for (int i = 0; i < n; ++i) {
    if (padre[i] == i)
      root[numComponentes++] = i;
  }
  return numComponentes;
}

int numVertices[ MAX ];
void getNumberNodes(int n) {
  fill(numVertices, numVertices + MAX, 0);
  for (int i = 0; i < n; ++i) {
    numVertices[ find(i) ] += P[ i ];
  }
}

int main() {
  int casos, personas, amigos, x, y;
  bool flag;

  cin >> casos;
  for (int i = 0; i < casos; ++i) {
    cin >> personas >> amigos;
    make(personas);

    for (int i = 0; i < personas; ++i)
      cin >> P[i];
    
    for (int i = 0; i < amigos; ++i) {
      cin >> x >> y;
      unionRank(x,y);
    }

    int cc = getNumberCC(personas);
    getNumberNodes(personas);

    flag = true;
    for (int i = 0; i < cc && flag; ++i) {
      if (numVertices[ root[i] ] != 0)
        flag = false;
    }
    if (flag)
      cout << "POSSIBLE\n";
    else
      cout << "IMPOSSIBLE\n";
  }
  return 0;
}

/*
2
5 3
100
-75
-25
-42
42
0 1
1 2
3 4
4 2
15
20
-10
-25
0 2
1 3


*/
