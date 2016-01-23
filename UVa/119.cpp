/*
ID: wizard.1
PROG: gift1
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, varo, amigos, i, j, regalo;    
    string cad, santa, people[13];
    bool flag = false;

    while (cin >> N) {
        if (flag)
            cout << "\n";
        flag = true;

        map<string, pair<int,int> > M;
        for(i=0; i<N; i++){
            cin >> people[i];
            M[people[i]] = make_pair(0,0);
        }
        for(i=0; i<N; i++){
            cin >> santa;
            cin >> varo >> amigos;
            if(amigos){
                M[santa].first = varo;
                regalo = varo/amigos;                        
                for(j=0; j<amigos; j++){
                    cin >> cad;
                    if((varo - regalo) >= 0){
                        M[cad].second += regalo;
                        varo -= regalo;
                    }
                }
                M[santa].first -= varo;
            }    
        }
        for(i=0; i<N; i++)
            cout << people[i] << " " << M[ people[i] ].second - M[ people[i] ].first << "\n";
    }
    return 0;
}
