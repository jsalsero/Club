#include <bits/stdc++.h>
using namespace std;

int main(){
	int s,b,l,r,j;
	cin.tie(0);
	ios::sync_with_stdio(true);

	while(cin >> s >> b && s != 0 && b != 0)s{
		int LS[100007];		
		int RS[100007];		

		for(int i = 2; i <= s; i++){
			LS[i] = i - 1;
		}
		for(int i = 1; i < s; i++){
			RS[i] = i + 1;
		}

		for(int i = 0; i < b; i++){
			cin >> l >> r;
			
		}
		cout << "-\n";
	}
	return 0;
}
/*
1 1
1 1
10 4
2 5
6 9
1 1
10 10
5 1
1 1
0 0


*/
