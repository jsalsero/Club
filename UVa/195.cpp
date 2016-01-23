#include <bits/stdc++.h>
using namespace std;

bool comp (const char &a, const char &b) {
	int delta = tolower(a) - tolower(b);
	return delta ? delta < 0 : a < b;
}

int main() {
	int N;
	string cad;

	cin >> N;
	for (int i = 0; i < N; ++i)	{
		cin >> cad;
		sort(cad.begin(), cad.end());
		cout << cad << "\n";
		while( next_permutation(cad.begin(), cad.end()) )
			cout << cad << "\n";		
	}
	return 0;
}
