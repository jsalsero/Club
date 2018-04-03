#include <bits/stdc++.h>
using namespace std;

struct query {
	int op, a, b, c;
	query() : a(0), b(0), c(0), op(0) {}
	query(int OP, int A, int B, int C) : a(A), b(B), c(C), op(OP) {}
};

#define endl '\n'

void swap_row(vector< vector<int> > &matrix, int row) {
	for (int i = matrix[0].size() - 1; i > 0; --i)
		swap(matrix[row][i], matrix[row][i - 1]);
}

void swap_col(vector< vector<int> > &matrix, int col) {
	for (int i = matrix.size() - 1; i > 0; --i)
		swap(matrix[i][col], matrix[i - 1][col]);
}

int main() {
	int n, m, q;

	cin >> n >> m >> q;

	vector<query> data;
	vector< vector<int> > matrix(n, vector<int>(m));

	for (int i = 0; i < q; ++i) {
		int op;
		cin >> op;
		
		if (op < 3) {
			int x;
			cin >> x;
			data.push_back({op, x, 0, 0});
		} else {
			int x, y, val;
			cin >> x >> y >> val;
			data.push_back({op, x, y, val});
		}
	}
	reverse(data.begin(), data.end());

	for (int i = 0; i < q; ++i) {
		int op = data[i].op;
		int a  = data[i].a;

		if (op < 3) {
			if (op == 1)	swap_row(matrix, a - 1);
			if (op == 2)	swap_col(matrix, a - 1);
		} else {
			int b  = data[i].b;
			int c  = data[i].c;
			matrix[a - 1][b - 1] = c;
		}
	}

	for (const auto& row : matrix) {
		for (const auto& cell : row)
			cout << cell << ' ';
		cout << endl;
	}

	return 0;
}
