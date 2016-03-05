#include <iostream>
using namespace std;

int main() {
	long long int n;

	cin >> n;
	(n%2 != 0) ? cout << "0\n" : cout << (n/2 - 1)/2;	
	return 0;
}
