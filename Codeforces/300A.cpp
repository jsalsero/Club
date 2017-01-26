#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void print(vector<int> &data) {
	cout << data.size() << ' ';
	for (const auto& var : data)
		cout << var << ' ';
	cout << endl;
}

int main() {
	int n;

	cin >> n;
	vector<int> neg, pos, cero;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		if (num  < 0) 	neg.push_back(num);
		if (num  > 0) 	pos.push_back(num);
		if (num == 0)	cero.push_back(0);
	}

	if (pos.size() == 0)
		for (int i = 0; i < 2; ++i)
			pos.push_back(neg.back()), neg.pop_back();

	if (neg.size() % 2 == 0)
		cero.push_back(neg.back()), neg.pop_back();

	print(neg);
	print(pos);
	print(cero);

	return 0;
}
