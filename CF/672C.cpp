#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

double power(double n) { return n*n; }

int main() {
	double ax, ay, bx, by, tx, ty;
	int n;

	cin >> ax >> ay >> bx >> by >> tx >> ty;
	cin >> n;
	vector< pair<double, double> > data(n);

	double ans = 0;
	for (int i = 0; i < n; ++i) {
		cin >> data[i].first >> data[i].second;
		ans += 2.0*sqrt(power(data[i].first - tx) + power(data[i].second - ty));
	}

	cout << " Dobles  " << ans << endl;

	double adil = sqrt(power(data[0].first - ax) + power(data[0].second - ay)) + sqrt(power(data[0].first - tx) + power(data[0].second - ty));
	int Aidx = 0;
	for (int i = 1; i < n; ++i) {
		double dist = sqrt(power(data[i].first - ax) + power(data[i].second - ay)) + sqrt(power(data[i].first - tx) + power(data[i].second - ty));
		if (dist < adil)
			adil = dist, Aidx = i;
	}

	double bera = sqrt(power(data[0].first - bx) + power(data[0].second - by)) + sqrt(power(data[0].first - tx) + power(data[0].second - ty));
	int Bidx = 0;
	if (Bidx == Aidx)
		Bidx++, bera = sqrt(power(data[1].first - bx) + power(data[1].second - by)) + sqrt(power(data[1].first - tx) + power(data[1].second - ty));


	for (int i = 0; i < n; ++i) {
		double dist = sqrt(power(data[i].first - bx) + power(data[i].second - by)) + sqrt(power(data[i].first - tx) + power(data[i].second - ty));
		if (dist < bera && i != Aidx)
			bera = dist, Bidx = i;
	}


	cout << "	Adil  " << Aidx << endl;
	cout << "	Bera  " << Bidx << endl;

	ans += adil + bera
		   - 2.0*sqrt(power(data[Bidx].first - tx) + power(data[Bidx].second - ty))
		   - 2.0*sqrt(power(data[Aidx].first - tx) + power(data[Aidx].second - ty));

	cout << ans << endl;
	return 0;
}
