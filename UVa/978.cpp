#include <bits/stdc++.h>
using namespace std;

int main() {
  int casos, green, blue, num, peleas, p, campos;
  multiset <int, greater<int> > G, B;
  vector<int> verdes, azules;

  cin >> casos;
  for (int t = 0;  t < casos; t++) {
    if (t) cout << "\n";
    cin >> campos >> green >> blue;
    G.clear();
    B.clear();

    for (int i = 0; i < green; ++i) {
      cin >> num;
      G.insert(num);
    }
    for (int i = 0; i < blue; ++i) {
      cin >> num;
      B.insert(num);
    }

    while (!G.empty() && !B.empty()) {
      verdes.clear();
      azules.clear();
      peleas = min(campos, (int)min(G.size(), B.size()));
      for (int i = 0; i < peleas; i++) {
        auto tg = G.begin(), tb = B.begin(); 
        int gs = *tg, bs = *tb;
        G.erase(tg);
        B.erase(tb);

        if (gs > bs)
          verdes.push_back(gs-bs);
        else if (bs > gs)
          azules.push_back(bs-gs);
      }
      for (auto i : verdes) G.insert(i);
      for (auto i : azules) B.insert(i);
    }
    if(G.empty() && !B.empty()) {
      cout << "blue wins\n";
      for (auto var : B) 
        cout << var << "\n";      
    } else if (!G.empty() && B.empty()) {
      cout << "green wins\n";
      for (auto var : G) 
        cout << var << "\n";
    } else
      cout << "green and blue died\n";
  }
}
