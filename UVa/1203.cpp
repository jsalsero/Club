#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

int main() {
	int id, period, K;
	string cad;
	priority_queue< pii, vector< pii >, greater<pii> > pq;

	while (cin >> cad) {
		if (cad[0] == '#') break;
		
		cin >> id >> period;
		for (int i = 1; i <= 10000; ++i) 
			pq.push( make_pair(period*i, id) );		
	}
	cin >> K;
	while (K--) {
		//cout << pq.top().first << "  ";
		cout << pq.top().second << "\n";
		pq.pop();
	}
	return 0;
}
