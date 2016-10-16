#include <bits/stdc++.h>
using namespace std;

typedef long long Long;

Long Expo(Long a, Long n) {
    Long ans = 1;
    for (; n; n >>= 1) {
        if (n & 1) ans *= a;
        a *= a;
    }
    return ans;
}

struct Fraccion {
    Long num, den;
    Fraccion() : num(0), den(1) {}

    Fraccion (string cad) {
        int tam   = cad.size();
        int punto = cad.find(".");
        Fraccion ans(stol(cad.substr(0, punto)), 1);

        int cycle = cad.find("(");
        int  L = (cycle < 0 ? tam : cycle) - punto - 1;
        Long n = (L > 0 ? stol(cad.substr(punto + 1, L)) : 0);
        ans    = ans + Fraccion(n, Expo(10, L));

        int offset = L;
        L   = tam - cycle - 2;
        n   = (cycle > 0 ? stol(cad.substr(cycle + 1, L)) : 0);
        ans = ans + Fraccion(n, stol(string(L, '9')) * Expo(10, offset));

        num = ans.num;
        den = ans.den;
    }

    Fraccion(Long n, Long d) {
        if (d < 0) n = -n, d = -d;
        Long gcd = __gcd(abs(n), abs(d));
        num = n / gcd, den = d / gcd;
    }

    string to_decimal() {
        string decimal = to_string(num/den) + '.';
        if (num % den == 0)
            return decimal += "0";
        
        int rem = num % den;
        unordered_set<int> rept;
        vector<int> digit, R; // R -> residuos

        while (rem && !rept.count(rem)) {
            rept.insert(rem);
            R.push_back(rem);
            rem *= 10;
            digit.push_back(rem / den);
            rem %= den; 
        }

        for (int i = 0; i < digit.size(); ++i) {
            if (rem && R[i] == rem) // Empieza lo periodico
                decimal += '(';
            decimal += (digit[i] + '0');
        }
        if (rem)
            decimal += ')';
        return decimal;
    }

    Fraccion operator+(const Fraccion& f) {
        Long gcd = __gcd(den, f.den);
        return Fraccion(
            num * (f.den / gcd) +
            f.num * (den / gcd),
            den * (f.den / gcd)
        );
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Long n, d;
    while (cin >> n >> d && n != 0 && d != 0) {
        Fraccion A(n, d);
        string dec = A.to_decimal();
        int ini = dec.find("(");
        int fin = dec.find(")");

        int conta = 0;
        for (int i = dec.find("."); i < dec.size(); ++i) {
            if (i == ini || i == fin) continue;
            if (conta != 0 && conta % 50 == 0)
                cout << '\n';
            conta++;
            cout << dec[i];
        }

        if (ini == -1)
            cout << "\nThis expansion terminates.\n\n";
        else
            cout << "\nThe last " << fin - ini - 1 << " digits repeat forever.\n\n";
    }       
    return 0;
}
