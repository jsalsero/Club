#include <bits/stdc++.h>
using namespace std;

int main() {
	int materias, cate, num, tam, mini, flag;	
	string res;

	while (cin >> materias && materias != 0) {
		map <int, int> M;
		res = "yes\n";

		cin >> cate;
		for (int i = 0; i < materias; ++i) {
			cin >> num;
			M[num]++;
		}
		for (int i = 0; i < cate; ++i) {
			cin >> tam >> mini;
			flag = 0;
			for (int j = 0; j < tam; j++) {
				cin >> num;
				if (M.count(num) != 0)
					flag++;
			}
			if (flag < mini)
				res = "no\n";
		}
		cout << res;
	}

	return 0;
}
/*
3 2
0123 9876 2222
2 1 8888 2222
3 2 9876 2222 7654
3 2
0123 9876 2222
2 2 8888 2222
3 2 7654 9876 2222
0

*/
