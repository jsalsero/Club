#include <bits/stdc++.h>
using namespace std;

struct Trie {
	map<int, Trie*> sig;

	void Agregar(const int& a) {
		Trie* cabeza = this;
		for (int i = 0; i < 31; ++i) {
			int val = (a & 1<<i)? 1: 0;
			if (cabeza->sig.find(val) == cabeza->sig.end())
				cabeza->sig[val] = new Trie();
			cabeza = cabeza->sig[val];
		}
	}

	
	int Query(const int& n) {
		Trie* cabeza = this;
		int ans = 0;
		for (int i = 0; i < 31; ++i) {
			int val = (n & 1<<i)? 1: 0;			
			if (cabeza->sig.find(1 - val) == cabeza->sig.end())
				cabeza = cabeza->sig[val];
			else {
				cabeza = cabeza->sig[1 - val];
				ans += (1<<i);
			}

		}
	}	
};

int Query(Trie* t, const int& n) {
		int ans = 0;
		for (int i = 0; i < 31; ++i) {
			int val = (n & 1<<i)? 1: 0;			
			if (t->sig.find(1 - val) == t->sig.end())
				t = t->sig[val];
			else {
				t = t->sig[1 - val];
				ans += (1<<i);
			}

		}
	}

int main() {
	int T, N, num;
	/*
	for (int i = 0; i < 10; i++) {
		int val = (19 & 1<<i)? 1: 0;
		cout << val;
	}
	*/

	cin >> T;
	while (T--) {
		cin >> N;
		Trie* xors = new Trie();
		int prefix = 0;
		int ans = 0;
		xors->Agregar(0);
		for (int i = 0; i < N; ++i) {
			cin >> num;
			prefix ^= num;
			cout << "-- " << prefix << endl;
			xors->Agregar(prefix);
			//ans = max(ans, Query(xors, prefix));
			ans = max(ans, xors->Query(prefix));
		}
		cout << ans << "\n";
	}
	return 0;
}
/*
2  
5  
3  7  7  7  0  
5  
3  8  2  6  4

*/
