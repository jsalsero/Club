#include <bits/stdc++.h>
using namespace std;

const double ERROR = 1e-9;

struct fuente {
  double ini;
  double fin;
};

bool cmp(const fuente &a, const fuente &b) {
  if ( (a.ini - b.ini) < ERROR) 
    return true;
  return false;
}

void debug(vector<fuente> V) {
  int m = V.size();
  for (int i = 0; i < m; ++i){
    cout << V[i].ini << "    " << V[i].fin << endl;
  }
}

int main() {
  double n,l,w;
  double p, r;  
  int i;

  while (cin >> n >> l >> w) {    
    vector<fuente> A;

    for (int i = 0; i < n; ++i) {
      cin >> p >> r;
      if (r < w/2.0) continue;
      double a = r*r - (w*w)/4.0;
      if ( a < 0 ) continue;      
      a = sqrt(a);

      fuente f;
      f.ini = p - a;
      f.fin = p + a;
      A.push_back(f);
    }
    
    sort(A.begin(), A.end(), cmp);
    //cout << endl << endl; debug(A);
    int tam = A.size();
    int res = 0;
    
    double ultimo = 0.0;
    double mejor = 0.0;
    bool flag = false;
    for (int i = 0; i < tam; i++) {
      if (ultimo >= l)
        break;
      while (i < tam && A[i].ini <= ultimo) {
        if (mejor < A[i].fin) {
          mejor = A[i].fin;
          flag = true;
        }
        i++;
      }
      if (flag) {
        res++;
        i--;
        ultimo = mejor;
        flag = false;
      }
    }

    if (ultimo < l)
      cout << "-1\n";
    else
      cout << res << "\n";  
  }
  return 0;
}