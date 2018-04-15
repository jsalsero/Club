#include <bits/stdc++.h>
using namespace std;

bool cr[1000007];
bool m[1000007];
vector<int> primos;

void criba(int max){

	for (int i=0; i <= max; i++)
		cr[i] = true;

	for (int i=2; i<=max; ++i){
		if(cr[i]){
			primos.push_back(i);
			if(i<=1000)
				for (int j = i*i; j <= max; j+=i)
					cr[j] = false;				
		}
	}
}

void criba_chaqueta( int tam){
    m[0] = false;
    m[1] = false;
    for(int i = 2; i <= tam; ++i) 
        m[i] = true;

    for(int i = 2; i*i <= tam; ++i) {
        if(m[i]) {
        	primos.push_back(i);
            for(int h = 2; i*h <= tam; ++h)
                m[i*h] = false;
        }
    }
}


int main(){
	int a, b, cont=1;
	criba2(1000000);
	while(1){
		scanf("%d %d", &a, &b);
		if(a==0 && b==0)
			return 0;

		map<int,int> M;
		map<int,int> M2;
		vector<int> primero;
		int X=0,res=0;
		
		for (int i=0; i < primos.size(); i++){
			if(a%primos[i]==0 || b%primos[i]==0)
				++X;

			int aux = 0;
			while (a%primos[i] == 0){
				aux++;
				a /= primos[i];
			}

			while (b%primos[i] == 0){
				aux--;
				b /= primos[i];
			}

			res += abs(aux);
		}

		printf("%d. %d:%d\n", cont++, X, res);
	}
	return 0;
}