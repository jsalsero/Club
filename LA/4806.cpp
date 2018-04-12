#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,b, num;
	bool flag;

	while(cin >> n >> b && n != 0 && b != 0){
		vector<int> V;
		map<int,int> M;
		flag = true;

		for(int i = 0; i < b; i++){
			cin >> num;
			V.push_back(num);
			//M[num]++;
		}
		for(int i = 0; i < b; i++){
			for(int j = 0; j < b; j++){
				M[abs(V[i] - V[j])]++;
			}
		}
		for(int i = 0; i <= n; i++){
			if(M.count(i) == 0){
				flag = false;
				break;
			}
		}
		(flag) ? cout << "Y\n" : cout << "N\n";
	}
	return 0;
}
/*
6 7
2 1 3 4 0 6 5
5 4
5 3 0 1
5 3
1 5 0
0 0

*/