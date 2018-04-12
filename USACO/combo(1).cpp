/*
ID: wizard.1
LANG: C++
TASK: combo
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	int john[5], master[5];
	string aux;
	map<string, int> M;

	ifstream fin ("combo.in");
	ofstream fout ("combo.out");

	fin >> N;
	fin >> john[0] >> john[1] >> john[2];
	fin >> master[0] >> master[1] >> master[2];

	if( N < 6){
		fout << N*N*N << "\n";
		return 0;
	}

	for (int pri = -2; pri < 3; pri++){
		for (int seg = -2; seg < 3; seg++){
			for (int ter = -2; ter < 3; ter++){
				aux = "";
				
				if(john[0] + pri <= 0){
					stringstream oss;
					oss << (N + pri + john[0]);
					aux += oss.str();
				} else{
					stringstream oss;
					if( john[0] + pri > N)
						oss << (john[0] + pri)%N;
					else
						oss << (john[0] + pri);
					aux += oss.str();
				}

				if(john[1] + seg <= 0){
					stringstream oss;
					oss << (N + seg + john[1]);
					aux += oss.str();
				} else{
					stringstream oss;
					oss << (john[1] + seg);
					aux += oss.str();
				}
				
				if(john[2] + ter <= 0){
					stringstream oss;
					oss << (N + ter + john[2]);
					aux += oss.str();
				} else{
					stringstream oss;
					oss << (john[2] + ter);
					aux += oss.str();
				}
				M[aux]++;

				aux = "";
				if(master[0] + pri <= 0){
					stringstream oss;
					oss << (N + pri + master[0]);
					aux += oss.str();
				} else{
					stringstream oss;
					oss << (master[0] + pri);
					aux += oss.str();
				}

				if(master[1] + seg <= 0){
					stringstream oss;
					oss << (N + seg + master[1]);
					aux += oss.str();
				} else{
					stringstream oss;
					oss << (master[1] + seg);
					aux += oss.str();
				}

				if(master[2] + ter <= 0){
					stringstream oss;
					oss << (N + ter + master[2]);
					aux += oss.str();
				} else{
					stringstream oss;
					oss << (master[2] + ter);
					aux += oss.str();
				}
				M[aux]++;
			}
		}
	}
	for( auto var : M){
		cout << "-" << var.first << endl;
	}
	fout << M.size() << "\n";
	return 0;
}