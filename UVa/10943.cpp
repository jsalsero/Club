#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000

int combina(int n, int r, int p) {
  int C[r + 1];
  fill(C, C + r + 1, 0);

  C[0] = 1;

  for (int i = 0; i <= n; ++i) {
    for (int j = min(i,r); j > 0; j--)
      C[j] = (C[j] + C[j - 1])%p;
  }
  return C[r];
}

int main() {
  int n,k;
  while (cin >> n >> k && n != 0 && k != 0) 
    cout << combina(n, k, MOD) << "\n";
  return 0;
}