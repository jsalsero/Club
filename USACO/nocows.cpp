/*
ID: wizard.1
LANG: C++
TASK: nocows
*/

#include <bits/stdc++.h>
using namespace std;
#define MOD 9901

int N,K;
int memo[207][107];

long long int dp(int nodos, int h) {
  if (memo[nodos][h] != -1)
    return memo[nodos][h];

  if (nodos <= 0 || h > K)
    return 0;
  if (nodos == 1 && h <= K)
    return 1;

  long long int izq, der, res = 0;
  for (int i = 0; i < nodos - 1; ++i) {    
    izq = dp(i, h + 1);
    der = dp(nodos - i - 1, h + 1);
    res = (res + izq%MOD*der%MOD )%MOD;
  }
  return memo[nodos][h] = res;
}

int main() {
  ifstream fin ("nocows.in");
  ofstream fout ("nocows.out");

  fin >> N >> K;
  for (int i = 0; i < 200; ++i)
    for (int j = 0; j < 100; j++)
      memo[i][j] = -1;
  int a = dp(N, 1);
  K--;
  for (int i = 0; i < 200; ++i)
    for (int j = 0; j < 100; j++)
      memo[i][j] = -1;
  int b = dp(N, 1);
  if (a < b)
    fout << a - b + MOD << "\n";
  else
    fout << a - b << "\n";
  return 0;
}
