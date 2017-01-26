#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a, b, c, d;

	cin >> n >> a >> b >> c >> d;

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		int q = i;
		int r = q + b - c;
		int t = q + a - d;
		int u = q + a + b - c - d;
		if (r <= 0 || t <= 0 || u <= 0 || r > n || t > n || u > n)
			continue;
		ans += n;
	}
	cout << ans << endl;

	return 0;
}
/*
q a r 
b s c
t d u 

q + a + b + s   1
a + r + s + c 	2
b + s + t + d	3
s + c + d + u   4

1 - 2
  q + a + b + s = a + r + s + c
  q + b - r - c = 0
  r = q + b - c

1 - 3
  q + a + b + s = b + s + t + d
  q + a - t - d = 0
  t = q + a - d

1 - 4 
  q + a + b + s = s + c + d + u
  q + a + b - c - d - u = 0
  u = q + a + b - c - d




*/