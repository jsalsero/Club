#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, num, n1, n2;	

	while ( cin >> N && N != 0) {	
		priority_queue< int, vector<int>, greater<int> > PQ;
		
		for (int i = 0; i< N; i++) {
			cin >> num;
			PQ.push(num);
		}

		int res = 0;
		while (!PQ.empty()) { 
			if (PQ.size() == 1)
				break;
			n1 = PQ.top();
			PQ.pop();
			n2 = PQ.top();
			PQ.pop();
			int aux = n1 + n2;
			res += aux;
			PQ.push(aux);
		}
		cout << res << "\n";
	}
	return 0;
}
