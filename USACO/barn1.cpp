#include <bits/stdc++.h>
using namespace std;

int dp(int id, int tablas, int longi){
	//if(id == farm[farm.size() - 1] || )
}

int cantidad;

int prueba(int num){
	if(num == 0)
		return 0;
	cantidad--;
	cout << cantidad << endl;
	return prueba(--num);
}

int main(){
	cantidad = 10;
	prueba(5);
	int m,s,c;
	cin >> m >> s >> c;

	/*
	for(int i = 0; i < c; i++){

	}
	*/
	return 0;
}