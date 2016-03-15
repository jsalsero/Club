#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int E[107], V[107];
int memo1[107][1007];
int memo2[107][1007];

int chicas, energia, varo;
int money(int pos, int ener) {
	if (ener < 0) return INF;
	if (pos < 0) return 0;
	if (memo2[pos][ener] != -1) return memo2[pos][ener];

	return memo2[pos][ener] = min(V[pos] + money(pos - 1, ener), money(pos - 1, ener - E[pos]));
}

int acc;
int dp(int pos, int ener) {
	if (ener < 0) return INF;
	/* Bug caca
	if (pos == chicas && ener == energia) { 
		acc = 0;
		for (int i = 0; i < chicas; i++) acc += V[i];
		if (acc <= varo) return 1;
		else return INF;
	}
	*/
	if (pos == chicas) return 1;
	if (memo1[pos][ener] != -1) return memo1[pos][ener];

	if (money(pos, energia) <= varo)
		return memo1[pos][ener] = dp(pos + 1, ener) + dp(pos + 1, ener - E[pos]);
	return memo1[pos][ener] = 0;
}

void init() {
	for (int h = 0; h < 105; h++) {
		for (int k = 0; k < 1005; k++) {
			memo1[h][k] = -1;
			memo2[h][k] = -1;			
		}
	}
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {		
		cin >> chicas >> energia >> varo;
		init();
		for (int i = 0; i < chicas; ++i) {
			cin >> E[i];
		}
		for (int i = 0; i < chicas; ++i) {
			cin >> V[i];
		}
		//cout << dp(0, energia) << endl;
		(dp(0, energia) > 0) ? cout << "Yes-Man\n" : cout << "No-Man\n";

	}
	return 0;
}
/*
2
1 4 1
3
3
2 4 1
2 3
3 2

1
1 2 1
2
1000


*/
