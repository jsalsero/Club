#include <bits/stdc++.h>
using namespace std;

string cad, pal;
bool solve(){
  stringstream ss(cad);
  char ini = 0;
  while(ss >> pal){
    if(ini == 0)
      ini = tolower(pal[0]);
    if(ini != tolower(pal[0]))
      return false;
  }
  return true;
}
int main() {
  while(getline(cin , cad), cad[0] != '*')
    puts(solve()?"Y":"N");
  return 0;
}