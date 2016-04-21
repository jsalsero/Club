#include <bits/stdc++.h>
using namespace std;

#define MAX 1000005

struct Tres {
    int cero, uno, dos;
};

//long long tree[4 * MAX], lazy[4 * MAX], N, M;
Tres tree[4 * MAX];
int lazy[4 * MAX];
int N, M;

void build(int node, int start, int end) {
    if(start == end) {
        // Leaf node will have a single element
        tree[node].cero = 1;
        tree[node].uno = 0;
        tree[node].dos = 0;
    } else {
        int mid = (start + end) / 2;
        // Recurse on the left child
        build(2*node, start, mid);
        // Recurse on the right child
        build(2*node+1, mid+1, end);
        // Internal node will have the sum of both of its children
        tree[node].cero = tree[2*node].cero + tree[2*node+1].cero;
        tree[node].uno = tree[2*node].uno + tree[2*node+1].uno;
        tree[node].dos = tree[2*node].dos + tree[2*node+1].dos;
    }
}

void cambia(int node) {
    int cero = tree[node].cero;
    int uno = tree[node].uno;
    int dos = tree[node].dos;
    tree[node].cero = dos;
    tree[node].uno = cero;
    tree[node].dos = uno;
}

void propagate(int node, int start, int fin) {
    if(lazy[node] != 0) { 
        // This node needs to be updated
        cambia(node);
        if (lazy[node] == 2) cambia(node);

        if(start != fin) {
            lazy[node*2] = (lazy[node*2] + lazy[node]) % 3;                  // Mark child as lazy
            lazy[node*2+1] = (lazy[node*2+1] + lazy[node])% 3;                // Mark child as lazy
        }
        lazy[node] = 0;                                  // Reset it
    }
}

void updateRange(int node, int start, int fin, int l, int r, int val) {
    propagate(node, start, fin);

    if(start > fin or start > r or fin < l)              // Current segment is not within range [l, r]
        return;

    if(start >= l and fin <= r) {
        // Segment is fully within range
        cambia(node);
        if(start != fin) {
            lazy[node*2] = (lazy[node*2] + val) % 3;
            lazy[node*2+1] = (lazy[node*2+1] + val)% 3;
        }
        return;
    }
    int mid = (start + fin) / 2;
    updateRange(node*2, start, mid, l, r, val);        // Updating left child
    updateRange(node*2 + 1, mid + 1, fin, l, r, val);   // Updating right child
    tree[node].cero = tree[node*2].cero + tree[node*2+1].cero;        // Updating root with max value 
    tree[node].uno = tree[node*2].uno + tree[node*2+1].uno;        // Updating root with max value 
    tree[node].dos = tree[node*2].dos + tree[node*2+1].dos;        // Updating root with max value 
}

int queryRange(int node, int start, int fin, int l, int r) {
    if(start > fin or start > r or fin < l)
        return 0;         // Out of range
    
    propagate(node, start, fin);

    if(start >= l and fin <= r)             // Current segment is totally within range [l, r]
        return tree[node].cero;
    int mid = (start + fin) / 2;
    int p1 = queryRange(node*2, start, mid, l, r);         // Query left child
    int p2 = queryRange(node*2 + 1, mid + 1, fin, l, r); // Query right child
    return (p1 + p2);
}

int main() {
    int Q, a, b, c;

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    
    build(1, 0, N - 1);
    /*
    for (int i = 0; i < 2*N - 1; i++)
        cout << tree[i].cero << "  ";
    */

    for (int i = 0; i < Q; ++i) {
        cin >> c >> a >> b;
        if (c == 0)
            updateRange(1, 0, N - 1, a, b, 1);
        else
            //cout << query(1, 0, N - 1, a, b) << "\n";
            cout << queryRange(1, 0, N - 1, a, b) << "\n";
    }
    return 0;
}
/*
4 7
1 0 3
0 1 2
0 1 3
1 0 0
0 0 3
1 3 3
1 0 3 

*/
