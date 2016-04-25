#include <iostream>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main() {
	int Q, n;
	char c;

	ordered_set S;
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> Q;	
	while (Q--) {
		cin >> c >> n;
		if (c == 'I')
			S.insert(n);
		else if (c == 'D')
			S.erase(n);
		else if (c == 'K') {
			if (n > S.size())
				cout << "invalid\n";
			else {
				cout << *S.find_by_order(n - 1) << "\n";
			}
		} else
			cout << S.order_of_key(n) << "\n";		
	}
	return 0;
}
/*
8
I -1
I -1
I 2
C 0
K 2
D -1
K 1
K 2

*/
