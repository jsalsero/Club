#include <bits/stdc++.h>
using namespace std;

int N, B, H, W, dinero, c, total;

int main(){
	while(scanf("%d %d %d %d", &N, &B, &H, &W)){
		total = 0;
		for(int i = 0; i<H; i++){
			scanf("%d", &dinero);
			for(int i = 0; i < W; i++){
				scanf("%d", &c);
				if(c >= N && N*dinero <= B)
					if(total==0 || N*dinero < total)
						total = N*dinero;									
			}
		}
		printf(total == 0? "stay home\n" : "%d\n", total);
	}
} 	
/*
3 1000 2 3
200
0 2 2
300
27 3 20
5 2000 2 4
300
4 3 0 4
450
7 8 0 13
*/
