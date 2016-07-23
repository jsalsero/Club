#include <bits/stdc++.h>
using namespace std;
#define RESTA pre[V[pos] - i]
#define SUMA  pre[V[pos] + i]

vector<int> primos = {2,3,5,7,11,13,17,19,23,29,31,37};
vector<int> pre = {0,0,1,2,1,4,3,8,1,2,5,16,3,32,9,6,1,64,3,128,5,10,17,256,3,4,33,2,9,512,7,1024,1,18,65,12,3,2048,129,34};

int n;
vector<int> V(101);
int memo[101][4100];
int dp(int pos, int mask) {
    if (pos == n)   return 0;
    int &tabla = memo[pos][mask];
    if (tabla != -1) tabla;
    int ans = 1<<30;
    
    for (int i = 0; V[pos] - i >= 1; i++) { 
        if ((RESTA&mask) == 0)
            ans = min(ans, dp(pos + 1, RESTA|mask) + i);        
        if ((SUMA&mask) == 0)
            ans = min(ans, dp(pos + 1, SUMA|mask)  + i);
    }
    return tabla = ans;
}

void print_dp(int pos, int mask) {
    if (pos == n) return;
    
    for (int i = 0; V[pos] - i >= 1; i++) {
        if ((RESTA&mask) == 0 && 
            (dp(pos + 1, RESTA|mask) + i) == memo[pos][mask]) {
            cout << V[pos] - i << " ";
            print_dp(pos + 1, RESTA|mask);
            return;
        }

        if ((SUMA&mask) == 0 && 
            (dp(pos + 1, SUMA|mask) + i) == memo[pos][mask]) {
            cout << V[pos] + i << " ";
            print_dp(pos + 1, SUMA|mask);
            return;
        }
    }
}

void init() {
    for (int i = 0; i < 101; i++)
        for (int j = 0; j < 4100; j++)
            memo[i][j] = -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    int caso = 1;
    while (cin >> n && n != 0) {
        init();
        for (int i = 0; i < n; ++i) cin >> V[i];
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
