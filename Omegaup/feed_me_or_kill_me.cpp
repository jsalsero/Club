#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> meal;

int max_meals(int idx, int mask) {
    if (idx == m) return 0;

    int ans = 0;

    //take it
    if (!(mask & meal[idx]))
        ans = max(ans, 1 + max_meals(idx + 1, mask | meal[idx]));

    //leave it
    ans = max(ans, max_meals(idx + 1, mask));

    return ans;
}

int main() {
    cin >> n >> m;
    meal = vector<int>(m);

    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;

        for (int j = 0; j < k; ++j) {
            int ingredient;
            cin >> ingredient;

            meal[i] |= (1 << ingredient);
        }
    }

    cout << max_meals(0, 0) << endl;

    return 0;
}
