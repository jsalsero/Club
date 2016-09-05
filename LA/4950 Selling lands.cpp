#include <bits/stdc++.h>
using namespace std;
typedef long long Long;
#define pii pair<int, int>
#define tope pila.top()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> actual(m, 0);
        map<int, int> M;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                char letra;
                cin >> letra;
                actual[j]++;
                if (letra == '#')
                    actual[j] = 0;
            }
            stack< pair<Long, Long> > pila;
            int j = 0;

            while (actual[j] == 0)  j++;
            if (j == m) 
                continue;

            pii prev(0, 0);
            for (; j < m; ++j) {
                int borrados = 1;
                while (!pila.empty() && actual[j] <= tope.first) {
                    //int aux = tope.first * (tope.second + borrados - 1);
                    borrados += tope.second;
                    pila.pop();
                    if (pila.empty())
                        prev = pii(0, 0);
                    else
                        prev = tope;
                }

                if (actual[j] == 0)
                    continue;
                
                pii nuevo(actual[j], borrados);
                if (prev.first + prev.second > actual[j]) {
                    nuevo.first = prev.first;
                    nuevo.second = prev.second + borrados;
                    if (!pila.empty())
                        pila.pop();
                }
                prev = nuevo;
                //cout << i << " " << j << " " << nuevo.first << ' '<< nuevo.second 
                //<< " " << actual[j] <<  endl;
                M[nuevo.first + nuevo.second]++;
                pila.push(nuevo);
            }
        }

        for (auto var : M)
            cout << var.second << " x " << 2 * var.first << "\n";
    }
    return 0;
}
/*
1
6 5
..#.#
.#...
#..##
...#.
#....
#..#.

*/
