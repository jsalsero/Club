#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int ,int> ii;
typedef vector< ii > vii;

typedef long long int li;
typedef vector<li> vl;
typedef pair<li,li> ll;




vi primes;

void sieve_primes(int n){
	primes.clear();
	vi nums(n,1);
	nums[0]=nums[1]=0;
	int top=ceil(sqrt(n));
	for(int i=2;i<top;i++)
		if(nums[i]==1)
			for(int j=i;i*j<n;j++)
				nums[i*j]=0;
	for(int i=0;i<n;i++)
		if(nums[i]==1)
			primes.push_back(i);
}


void prime_fact(li n, map<int,int> &pf){
	pf.clear();
	for(int p: primes){
		if( (li)(p*p) >n ) break;
		while(n%p==0){
			n/=p;
			pf[p]++;
		}
	}
	if(n!=1) pf[n]=1;
}


int repetitions(li p, li n){
	int top= log(n) / log(p) ;
	//cout << top << "\n";
	int res=0;
	for(int i=1;i<=top;i++){
		//cout << n/((int)pow((double)p,(double)i)) << " , ";
		//cout << "\n";
		res+= n/((int)pow((double)p,(double)i));
	}
	//cout << n << "\n";
	return res;
}


int main(){
	
	li n,m;
	sieve_primes(1000000);
	while(scanf("%lld %lld",&n,&m)==2){
		//cout << n <<  " " << m << "\n";
		
		map<int,int> fm;
		prime_fact(m,fm);
		int flag=0;
		for(auto it:fm){
			int s=repetitions(it.first,n);
			//cout << it.first << "\n";
			if(it.second > s){
				flag=1;
				break;
			}
		}
		if(flag==1){
			cout << m << " does not divide " << n << "!\n";
			
		}
		else{
			cout << m << " divides " << n << "!\n";
		}
	}
	return 0;
}
