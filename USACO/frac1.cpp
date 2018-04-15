/*
ID: wizard.1
PROG: frac1
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

struct Frac{
	int num, den;

	Frac(): num(), den() {}
	Frac(int Num, int Den) : num(Num), den(Den) {}

	bool operator<(const Frac& cmp) const {
		return ( cmp.num*den - cmp.den*num > 0 ) ? true : false;
	}
};

int main() {
	map<Frac, int> M;
	int N;

	ifstream fin("frac1.in");
	ofstream fout("frac1.out");

	fin >> N;
	for(int num = 0; num <= N; num++) {
		for(int den = 1; den <= N; den++) {
			if(num/(double)den <= 1.0) {
				M[ Frac(num, den) ]++;
			}
		}
	}
	for( auto var : M )
		fout << var.first.num << '/' << var.first.den << "\n";
	return 0;
}