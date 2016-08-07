#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pii> seg(n);
    for (int i = 0; i < n; ++i)
        cin >> seg[i].first >> seg[i].second;
    
    int q;
    cin >> q;
    stack<pii> pila;
    int izq = 0;
    for (int i = 0; i < q; ++i) {
        int point;
        cin >> point;
        while (izq < seg.size() && seg[izq].first <= point) {
            pila.push(pii(seg[izq].second, izq + 1));
            izq++;
        }
        int ans = -1;
        while (!pila.empty() && ans == -1) {
            if (point <= pila.top().first)
                ans = pila.top().second;
            else
                pila.pop();
        }
        cout << ans << "\n";
    }

    return 0;
}
/*
3
2 10
2 3
5 7
11
1
2
3
4
5
6
7
8
9
10
11

9
1 10
1 9
1 8
1 7
1 6
1 5
1 4
1 3
1 2
10
1 2 3 4 5 6 7 8 9 10

*/
