/*
ID: wizard.1
PROG: sort3
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,uno,dos,tres,num;
	int a_2, a_3, b_1, b_3, c_1, c_2;
	int a[1007];
	int i;

	ifstream fin ("sort3.in");
	ofstream fout ("sort3.out");

	fin >> n;
	uno = dos = tres = 0;

	for(i = 0; i < n; ++i) {
		fin >> a[i];

		if(a[i] == 1)
			uno++;
		else if(a[i] == 2)
			dos++;
		else
			tres++;		
	}

	i = 0;
	a_2 = a_3 = b_1 = b_3 = c_1 = c_2 = 0;

	for(; i < uno; ++i) {
		if(a[i] == 2)
			a_2++;
		else if(a[i] == 3)
			a_3++;
	}
	for(; i < uno + dos; ++i) {
		if(a[i] == 1)
			b_1++;
		else if(a[i] == 3)
			b_3++;
	}
	for(; i < uno + dos + tres; ++i) {
		if(a[i] == 1)
			c_1++;
		else if(a[i] == 2)
			c_2++;
	}

	int swap = 0;
	while(a_2 > 0 && b_1 > 0) {
		a_2--;
		b_1--;
		swap++;
	}
	while(a_3 > 0 && c_1 > 0) {
		a_3--;
		c_1--;
		swap++;
	}
	while(b_3 > 0 && c_2 > 0) {
		b_3--;
		c_2--;
		swap++;
	}

//	cout << a_2 << endl << b_1 << endl << a_3 << endl << c_1 << endl << b_3 << endl << c_2 << endl;
	int sobras = max(0, a_2);
	sobras = max(sobras, b_1);
	sobras = max(sobras, a_3);
	sobras = max(sobras, c_1);
	sobras = max(sobras, b_3);
	sobras = max(sobras, c_2);

	fout << swap + sobras*2 << "\n";
	return 0;
}