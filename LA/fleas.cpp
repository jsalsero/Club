#include <algorithm>
#include <iostream>
#include <vector>
#include <limits>
#include <set>

using namespace std;

typedef struct { vector< set<int> >vs; } graph;

graph new_graph(int n) {
  graph g;
  g.vs = vector< set<int> >(n);
  for (int i = 0; i < n; i++)
    g.vs[i] = set<int>();
  return g;
}

int *  euler; // 2 * n 
int *  level; // 2 * n
int *  index;
int * pathTo; // ESTO NO ES PARTE DEL LCA
int idx;

void dfs(graph * g, int s, int depth) {
  index[s] = idx;
  euler[idx] = s;
  level[idx++] = depth;
  for (auto v: g->vs[s]) {
    dfs(g, v, depth + 1);
    pathTo[v]  = s;       // ESTO NO ES PARTE DEL LCA
    euler[idx] = s;
    level[idx++] = depth;
  }
}

void createLCA(graph * tree, int n) {
  euler  = new int[2 * n]();
  level  = new int[2 * n]();
  index  = new int[n]();
  pathTo = new int[n]();
  idx   = 0;
  dfs(tree, 0, 0);
}

/** SEGMENT TREE **/
#define L    2 * n
#define R    2 * n + 1
#define pii  pair<int, int>
#define MAX  numeric_limits<int>::max()

void init(pii * a, int * input, int lo, int hi, int n) {
  if (lo >= hi) { a[n] = {input[lo], lo}; return;}
  int mi = (lo + hi) / 2;
  init(a, input, lo, mi + 0, L);
  init(a, input, mi + 1, hi, R);
  a[n] = (a[L].first < a[R].first ? a[L] : a[R]);
}

pii query(pii * a, int * input,int i, int j, int lo, int hi, int n) {
  if (i <= lo && j >= hi) return a[n];
  if (i >  hi || j <  lo) return a[0];
  int mi = (lo + hi) / 2;
  pii l = query(a, input, i, j, lo, mi + 0, L);
  pii r = query(a, input, i, j, mi + 1, hi, R);
  return (l.first < r.first ? l : r);
}

pii * createRMQ(int * input, int n) {
  pii * a = new  pii[4 * n]();
  init(a, input, 0, n - 1, 1);
  a[0] = {MAX, -1};
  return a;
} 


int main() {
  int n, m, u , v, x;
  while (cin >> n, n != 0) {
  	graph tree = new_graph(n);
    for (int i = 1; i < n; i++) 
      cin >> u >> v, tree.vs[u - 1].insert(v - 1);
    createLCA(&tree, n);
    pii * a = createRMQ(level, 2 * n);
    cin >> m;
    while (m--) {
      cin >> u >> v;
      int i = min(index[u - 1], index[v - 1]);
      int j = max(index[u - 1], index[v - 1]);
      int lca = euler[query(a, level, i, j, 0, 2 * n - 1, 1).second];
      x = u - 1;
      x = v - 1;
    }
  }
}




