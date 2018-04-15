#include <bits/stdc++.h>
using namespace std;
#define lld long long int
#define MAX 1000007

int blanco[MAX];
int negro[MAX];

int main() {
  lld A,B,dinero,r,res;
  int white, black;  
  string cad,cad2;

  A = B = 0;
  cad = "";

  while(cin >> A >> B >> cad) {
    int tam = cad.size();
    cad2 = "";
    res = numeric_limits<int>::max();;
    
    for (int i = 0; i < tam; ++i)
      (cad[i] == 'B') ? cad2 = 'B' + cad2 : cad2 = cad2 + 'W';
    
    fill(blanco, blanco + MAX, 0);
    fill(negro, negro + MAX, 0);
    white = black = 0;

    for (int i = 0; i < tam; ++i) {
      if (cad[i] != cad2[i] && cad[i] == 'W')
        blanco[white++] = i;
      if (cad[tam - i - 1] != cad2[tam - i - 1] && cad[tam - i - 1] == 'B')
        negro[black++] = tam - i - 1;
    }

    if (!negro)
      res = 0;
    else {
      // La solución será probar todos los swaps adyacentes
      // un largo y todos adyacentes
      // and so on B|      
      for (int largo = 0; largo <= black; largo++) {
        dinero = 0;
        r = 0; // swaps restantes

        while (r < largo && r < black) {// swaps largos
          (abs(blanco[r] - negro[r]) != 1) ? dinero += A : dinero += (A - B);
          r++;
        }

        for (int j = r; j < black; j++)
          dinero += (A - B)*(abs(blanco[j] - negro[j]));        

        if (dinero < res)
          res = dinero;
      }
    }
    cout << res << "\n";
  }
  return 0;
}