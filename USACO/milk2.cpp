/*
ID: wizard.1
PROG: milk2
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int N, a, b;
int inicio, final, milked, no_milked, maxi, mini;
int arre[1000007];

int main() {
	ifstream fin ("milk2.in");
    ofstream fout ("milk2.out");

    mini = 5000000;
    maxi = -1;
    fin >> N;

    for(int i=0; i<N; i++){
        fin >> a >> b;
        if(a<mini)
        	mini = a;
        if(b>maxi)
        	maxi = b;
        for(int cont=a; cont<b; cont++)
        	arre[cont] = 1;
    }

    for(int i=mini; i<=maxi; i++){
    	if(i!=mini)
    		i--;
    	
    	inicio = i;
    	while(arre[i]==1 && i<=maxi)
    		i++;
    	final = i;

    	if(milked < (final - inicio) )
    		milked = final - inicio;

    	if(i<maxi){
	    	inicio = i;
	    	while(arre[i]==0 && i<=maxi)
	    		i++;
	    	final = i;

	    	if(no_milked < (final - inicio) )
	    		no_milked = final - inicio;
    	}
    }
    fout << milked << " " << no_milked << "\n";
    return 0;
}
/*
3
300 1000
700 1200
1500 2100

*/
