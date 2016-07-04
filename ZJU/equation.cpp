#include <bits/stdc++.h>
using namespace std;
typedef long long Long;

Long x, y, d;
void extendedEuclid(Long a, Long b) {
    if (b == 0) { x = 1; y = 0; d = a; return; } 
    extendedEuclid(b, a % b); 
    Long x1 = y;
    Long y1 = x - (a / b) * y;
    x = x1;
    y = y1;
}

int main() {
    Long a, b, c, x1, x2, y1, y2;

    cin >> a >> b >> c;
    c = -c;
    cin >> x1 >> x2;
    cin >> y1 >> y2;

    extendedEuclid(a, b);
    Long gcd = d;
    Long ans = 0;

    if (gcd == 0)
        ans = c ? 0 : (x2 - x1 + 1) * (y2 - y1 + 1);
    else if (c % d == 0) {
        double lx, rx, ly, ry, l, r;
        x = c / d * x, y = c / d * y;
        if (a == 0)
            ans = (x2 - x1 + 1) * (y1 <= y && y <= y2);
        else if (b == 0)
            ans = (y2 - y1 + 1) * (x1 <= x && x <= x2);
        else {
            lx = 1.0 * (x1 - x) * gcd / b;
            rx = 1.0 * (x2 - x) * gcd / b;
            if (lx > rx) swap(lx, rx);

            ly = 1.0 * (y - y1) * gcd /a;
            ry = 1.0 * (y - y2) * gcd /a;
            if (ly > ry) swap(ly, ry);
            
            l = ceil(max(lx, ly));
            r = floor(min(rx, ry));
            ans = max(0.0, r - l + 1);
        }
    }
    cout << ans << "\n";
    return 0;
}
/*
1 1 -3
0 4
0 4

*/
