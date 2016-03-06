#include <iostream>
#include <vector>
using namespace std;
#define MAX 100

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;
	if (n < 3) {
		cout << "0 0 " << n << "\n";	
	} else {
		vector<long long int> F;
		F.assign(100, 0);
		F[0] = 0;
		F[1] = 1;
		for (int i = 2; i <= 50; ++i) 
			F[i] = F[i-1] + F[i-2];
		int index = lower_bound(F.begin(), F.end(), n) - F.begin();	
		cout << F[ index - 1 ] << ' ' << F[index - 2] << " 0\n";
	}
	return 0;
}
