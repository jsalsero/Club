/*
000
100

110
101

1234
1243
1324
1342

1

1 2 

1 2 3 
1 3 2 

1 2 3 4  / 
1 2 4 3  /
1 3 2 4  /
1 3 4 2  /

	


*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	int *ans = new int[56];
	ans[1] = ans[2] = 1;
	ans[3] = 2;

	for (int i = 4; i <= n; ++i)
		ans[i] = ans[i - 3] + ans[i - 1] + 1;

	cout << ans[n];
	return 0;
}