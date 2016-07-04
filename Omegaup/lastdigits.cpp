#include <bits/stdc++.h>
#define lld long long int
#define MOD 10
#define MAX 1000007
using namespace std;

bool m[MAX];
vector<lld> primes;

void criba(){
	for (lld i = 3; i < MAX; i += 2)
		m[i] = true;
	m[2] = true;
	for (lld i = 3; i * i < MAX; i += 2)
		if (m[i])
			for (lld j = i * i; j < MAX; j += i)
				m[j] = false;
	primes.push_back(2);
	for (lld i = 3; i < MAX; i++)
		if (m[i])
			primes.push_back(i);
}

vector<lld> barrido(string s){
	vector<lld> cu;
	char c = s[0];
	lld cont = 1;
	for (lld i = 1; i < s.size(); i++){
		if (c == s[i]){
			cont++;
		}else{
			c = s[i];
			cu.push_back(cont);
			cont = 1;
		}
	}
	if (cont >= 1)
		cu.push_back(cont);
	return cu;
}

lld power(lld a, lld n){
	lld ret = 1;
	while (n > 0){
		if (n % 2 == 1) ret = (ret * a) % MOD;
		a = (a * a) % MOD;
		n /= 2;
	}
	return ret % MOD;
}

lld get_powers(lld n, lld p){
    lld res = 0;
    while (n > 0){
    	res += n/p;
    	n /= p;
    }
    return res;
}

vector<lld> ans;
void llenar(lld n, lld sign){
	for (lld i = 0; primes[i] <= n; i++)
		ans[primes[i]] += sign * get_powers(n, primes[i]);
}

void imprimir(lld n){
	for (lld i = 0; i <= n; i++){
		cout << ans[i] << " ";
	}
	cout << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	criba();
	lld N;
	string s;

	cin >> N;
	while (N--){
		cin >> s;
		ans.assign(s.size() + 1, 0);
		sort(s.begin(), s.end());

		vector<lld> c = barrido(s);
		llenar(s.size(), 1);

		for (lld i = 0; i < c.size(); i++){
			llenar(c[i], -1);
		}
		if (s.size() >= 5){
			int mini = min(ans[2], ans[5]);
			ans[2] -= mini;
			ans[5] -= mini;
		}

		lld ret = 1;
		for (lld i = 0; primes[i] <= s.size(); i++)
			ret = (ret * power(primes[i], ans[primes[i]])) % MOD;
		cout << ret << "\n";
	}
	return 0;
}
/*
4  
 aaba   
 aaabababababa   
 abbzazzazzalzalzzaaaaazlalzaazlalzla   
 w
*/
