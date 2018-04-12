/*
ID: wizard.1
PROG: transform
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int N, i, j;


int uno(char m1[10][10], char m2[10][10]){
	for(i=0; i<N; i++)
    	for(j=0; j<N; j++)
    		if( m1[i][j] != m2[j][N-1-i] )
    			return 1;
   	return 0;
}

int dos(char m1[10][10], char m2[10][10]){
	for(i=0; i<N; i++)
    	for(j=0; j<N; j++)
    		if( m1[i][j] != m2[N-1-i][N-1-j] )
    			return 1;
   	return 0;
}

int tres(char m1[10][10], char m2[10][10]){
	for(i=0; i<N; i++)
    	for(j=0; j<N; j++)
    		if( m1[i][j] != m2[N-1-j][i] )
    			return 1;
   	return 0;
}

int cuatro(char m1[10][10], char m2[10][10]){
	for(i=0; i<N; i++)
    	for(j=0; j<N; j++)
    		if( m1[i][j] != m2[i][N-1-j] )
    			return 1;
   	return 0;
}

int cinco(char m1[10][10], char m2[10][10]){
	char aux[10][10];
	for(i=0; i<N; i++)
    	for(j=0; j<N; j++)
    		aux[i][N-1-j] = m1[i][j];

    for(i=0; i<N; i++){
    	for(j=0; j<N; j++){
    		cout << aux[i][j];
    	}
    	cout << endl;
    }

    if(uno(aux, m2) || dos(aux, m2) || tres(aux, m2))
    	return 1;

   	return 0;
}

int seis(char m1[10][10], char m2[10][10]){
	for(i=0; i<N; i++)
    	for(j=0; j<N; j++)
    		if( m1[i][j] != m2[i][j] )
    			return 1;
   	return 0;
}

int main() {
	ifstream fin ("transform.in");
    ofstream fout ("transform.out");

    fin >> N;

    char m1[10][10];
    char m2[10][10];

    for(i=0; i<N; i++)
    	for(j=0; j<N; j++)
    		fin >> m1[i][j];

    for(i=0; i<N; i++)
    	for(j=0; j<N; j++)
    		fin >> m2[i][j];

    if(!uno(m1, m2)){	fout << "1\n";	} 
    else if(!dos(m1, m2)){	fout << "2\n";	} 
    else if(!tres(m1, m2)){	fout << "3\n";	}
    else if(!cuatro(m1, m2)){	fout << "4\n";	}
    else if(!cinco(m1, m2)){	fout << "5\n";	} 
    else if(!seis(m1, m2)){	fout << "6\n";  } 
    else	
    	fout << "7\n";

    return 0;
}
/*


*/
