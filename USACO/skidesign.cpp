/*
ID: wizard.1
PROG: skidesign
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int main(){
	int N, num;
	int diferencia, costo, corte;
	vector<int> hills;

	ifstream fin ("skidesign.in");
	ofstream fout ("skidesign.out");

	fin >> N;
	for(int i = 0; i < N; i++){
		fin >> num;
		hills.push_back(num);
	}

	sort(hills.begin(), hills.end());
	for (int i = 0; i < hills.size(); i++)
		fout << hills[i] << endl;

	int res = 0;

	while( (diferencia = hills[ hills.size() - 1 ] - hills[ 0 ]) > 17){
		diferencia -= 17;

		//Creo que esto es la simulación completa, pero da el mismo resultado 
		//que lo de abajo

		costo = INF;
		corte = -1;
		for (int i = 0; i <= diferencia; i++){
			if( costo > i*i + (diferencia - i)*(diferencia - i) ){
				costo = i*i + (diferencia - i)*(diferencia - i);
				corte = i;
			}
		}
		hills[ hills.size() - 1 ] -= (diferencia - corte);
		hills[ 0 ] += corte;
		res += corte*corte + (diferencia - corte)*(diferencia - corte); 
		

		/*
		// Otra solución
		if(diferencia%2 == 0){
			hills[ hills.size() - 1 ] -= (diferencia/2);
			hills[ 0 ] += (diferencia/2);
			res += 2*(diferencia/2)*(diferencia/2);
		} else {
			hills[ hills.size() - 1 ] -= ((diferencia + 1)/2);
			hills[ 0 ] += (diferencia/2);
			res += (diferencia/2)*(diferencia/2) + ((diferencia + 1)/2)*((diferencia + 1)/2);
		}		
		*/

		sort(hills.begin(), hills.end());
		fout << endl <<  "------------------------------" << endl;
		for (int i = 0; i < hills.size(); i++)
			fout << hills[i] << endl;


	}
	fout << "<<<<<<<<<<>>>>>>>>";
	fout << endl << endl << endl << endl;
	fout << res << "\n";
	return 0;
}
/*
5
20
4
1
24
21

*/