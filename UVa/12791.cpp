#include <bits/stdc++.h>
using namespace std;

int i,x,y,lx,ly,contx,conty;
bool flag;

int main()
{
	while(scanf("%d %d",&x,&y) != EOF)
	{
		contx = 0;
		conty = 0;
		lx = 0;
		ly = 0;
		flag = true;
		while(flag)
		{
			contx++;
			contx = contx % x;			
			conty++;
			conty = conty % y;
			if(contx == 0)
				lx++;
			if(conty == 0)
				ly++;			
			if(lx-ly >= 2)
				flag = false;
			if(lx-ly == 1 && contx==0 && conty==0)
				flag = false;			
		}
		printf("%d\n", lx);
	}
	return 0;
}
