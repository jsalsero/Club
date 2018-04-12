#include <bits/stdc++.h>
using namespace std;
#define MOD 100000000

//vector< pair<int,int> > V;
pair<int,int> V[107];
int M,N, s,f;
int memo[107][107];

int dp(int id, int previo) {
	if(V[id].second == M)
		return 1;

	int &res = memo[id][previo];

	if(res == -1){
		res = 0;
		for(int j = id + 1; j < N; ++j) {
			// Puedes tomar si no hay hueco y se cumple que al quitar la actividad quede
			// un hueco
			if( V[j].first > V[id].first && V[j].first <= V[id].second && V[j].second > V[id].second && (id == previo || V[j].first > V[previo].second)) {
				res += dp(j, id);
				if (res >= MOD)
					res -= MOD;
			}
		}
	}
	return res;
}

int main() {	
	int res;
	while(true) {
		scanf("%d %d", &M, &N);
		if(M == 0 && N == 0)
			return 0;
		//V.clear();

		/*
		for(int i = 0; i < 105; i++) {
			for(int j = 0; j < 105; j++) {
				memo[i][j] = -1;
			}
		}
		*/
		memset(memo, -1, sizeof memo);

		for(int i = 0; i < N; i++) {
			//cin >> s >> f;
			//V[i] = make_pair(s,f);
			scanf("%d %d", &V[i].first, &V[i].second);
			//V.push_back( make_pair(s,f) );
		}
		sort(V, V + N);

		res = 0;
		for(int i = 0; i < N; i++) {
			if(V[i].first == 0) {
				res += dp(i,i);
				if (res >= MOD)
					res -= MOD;	
			}
			//cout << V[i].first << "   " << V[i].second << endl;
		}
		printf("%d\n", res);
		//cout << res << "\n";		
	}
	return 0;
}
/*
8 7
0 3
2 5
5 8
1 3
3 6
4 6
0 2
1 1
0 1
2 1
0 1
0 0

*/