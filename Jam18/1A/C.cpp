#include <bits/stdc++.h>
#define endl '\n'
#define Long long long
#define forn(i, n) for(int i = 0; i < n; ++i)
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;

int const MAXN = 5005;

//double const M_PI = 3.14159265358979323846;

double p, w, h;

const double ERROR = 1e-9;

bool Igual(double a, double b) {
    return fabs(a - b) < ERROR;
}

struct Punto {
    double x, y;

    Punto() : x(), y() {}
    Punto(double X, double Y) : x(X), y(Y) {}

    bool operator<(const Punto &cmp) const {
        if (!Igual(x, cmp.x)) return x < cmp.x;
        return Igual(y, cmp.y)? false: y < cmp.y;
    }
};

double Dist(const Punto &p, const Punto &q) {
    return hypot(p.x - q.x, p.y - q.y);
}


struct Linea {
    Punto p, q;
    double a, b,c;

    Linea() : p(), q(), a(), b(), c() {}

    Linea(const Punto &P, const Punto& Q) 
    : p(P), q(Q), a(), b(), c() {
        if (q < p) swap(p, q);

        a = q.y - p.y;
        b = p.x - q.x;
        if (!a) c = p.y, b = -1;
        else if (!b) c = p.x, a = -1;
        else {
            c = -a*p.x - b*p.y;
        }
    }
};

Punto Rotar(const Punto &p, double rad) {
    return Punto(p.x * cos(rad) - p.y * sin(rad),
                 p.x * sin(rad) + p.y * cos(rad));
}


Punto PuntoInter(const Linea& l, const Linea& m) {
    if (Igual(l.a, 0)) return Punto((double)(l.c * m.b + m.c) / -m.a, l.c);
    double y = (double)(m.a * l.c - l.a*m.c) / (m.b * l.a - m.a * l.b);
    return Punto((double)(l.c + l.b * y) / -l.a, y);
}

double calc(double ang) {
    Linea izq(Punto(-w/2.0, 0), Punto(-w/2.0, 1));
    Linea der(Punto( w/2.0, 0), Punto( w/2.0, 1));

    Punto a(-10000, 0); 
    Punto b( 10000, 0);
    
    a = Rotar(a, ang); // CCW
    b = Rotar(b, ang);
    
    Linea cen(a, b);

    return Dist(PuntoInter(izq, cen), PuntoInter(cen, der));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cout << fixed << setprecision(12);

    int t;
    cin >> t;

    forn(caso, t) {
        if (caso) cout << endl;
        cout << "Case #" << caso + 1 << ": ";
        
        double n;
        cin >> n >> p;

        forn(i, n) cin >> w >> h;
        if (w < h) swap(w, h);

        double izq = 0.0, der = M_PI/4.0;
        double m, total;
        
        double maxi = n * (2.0*w + 2.0*h) + 2.0*n*calc(M_PI/4.0);

        cout << min(p, maxi);
        continue;
   /* 
        cout << maxi << "   ";
        if (p <= n * (2.0*w + 2.0*h) + 2.0 * maxi * n) {
            cout << "   " << p << endl;
            continue;
        }

        forn(it, 100) {
            m = (izq + der) / 2.0;
            total = n * (2.0*w + 2.0*h) + 2.0*calc(m);

            if (total < p)
                izq = m + 1e-9;
            else
                der = m;
        }

        cout << fixed << setprecision(12) << total;
        */
    }

    return 0;
}

