/*
ID: wizard.1
PROG: namenum
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	string tel[][3] = {{"A", "B", "C"},
                    {"D", "E", "F"},
                    {"G", "H", "I"},
                    {"J", "K", "L"},
                    {"M", "N", "O"},
                    {"P", "R", "S"},
                    {"T", "U", "V"},
                    {"W", "X", "Y"}};
	string cad;
	set<string> diccio;

	ifstream fin ("namenum.in");
	ofstream fout("namenum.out");

	ifstream fdic("dict.txt");

	while(fdic >> cad)
		diccio.insert(cad);
	
	fin >> cad;
	stack<string> Q;

	int res = 0;
	bool flag = false;

	Q.push( tel[ cad[0] - '2' ][2] );
	Q.push( tel[ cad[0] - '2' ][1] );
	Q.push( tel[ cad[0] - '2' ][0] );
	
	while(!Q.empty()){
		string actual = Q.top();
		Q.pop();		
		if( actual.size() == cad.size() ){
			if( diccio.count(actual) != 0 ){
				fout << actual << "\n";
				flag = true;
			}
		} else {
			Q.push(actual + tel[ cad[actual.size()] - '2' ][2]);
			Q.push(actual + tel[ cad[actual.size()] - '2' ][1]);
			Q.push(actual + tel[ cad[actual.size()] - '2' ][0]);
		}		
	}
	if(!flag) fout << "NONE\n";
	return 0;
}