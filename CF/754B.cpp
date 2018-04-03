#include <bits/stdc++.h>
using namespace std;

bool possible(int i, int j) {
	return (i < 4 && j < 4 && i >= 0 && j >= 0);
}

bool izquierda(int i, int j, vector< vector<char> > &data) {
	if (!possible(i, j + 2))
		return false;

	int xs = 0;
	for (int h = 0; h < 3; ++h) {
		if (data[i][j + h] == 'o')
			xs = -(1<<30);
		xs += (data[i][j + h] == 'x');
	}
	
	return xs == 2;
}

bool abajo(int i, int j, vector< vector<char> > &data) {
	if (!possible(i + 2, j))
		return false;

	int xs = 0;
	for (int h = 0; h < 3; ++h) {
		if (data[i + h][j] == 'o')
			xs = -(1<<30);
		xs += (data[i + h][j] == 'x');	
	}
		
	return xs == 2;
}

bool diagonalRight(int i, int j, vector< vector<char> > &data) {
	if (!possible(i + 2, j + 2))
		return false;

	int xs = 0;
	for (int h = 0; h < 3; ++h) {
		if (data[i + h][j + h] == 'o')
			xs = -(1<<30);
		xs += (data[i + h][j + h] == 'x');	
	}
		
	return xs == 2;
}

bool diagonalLeft(int i, int j, vector< vector<char> > &data) {
	if (!possible(i - 2, j + 2))
		return false;

	int xs = 0;
	for (int h = 0; h < 3; ++h) {
		if (data[i - h][j + h] == 'o')
			xs = -(1<<30);
		xs += (data[i - h][j + h] == 'x');	
	}
		
	return xs == 2;
}

bool diagonal3(int i, int j, vector< vector<char> > &data) {
	if (!possible(i + 2, j - 2))
		return false;

	int xs = 0;
	for (int h = 0; h < 3; ++h) {
		if (data[i + h][j - h] == 'o')
			xs = -(1<<30);
		xs += (data[i + h][j - h] == 'x');	
	}
		
	return xs == 2;
}


bool tira(int i, int j, vector< vector<char> > &data) {
	return (izquierda(i, j, data) || abajo(i, j, data) || diagonalRight(i, j, data) || diagonalLeft(i, j, data)
			|| diagonal3(i, j, data));	
}

int main() {
	vector< vector<char> > data(4, vector<char>(4));
	
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			cin >> data[i][j];
	
	bool ans = false;
	for (int i = 0; i < 4 && !ans; ++i)
		for (int j = 0; j < 4 && !ans; ++j)
			if (tira(i, j, data))
				ans = true;

	cout << (ans? "YES": "NO");
	return 0;
}	
