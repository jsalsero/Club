#include <bits/stdc++.h>
using namespace std;

int main() {
  int inicio, tam;
  set <string> S;
  string cad, aux;

  while (cin >> cad) {
    transform(cad.begin(), cad.end(), cad.begin(), ::tolower);    

    tam = cad.size();
    inicio = 0;
    for (int i = 0; i < tam; i++) {
      if (!isalpha(cad[i])) {
        aux = cad.substr(inicio,i - inicio);
        inicio = i + 1;
        if (aux != "")
          S.insert(aux);
      }
    }
    aux = cad.substr(inicio, -1);
    if (aux != "")
      S.insert(aux); 
  }

  for (auto var : S)
    cout << var << "\n";  
  return 0;
}
