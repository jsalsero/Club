#include <bits/stdc++.h>
using namespace std;

typedef double Coord;

const double ERROR = 1e-9;
const double M_2PI = 2 * M_PI;

// Tolerancia en flotantes
bool Igual(Coord a, Coord b) { 
    return fabs(a - b) < ERROR;
}

// Punto en 2D
struct Punto {
    Coord x, y;

    Punto() : x(0), y(0) {}
    Punto(Coord x_, Coord y_)
        : x(x_), y(y_) {}

    // Izquierda a derecha, abajo a arriba
    bool operator<(const Punto& cmp) const {
        if (!Igual(x, cmp.x)) return x < cmp.x;
        return Igual(y, cmp.y)? false: y < cmp.y;
    }
 
    bool operator==(const Punto& cmp) const {
        return Igual(x, cmp.x) && Igual(y, cmp.y);
    } 
};

double Distancia(const Punto& p, const Punto& q) {
    return hypot(p.x - q.x, p.y - q.y);
}

struct Linea {
    Punto p, q;
    //long long a, b, c; // <comment/>
    double a, b, c; // <uncomment/>

    Linea() : p(), q(), a(0), b(0), c(0) {}

    Linea(Coord a_, Coord b_, Coord c_)
        : p(), q(), a(a_), b(b_), c(c_) {
        if (Igual(a, 0)) {
            c /= -b; b = -1;
            p = Punto(0, c);
            q = Punto(1, c);
        } else if (Igual(b, 0)) {
            c /= -a; a = -1;
            p = Punto(c, 0);
            q = Punto(c, 1);
        } else {
            p = Punto(-c/a, 0);
            q = Punto(-(b+c)/a, 1);
        } if (q < p) swap(p, q);
    }

    Linea(const Punto& p_, const Punto& q_)
        : p(p_), q(q_), a(), b(), c() {
        // Asegura p como punto menor
        if (q < p) swap(p, q);
        a = q.y - p.y;
        b = p.x - q.x;
        if (!a) c = p.y, b = -1;
        else if (!b) c = p.x, a = -1;
        else {
            // <comment>
            //c = abs(__gcd(a, b));
            //a /= c, b /= c;
            // </comment>
            c = -a*p.x - b*p.y;
        }
    }

    // ¡Peligro! Ordena por ecuacion de recta
    bool operator<(const Linea& cmp) const {
        if (!Igual(a, cmp.a)) return a < cmp.a;
        if (!Igual(b, cmp.b)) return b < cmp.b;
        return Igual(c, cmp.c)? false: c < cmp.c;
    }
};

bool LineasParalelas(const Linea& l, const Linea& m) {
    //return l.a == m.a && l.b == m.b; // <comment/>
    // <uncomment>
    if (Igual(l.b, 0) || Igual(m.b, 0))
        return Igual(l.a, m.a) && Igual(l.b, m.b); 
    return Igual(l.a/l.b, m.a/m.b);
    // </uncomment>
}

Linea PerpendicularEnPunto(const Linea& l, const Punto& p) {
    return Linea(p, Punto(p.x + l.a, p.y + l.b));
}


Punto PuntoInterseccion(const Linea& l, const Linea& m) {
    if (LineasParalelas(l, m)) return Punto();
    if (Igual(l.a, 0)) return Punto(
               (double)(l.c*m.b + m.c) / -m.a, l.c);
    double y = (double)(m.a*l.c - l.a*m.c) / (m.b*l.a - m.a*l.b);
    double x = (double)(l.c + l.b * y) / -l.a;
    return Punto(x, y);
}

// Circulo en 2D
struct Circulo {
    Punto c; Coord r;

    Circulo() : c(), r(0) {}
    Circulo(const Punto& c_, Coord r_)
        : c(c_), r(r_) {}

    bool operator<(const Circulo& cmp) const {
        if (!(c == cmp.c)) return c < cmp.c;
        return Igual(r, cmp.r)? false: r < cmp.r;
    }
};

// Saber si un punto esta en el perimetro de un circulo
bool PuntoEnCircunferencia(const Punto& p, const Circulo& c) {
    return Igual(Distancia(p, c.c), c.r);
}

int main(){
	int N, maxi;
	Coord x,y;

	while(cin >> N && N != 0){
		vector < Punto > num;

		for(int i = 0; i < N; i++){
			cin >> x >> y;
			num.push_back( Punto(x,y) );
		}

		if(N < 3){
			cout << N << "\n";
			continue;
		}

		maxi = 2;
		for(int i = 0; i < N; i++){
			for(int j = i + 1; j < N; j++){
				map<Punto, int> M;
                
				for(int k = 0; k < N; k++){
					if(k == i || k == j) continue;

					Punto a = num[i];
					Punto b = num[j];
					Punto c = num[k];

					if( Igual( (a.x - b.x)*(b.y - c.y) - (a.y - c.y)*(b.x - c.x), 0.0 ))
						continue;

					Linea l1(a,b);
					Linea l2(b,c);

					if(LineasParalelas(l1, l2))  continue;

					Linea m1 = PerpendicularEnPunto(l1, Punto( (a.x + b.x)/2, (a.y + b.y)/2 ) );
					Linea m2 = PerpendicularEnPunto(l2, Punto( (b.x + c.x)/2, (b.y + c.y)/2 ) );

					Punto centro = PuntoInterseccion(m1, m2);

					//Coord radio = Distancia(a, centro);
										
					M[centro]++;
					maxi = max(maxi, M[centro] + 2);

					//cout << centro.x << " " << centro.y << "  " << M[centro] + 2 << endl;
				}
			}
		}

		cout << maxi << "\n";

	}
	return 0;
}