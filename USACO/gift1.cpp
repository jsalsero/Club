/*
ID: wizard.1
PROG: gift1
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

map<string, pair<int,int> > M;
int main() {
    int N, varo, amigos, i, j, regalo;
    string cad, santa, people[13];

	ifstream fin("gift1.in");
    ofstream fout("gift1.out");    

    fin >> N;
    for(i=0; i<N; i++){
        fin >> people[i];
        M[people[i]] = make_pair(0,0);
    }
    for(i=0; i<N; i++){
        fin >> santa;
        fin >> varo >> amigos;
        M[santa].first = varo;
        if(amigos){
            regalo = varo/amigos;        
            if(!regalo)
                regalo = 1;
            for(j=0; j<amigos; j++){
                fin >> cad;
                if((varo - regalo) >= 0){
                    M[cad].second += regalo;
                    varo -= regalo;
                }
            }
            M[santa].first -= varo;
        }    
    }
    for(i=0; i<N; i++)
        fout << people[i] << " " << M[ people[i] ].second - M[ people[i] ].first << "\n";
    return 0;
}