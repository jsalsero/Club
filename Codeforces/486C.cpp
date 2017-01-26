#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, p;
	string cad;

	cin >> n >> p >> cad;

	--p;
	if (p >= n/2)
		p = n - p - 1, reverse(cad.begin(), cad.end());

	vector<int> acc(n);
    int left  = -1;
    int right = -1;
	
	for (int i = 0; i < n/2; ++i) {
		char a = cad[i], b = cad[n - i - 1];
		if (a > b)
			swap(a, b);

		int up   = b - a;
		int down = 'z' - b + a - 'a' + 1;
		//cout << '\t' << a << ' ' << b << ' ' << min(up, down) << endl;
		acc[i] = min(up, down);
        if (left == -1 && acc[i] > 0)
            left = i;
        if (acc[i] > 0)
            right = i; 
	}
	
	//cout << "left  " << left << endl;
	//cout << "right " << right << endl;
	
	int ans = 0;
	if (left != -1 && right != -1) {
		for (int i = left; i <= right; ++i)
			ans += acc[i];
		//cout << "      " << ans << endl;
		ans += min(abs(left - p), abs(right - p)) + right - left;
	}
	cout << ans << endl;

	return 0;
}
