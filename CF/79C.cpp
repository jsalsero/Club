#include <bits/stdc++.h>
using namespace std;

const int INF = 1 << 30;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string S;
    int n;

    cin >> S >> n;
    vector<string> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    
    int izq = 0;
    int der = 0;
    int res = -1;
    int empieza = 0;
    string aux;
    while (der < S.size()) {
        if (der - izq + 1 < 10)
            aux = S.substr(izq, der - izq + 1);
        else
            aux = S.substr(der - 9, 10);

        int avanza = INF;
        for (auto cad : v) {
            int pos = (int)aux.find(cad);
            if (pos != -1)
                avanza = min(avanza, (int)cad.size());
        }

        if (avanza != INF) {
            if (res < der - izq) {
                res = der - izq;
                empieza = izq;
            }
            izq = der - avanza + 2, der = izq;
        } else
            der++;
    }
    if (izq != der && res < der - izq) {
        res = der - izq;
        empieza = izq;
    }

    cout << res << " " << empieza << "\n";
    return 0;
}
/*
Go_straight_along_this_street
5
str
long
tree
biginteger
ellipse

IhaveNoIdea
9
I
h
a
v
e
N
o
I
d

unagioisii
2
ioi
unagi

*/
