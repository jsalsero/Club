#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define forn(i, n) for (int i = 0; i < n; ++i)
#define rep(a, b, n) for (int i = a; i < b; ++i)
#define endl '\n'
#define pii pair<int, int>
#define Long long long
#define fi first
#define se secon
using namespace std;

const int MAXN = 100 * 1000 + 7;

char grid[66][66];
string data[6];

bool ins_hor(int idx, int x, int y) {
    forn(i, data[idx].size()) {
        if (grid[x][y + i] == '.')
            grid[x][y + i] = data[idx][i];
        
        if (grid[x][y + i] != data[idx][i])
            return false;
    }

    return true;
}

bool ins_ver(int idx, int x, int y) {
    forn(i, data[idx].size()) {
        if (grid[x + i][y] == '.')
            grid[x + i][y] = data[idx][i];

        if (grid[x + i][y] != data[idx][i])
            return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string ans(200, 'a');

    forn(i, 6) cin >> data[i];
    sort(data, data + 6);

    do {
        bool valid = true;

        int hor = data[2].size();
        int ver = data[3].size();

        valid &= (data[0].size() + data[4].size() - 1 == ver);
        valid &= (data[1].size() + data[5].size() - 1 == hor);

        if (!valid) continue;

        forn(i, hor)
            forn(j, ver)
                grid[i][j] = '.';

        valid &= ins_hor(0,                  0, 0);
        valid &= ins_hor(3, data[1].size() - 1, 0);
        valid &= ins_hor(4, data[2].size() - 1, data[0].size() - 1);
        
        valid &= ins_ver(1,                  0, 0);
        valid &= ins_ver(2,                  0, data[0].size() - 1);
        valid &= ins_ver(5, data[1].size() - 1, data[3].size() - 1);

        if (valid) {
            string temp;

            forn(i, hor) {
                forn(j, ver) temp += grid[i][j];
                temp += '\n';
            }

            ans = min(ans, temp);
        }
    } while (next_permutation(data, data + 6));

    cout << (ans.size() == 200? "Impossible\n": ans);
    return 0;
}

