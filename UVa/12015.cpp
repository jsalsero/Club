#include <bits/stdc++.h>
using namespace std;

int main(){
	int T, v, maxi, c=1;
	string cad[13];
	map<string,int> M;

	cin >> T;	
	for(int i=0; i<T; i++){
		maxi = -1;
		for(int j=0; j<10; j++){
			cin >> cad[j] >> v;
			M[ cad[j] ] = v;
			if(v>maxi)
				maxi = v;
		}		

		cout << "Case #" << c++ << ":\n";
		for(int j=0; j<10; j++){
			if(M[ cad[j] ] == maxi)
				cout << cad[j] << "\n";
		}
	}
	
	return 0;
}
/*
2
www.youtube.com 1
www.google.com 2
www.google.com.hk 3
www.alibaba.com 10
www.taobao.com 5
www.bad.com 10
www.good.com 7
www.fudan.edu.cn 8
www.university.edu.cn 9
acm.university.edu.cn 10
www.youtube.com 1
www.google.com 2
www.google.com.hk 3
www.alibaba.com 11
www.taobao.com 5
www.bad.com 10
www.good.com 7
www.fudan.edu.cn 8
acm.university.edu.cn 9
acm.university.edu.cn 10

*/
