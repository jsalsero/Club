#include <bits/stdc++.h>
using namespace std;

int const INF = 1 << 30;

bool search(const int i, const int j, const vector< vector<char> > &data, const int mvI, const int mvJ) {
	int xs = 0;
	for (int h = 0; h < 3; ++h) {
		if (data[i + h*mvI][j + h*mvJ] == 'o')
			xs = -INF;
		xs += (data[i + h*mvI][j + h*mvJ] == 'x');
	}
	return xs == 2;
}

bool check(const int i, const int j, const vector< vector<char> > &data) {
	bool ans = false;

	ans |= search(i, j, data, 1,  0);
	ans |= search(i, j, data, 0,  1);
	ans |= search(i, j, data, 1,  1);
	ans |= search(i, j, data, 1, -1);
	
	return ans;
}

int main() {
	vector< vector<char> > data(8, vector<char>(8, 'o'));

	for (int i = 2; i < 6; ++i)
		for (int j = 2; j < 6; ++j)
			cin >> data[i][j];

	bool ans = false;
	for (int i = 2; i < 6 && !ans; ++i)
		for (int j = 2; j < 6 && !ans; ++j)
			if (check(i, j, data))
				ans = true;

	cout << (ans? "YES": "NO");
	return 0;
}

