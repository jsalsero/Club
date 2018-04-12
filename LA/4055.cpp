#include <bits/stdc++.h>
using namespace std;
#define ld long double

int main(){
	ld s,b;
	double nuevo;
	int caso=1, signo;
	while(true){
		cin >> b >> s;
		if(b==0 && s==0)
			return 0;

		if(b==1){
			cout << "Case " << caso << ": :-\\\n";
		} else if(s >= b){
			cout << "Case " << caso << ": :-|\n";
		} else if(s < b){
			nuevo  = (b - s)/(b * (b - 1));
			if( nuevo > 0 )
				cout << "Case " << caso << ": :-(\n";
			else 
				cout << "Case " << caso << ": :-)\n";
		}
		caso++;
	}
	return 0;
}