#include <iostream>
#include <limits>
#include <vector>

using namespace std;

typedef long long int lld;

#define vi   vector<lld>
#define vii  vector< vi >
#define pii  pair<lld, int>

vii    tree;
int * euler;
int * level;
int * index;
lld * d;
int idx;

void dfs(int s, int depth) {
  index[s] = idx;
  euler[idx] = s;
  level[idx++] = depth;
  for (int i = tree[s].size() - 1; i >= 0; i--) {
    dfs(tree[s][i], depth + 1);
    euler[idx] = s;
    level[idx++] = depth;
  }
}

void new_tree(int n) {
  tree = vii(n);
  for (int i = 0; i < n; i++)
    tree[i] = vi();
  d = new lld[n]();
}

void init_lca(int n) {
  euler = new int[2 * n]();
  level = new int[2 * n]();
  index = new int[n]();
  idx   = 0;
  dfs(0, 0);
}

#define L    2 * n
#define R    2 * n + 1

void init(pii * a, int * input, int lo, int hi, int n) {
  if (lo >= hi) {
    a[n] = {input[lo], lo};
    return;
  }
  int mi = (lo + hi) / 2;
  init(a, input, lo, mi + 0, L);
  init(a, input, mi + 1, hi, R);
  a[n] = (a[L].first <= a[R].first ? a[L] : a[R]);
}

pii query(pii * a, int i, int j, int lo, int hi, int n) {
  if (i <= lo && j >= hi) 
    return a[n];
  if (i >  hi || j <  lo)
    return {numeric_limits<lld>::max(), -1};
  int mi = (lo + hi) / 2;
  pii l = query(a, i, j, lo, mi + 0, L);
  pii r = query(a, i, j, mi + 1, hi, R);
  return (l.first <= r.first ? l : r);
}

pii * init_rmq(int n) {
  pii * a = new pii[8 * n]();
  init(a, level, 0, 2 * n - 1, 1);
  return a;
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  lld a, b;
  while (cin >> n, n != 0) {
    new_tree(n);
    for (int i = 1; i < n; i++)
      cin >> a >> b, tree[a].push_back(i), d[i] += d[a] + b;
    init_lca(n);
    pii * tree = init_rmq(n);
    cin >> m;
    while (m--) {
      cin >> a >> b;
      int i = min(index[a], index[b]);
      int j = max(index[a], index[b]);
      cout << d[a] + d[b] - 2 * d[euler[query(tree, i, j, 0, 2 * n - 1, 1).second]];
      if (m > 0)
        cout << " ";
    }
    cout << "\n";
  }
  return 0;
}
