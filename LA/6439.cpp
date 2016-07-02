#include <bits/stdc++.h>
using namespace std;
 
string cad; 
unsigned long long L, R, P[50010];//, B = 1947698881ULL;
unsigned long long B = 1000000007ULL;
 
int F(int i, int j){ 
    if (i >= j) return (i == j);
    L = R = 0;
    int r = 1, power = 0;
    while (i < j){
        L = L * B + cad[i];
        R = P[power] * cad[j] + R;
        if (L == R){
            //cout << "\t" << i << " - " << j << endl;
            //cout << "\t" << L << endl;
            r = 2 + F(i + 1, j - 1);
            break;
        }
        i++, power++, j--;
    }
    return r;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 0, t, i;
    P[0] = 1ULL;
    for(i = 1; i < 50007; i++) P[i] = (P[i - 1] * B);
 
    cin >> t;
    while (t--){
        cin >> cad;
        cout << "Case #" << ++T << ": " << F(0, cad.size() - 1) << "\n";
        //printf("Case #%d: %d\n", ++T, F(0, cad.size() - 1));
    }
    return 0;
}
/*
4
PASTIPAS
ABCADDABCA
MADAMIAMADAM
ACMICPCJAKARTASITE

*/
