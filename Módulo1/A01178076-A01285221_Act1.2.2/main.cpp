// Oscar Arreola (A01178076) y Alejandra Coeto (A01285221)
// Última modificación: Martes 20 de Agosto
// Programa para calcular la cantidad de monedas que se deben dar como cambio


// Notas de la implementación:

// 1)
// Al seguir un enofque greedy, no está asegurado que el algoritmo llegue a la cantidad con las menos monedas
// posibles. Un caso en donde el algoritmo greedy siempre usa la menor cantidad de monedas
// para este problema es cuando la cantidad de cada moneda puede ser obtenida con monedas menores.
// Por ejemplo, si se tuvieran las monedas: 1, 5, 10, 20, entonces el algoritmo greedy da la solución de menos monedas.

// Sin embargo, con las siguientes monedas no necesariamente: 1, 3, 4;
// Por ejemplo, si se tiene que dar un cambio de 6:
// Greedy: 4, 1, 1
// Con menos monedas(dp): 3, 3

// 2)
// El algoritmo greedy usa dp para evitar visitar cantidades vistas anteriormente
// en el dfs (vector<bool>& visited)

#include "libs.h"

#include <iostream>
#include <vector>
#include <map>
 
using namespace std;


void dfs(int amount, vector<bool>& visited, vector<int> &coins, vector<int> &used){
    // Si ya se dió el cambio o si ya se intentó la cantidad dada, parar la ejecución.
    if (visited[0] || visited[amount])
        return;

    visited[amount] = true;
    
    // Checar qué pasa si usamos todas las monedas. Primero checamos si podemos usar las monedas más grandes, ya que nos acercan más al objetivo (approach greedy)
    for(int i = 0; i < coins.size(); i++){
        if (coins[i] <= amount){
            // Marcamos la moneda como usada.
            used[i]++;
            // Exploramos la posibilidad.
            dfs(amount - coins[i], visited, coins, used);
            // Si ya se dió el cambio, salir
            if (visited[0])
                return;
            // Quitamos la moneda si no se usó
            used[i]--;
        }
    }
}

// Complejidad temporal: O(A * C)
// Complejidad espacial: O(A + M), donde A es la cantidad a regresar y M es el espacio máximo del stack de llamadas recursivas (A / min(coins)).
// Función para obtener la cantidad mínima de monedas que se necesitan dar de cambio
// Recibe las monedas, el precio y la cantidad pagada
// Imprime la cantidad de cada moneda
void coinChange(vector<int>& coins, int amount) {

    // O(NlogN) -> complejidad usando algoritmo de ordenamiento estándar
    sort(coins.rbegin(), coins.rend());
    
    vector<bool> visited(amount+1);

    vector<int> coinsUsed(coins.size());

    bool possible = false;

    dfs(amount, visited, coins, coinsUsed);

    cout << endl;
    
    // O(C), donde C es la cantidad de monedas disponibles
    if (visited[0]) {
        for(int i = 0; i < coins.size(); i++){
            cout << coinsUsed[i] << " moneda(s) de " << coins[i] << ".\n";
        }
    } else {
        cout << "No se puede dar " << amount << " de cambio con las monedas ingresadas." << "\n";
    }

}

// Función principal
int main() { 
    int n,a,p,q;
    vector<int> coins;

    cout << "Ingrese el número de denominaciones de monedas: ";
    cin >> n;
    cout << "Ingrese las denominaciones de las monedas, una por línea: " << endl;

    // Complejidad -> O(N) 
    while (n--) {
        cin >> a;
        coins.push_back(a);
    }

    cout << "Ingrese el precio del producto: ";
    cin >> p;
    cout << "Ingrese la cantidad pagada: ";
    cin >> q;

    if (q-p == 0) {
        cout << "\nNo hay cambio por dar." << endl;
    } else if (q < p) {
        cout << "\nFalta dinero para pagar este producto." << endl;
    } else {
        coinChange(coins, q-p);
    }

    return 0;
}