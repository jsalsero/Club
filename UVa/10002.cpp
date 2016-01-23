#include <bits/stdc++.h>
using namespace std;

// Definiciones iniciales
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

// Producto cruz entre vectores v y w
double Cruz(const Punto& v, const Punto& w) {
    return v.x * w.y - v.y * w.x;
}

typedef vector<Punto> Poligono;

// Centroide de un poligono
Punto Centroide(const Poligono& P) {
    double x = 0, y = 0, k = 0;
    for (int i = 1; i < P.size(); ++i) {
        double cruz = Cruz(P[i - 1], P[i]);
        x += cruz * (P[i - 1].x + P[i].x);
        y += cruz * (P[i - 1].y + P[i].y);
        k += cruz * 3;
    }
    return Punto(x/k, y/k);
}

int n, x, y;

int main()
{
	while(1){
		scanf("%d", &n);
		if(n<3)
			break;
		Poligono poli;
		while(n--){
			scanf("%d %d", &x, &y);
			Punto paux(x,y);
			poli.push_back(paux);
		}
		sort(poli.begin(), poli.end());
		for( Punto p : poli){
			printf("%f %f", p.x, p.y);
		}
		Punto baricentro = Centroide(poli);
		printf("%f %f\n", baricentro.x, baricentro.y);
	}
	return 0;
}
