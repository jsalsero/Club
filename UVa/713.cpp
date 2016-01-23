#include <bits/stdc++.h>
using namespace std;

int main() {
	int casos;
	string cad1, cad2;

	cin >> casos;
	for (int i = 0; i < casos; ++i)
	{
		cin >> cad1 >> cad2;
		reverse(cad1.begin(), cad1.end());
		reverse(cad2.begin(), cad2.end());

		 double f = 23.43;
		    std::string f_str = std::to_string(f);
		    std::cout << f_str << '\n';

		//cad1 = std::to_string(atoi(cad1.c_str()) + atoi(cad2.c_str())) + "";
		//reverse(cad1.begin(), cad1.end());
		cout << cad1 << "\n";
	}
	return 0;
}
