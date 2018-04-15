/*
ID: wizard.1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

map<char, int> m;

int main() {
	int res = 1, res2=1, i;
	ifstream fin ("ride.in");
    ofstream fout ("ride.out");    
    char[50] a;
    char[50] b;
    fin >> a >> b;
    for(i=0 ; i<strlen(a) ; i++)
    	res = res*(a[i]-'A'+1);
    for(i=0 ; i<strlen(b) ; i++)
    	res2 = res2*(b[i]-'A'+1);
    if(res == res2)
    	fout << "GO" << endl;
    else
    	fout << "STAY" << endl;
    return 0;
}