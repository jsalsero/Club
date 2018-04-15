#include <bits/stdc++.h>
using namespace std;

typedef int Arista;
typedef vector<Arista> Nodo;
typedef pair<int,int> AristaPeso;
typedef vector<AristaPeso> NodoPeso;

const int INF = 1 << 30;
const int MAXN = 107;
const int MAXQ = 1002;

Nodo grafo[MAXN];
NodoPeso grafo_peso[MAXN];
int in_degree[MAXN];

void AgregarAristaPeso(int u, int v, int peso);
vector<int> DijkstraPesos(int o, int n);

int ciudad;
string preguntas[MAXQ];
map<string,int> ciudades;

int main(){
    int caso = 1;
    while(true){
        int n, querys, aristas;
        cin >> n >> querys >> aristas;
        if(n == 0 && querys == 0 && aristas == 0) 
            return 0;
        
        ciudades.clear();
        for(int i=0; i < MAXN; i++)
            grafo_peso[i].clear();
        ciudad = 0;

        for(int i = 0; i < querys + 1; i++)
            cin >> preguntas[i];

        for(int i = 0; i < aristas; i++){
            int u,v;

            string home, peso, destiny;
            cin >> home >> peso >> destiny;

            if(ciudades.find(home) == ciudades.end()){
                ciudades[home] = ciudad;
                ciudad++;
            } 

            if(ciudades.find(destiny) == ciudades.end()){
                ciudades[destiny] = ciudad;
                ciudad++;
            }

            u = ciudades[home];
            v = ciudades[destiny];

            int cost = atoi(peso.substr(2,peso.size() - 3).c_str());

            if(peso[0] == '<')
                AgregarAristaPeso(v,u,cost);
            if(peso[peso.size() - 1] == '>')
                AgregarAristaPeso(u,v,cost);
        }

        int sum = 0;
        int home = ciudades[preguntas[0]];
        vector<int> mapa = DijkstraPesos(home,n);
        for(int i = 1; i <= querys; i++){
            int destiny = ciudades[preguntas[i]];
            sum += mapa[destiny];
            vector<int> mapa2 = DijkstraPesos(destiny,n);
            sum += mapa2[home];
        }

        cout << caso << ". " << sum << "\n";
        caso++;
    }
    return 0;
}

void AgregarAristaPeso(int u, int v, int peso){
    grafo_peso[u].push_back(AristaPeso(peso, v));
    ++in_degree[v];
}

vector<int> DijkstraPesos(int o, int n){
    vector<int> dist(n,INF);
    priority_queue<AristaPeso,
                    vector<AristaPeso>,
                    greater<AristaPeso> > pq;
    pq.push(AristaPeso(0,o)); dist[o] = 0;

    while (!pq.empty()){
        int d = pq.top().first; 
        int u = pq.top().second;
        pq.pop();
        if (dist[u] < d) continue;
        for (int i=0; i < grafo_peso[u].size(); ++i){
            int peso_actual = grafo_peso[u][i].first;
            int v = grafo_peso[u][i].second;
            if (dist[u] + peso_actual < dist[v]){
                dist[v] = dist[u] + peso_actual;
                pq.push(AristaPeso(dist[v], v));                
            }
        }
    }
    return dist;
}


/*
4 2 5
NewTroy Midvale Metrodale
NewTroy   <-20-> Midvale
Midvale   --50-> Bakerline
NewTroy    <-5-- Bakerline
Metrodale <-30-> NewTroy
Metrodale  --5-> Bakerline
0 0 0



*/