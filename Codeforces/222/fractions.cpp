// Reducing fractions
#include <bits/stdc++.h>
using namespace std;
#define MAXI 10000000

int criba[MAXI + 7];

void cribaD() {
    for (int i = 0; i < MAXI; i++)
        criba[i] = i;
    
    for (int i = 2; i < MAXI; i++) {
        if (criba[i] == i) {
            for (int j = 2; j*i < MAXI; j++ ) {
                criba[j*i] = i;
            }
        }
    }
}

int Exponenciar(int a, int n) {
    int res = 1, p = a;
    for (; n; n >>= 1) {
        if (n & 1) res =
            (res * p);
        p = (p * p);
    }
    return res;
}

int main() {
    int n, m, res, num;
    vector<int> numer, deno;
    map<int, int> m_numer, m_deno, gcd;
    
    cribaD();
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        cin >> num;
        numer.push_back(num);
        while (num != 1) { // Descomponemos en factores primos
            m_numer[ criba[num] ]++;
            num /= criba[num];
            cout << num << endl;
        }
    }
    
    for (int i = 0; i < m; i++) {
        cin >> num;
        deno.push_back(num);
        while (num != 1) { // Descomponemos en factores primos
            m_deno[ criba[num] ]++;
            num /= criba[num];
            cout << num << endl;
        }
        cout << "-- -- \n";
    }
    cout << "edfdsfdfsd\n";
    for (auto g : m_numer) {
        if ( m_deno.count( g.first ) != 0 ) { // Sacamos el gcd
            gcd[ g.first ] = min(g.second, m_deno[ g.first ]);
        }
    }
    
    for (auto g: numer) {
        map<int , int> m_aux;
        int aux = g;
        
        while ( aux != 1) {
            m_aux[ criba[aux] ]++;
            aux /= criba[aux];
        }
        
        for (auto primo : m_aux) {
            if ( gcd.count( primo.first ) != 0 ) {
                m_aux[ primo.first ] = primo.second - gcd[ primo.first ];
            }
        }
        
        res = 1;
        for (auto primo : m_aux) {
            res *= Exponenciar(primo.first, primo.second);
        }
        cout << res << "**\n";
    } 
    
    return 0;
}
