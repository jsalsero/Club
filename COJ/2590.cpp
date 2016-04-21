// 16 52
#include <bits/stdc++.h>
using namespace std;
typedef long long Long;
int const MOD = 5000000;
struct FenTree {
    vector<Long> tree;
    FenTree(int n) : tree(n + 1) {}
    
    void Actualizar(int i, int v) {
        while (i < tree.size()) {
            tree[i] = (tree[i] + v) % MOD;
            i += i & -i;
        }
    }
    
    Long Query(int i) {
        Long sum = 0;
        while (i > 0) {
            sum = (sum + tree[i]) % MOD;
            i -= i & -i;
        }
        return sum;
    }
};

Long dp[100005][55];
void test() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= K; j++)
			cout << dp[i][j] << " ";
		cout << endl;
	}
}

int main() {
	int N, K, num;
	vector<int> V;

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;

	for (int i = 0; i < N; ++i) {
		cin >> num;
		V.push_back(num);		
		dp[i][1] = 1;
	}

	for (int p = 2; p <= K; ++p) {
		FenTree tree(100005);
		for (int i = 1; i <= N; ++i) {
			tree.Actualizar(V[i - 1], dp[i - 1][p - 1] % MOD);
			dp[i][p] += tree.Query(V[i] - 1) % MOD;
		}
	}

	Long res = 0;
	for (int i = 0; i < N; i++)
		res = (res + dp[i][K]) % MOD;
	cout << res << "\n";
	return 0;
}
/*
10 4
17 11 13 5 2 7 3 19 29 23

*/
