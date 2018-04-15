#include <bits/stdc++.h>
using namespace std;

struct person{
    string nom;
    int d, m, y;
}A[107];

bool comp(const person &a, const person &b) {
    if (a.y > b.y)
        return true;
    if (a.y < b.y)
        return false;
    if (a.m > b.m)
        return true;
    if (a.m < b.m)
        return false;
    if (a.d > b.d)
        return true;
    return false;
}

int main() {
    int n;

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> A[i].nom >> A[i].d >> A[i].m >> A[i].y;
    sort(A, A + n, comp);
    /*
    cout << endl << endl;
    for (int i = 0; i < n; i++) {
        cout << A[i].nom << "   " << A[i].d << '/' << A[i].m << '/' << A[i].y << endl;
    }
    */
    cout << A[0].nom << "\n" << A[n - 1].nom << "\n";

    return 0;
}
/*
5
Mickey 1 10 1991
Alice 30 12 1990
Tom 15 8 1993
Jerry 18 9 1990
Garfield 20 9 1990


*/