#include <bits/stdc++.h>
using namespace std;

int main(){
	int caso=1; char cad[10];

	while( scanf("%s", &cad) ){
		if(cad[0] == '*')
			return 0;
		(cad[0] == 'H') ? printf("Case %d: Hajj-e-Akbar\n", caso++) : printf("Case %d: Hajj-e-Asghar\n", caso++);
	}
	return 0;
}
