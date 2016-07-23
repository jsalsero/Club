#include <bits/stdc++.h>
using namespace std;

vector<int> primos = {2,3,5,7,11,13,17,19,23,29,31,37};

int check(int n, int mask) {
	int res = 0;
	for (int i = 0; primos[i] <= n; i++)
		if (n % primos[i] == 0) res |= (1<<i);
	return res;
}

int n;
vector<int> V(101);
int memo[101][5000];
int dp(int pos, int mask) {
	if (pos == n)	return 0;
	int &tabla = memo[pos][mask];
	if (tabla != -1) tabla;
	int ans = 1<<30;
	
	for (int i = 0; V[pos] - i >= 1; i++) {
		int factoriza = check(V[pos] - i, mask);
		if ((factoriza&mask) == 0)
			ans = min(ans, dp(pos + 1, factoriza|mask) + i);
        
        factoriza = check(V[pos] + i, mask);
        if ((factoriza&mask) == 0)
            ans = min(ans, dp(pos + 1, factoriza|mask) + i);
	}
	return tabla = ans;
}

void print_dp(int pos, int mask) {
	if (pos == n) return;
	
	for (int i = 0; V[pos] - i >= 1; i++) {
		int factoriza = check(V[pos] - i, mask);
		if ((factoriza&mask) == 0 && 
			(dp(pos + 1, factoriza|mask) + i) == memo[pos][mask]) {
			cout << V[pos] - i << " ";
			print_dp(pos + 1, factoriza|mask);
			return;
		}

        factoriza = check(V[pos] + i, mask);
        if ((factoriza&mask) == 0 && 
            (dp(pos + 1, factoriza|mask) + i) == memo[pos][mask]) {
            cout << V[pos] + i << " ";
            print_dp(pos + 1, factoriza|mask);
            return;
        }
	}
}

int main() {	
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	int caso = 1;
	while (cin >> n && n != 0) {
		for (int i = 0; i < 101; i++)
			for (int j = 0; j < 5000; j++)
				memo[i][j] = -1;
		for (int i = 0; i < n; ++i)	cin >> V[i];
		//cout << dp(0, 0) << "\n";
		cout << "Case #" << caso++ << ": ";
		int ans = dp(0, 0);
		print_dp(0, 0);
		cout << "\n";
	}
	return 0;
}
/*
4
4 8 10 12

*/
