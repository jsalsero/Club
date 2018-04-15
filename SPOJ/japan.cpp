/*
Explicación

El BIT actualiza sumando NO REEMPLAZANDO. That's all folks.

*/

#include <bits/stdc++.h>
#define MAX 100008
#define lld long long int
using namespace std;

lld BIT[MAX];
lld T, N, M, K, a, b, cont, resp;
lld datos[MAX];
//pair<lld, lld> caminos[MAX];
vector< pair<lld, lld> > caminos;

int getSum(lld index)
{
    lld sum = 0; //  
 
    // Traverse ancestors of BIT[index]
    while (index>0)
    {
        // Add current element of BIT to sum
        sum += BIT[index];
        // Move index to parent node
        index -= index & (-index);
    }
    return sum;
}
 
// Updates a node in Binary Index Tree (BIT) at given index
// in BIT.  The given value 'val' is added to BIT[i] and
// all of its ancestors in tree.
void actualizaBIT(lld index, lld val)
{
    // index in BIT[] is 1 more than the index in arr[]
    //index = index + 1;
 
    // Traverse all ancestors and add 'val'
    while (index <= M)
    {
       // Add 'val' to current node of BI Tree
       BIT[index] += val;
 
       // Update index to that of parent
       index += index & (-index);
    }
}

int main()
{      
    
    scanf("%lld",&T);
    int casos = 0;
    while( casos++<T ){       

        scanf("%lld %lld %lld", &N, &M, &K);       

        int cont = 0;
        caminos.clear();
        while( cont<K ){
            scanf("%lld %lld", &a, &b);
            pair<lld,lld> aux;
            aux.first = a;
            aux.second = b;
            caminos.push_back(aux);
            cont++;      
        }

        sort(caminos.begin(), caminos.end()); // Los ordena comparando el valor .first del pair

        // Inicializar el BIT
        for (int i=0; i<=M; i++)
            BIT[i] = 0;

        for( cont = 0 ; cont<=M ; cont++) // inicializamos los datos en cero
            datos[cont] = 0;
        
        for( cont = 0 ; cont<K ; cont++ ){ // vamos a hacer el bit usando el arreglo datos
            datos[ caminos[cont].second ]++;            
        }
        
        for( cont = 1 ; cont<=M ; cont++ ){ // corremos el bit            
            actualizaBIT(cont, datos[cont]);
        }

        resp = 0;
        for( cont = 0 ; cont<K ; cont++ ){
            resp += getSum( caminos[cont].second-1 ); // Contamos desde la linea anterior            
            actualizaBIT(caminos[cont].second, -1);
        }
        printf("Test case %d: %lld\n", casos, resp);        
    }
    return 0;
}
/*
Input :
7
3 4 4 
1 4 
2 3 
3 2 
3 1 
3 4 4
1 1
1 2
1 3
1 4
3 4 4 
1 4 
2 3 
3 2 
3 1 
3 4 4
1 1
1 2
1 3
1 4
4 4 6
3 3
2 2
4 4
1 1
1 4
4 2
4 4 6
3 3
2 2
4 4
1 1
1 4
4 2
2 4 6
1 1
1 2
1 3
1 4
1 5
1 6
Ouput: 
Test case 1: 5
Test case 2: 0
*/