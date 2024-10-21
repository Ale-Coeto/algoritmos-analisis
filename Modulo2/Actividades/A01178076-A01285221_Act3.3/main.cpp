// Oscar Arreola (A01178076) y Alejandra Coeto (A01285221)
// Última modificación: Domingo 20 de Octubre
// Programa para probar el algoritmo 0/1 knapsack

#include "libs.h"
 
using namespace std;
typedef vector<int> vi;
#define pb push_back

/*
    Algoritmo Knapsack para encontrar el valor más alto que se puede conseguir al
    seleccionar elementos con cierto valor y peso en una mochila de capacidad limitada
    Params: cantidad de objetos (int), capacidad de la mochila(int), pesos(vector), valores(vector)
    Returns: valor óptimo (int)

    Complejidad temporal: O(n*w), donde n es la cantidad de nodos
*/
int knapsack(int & n, int & w, vi & weights, vi & values) {
    vector<vi> dp(n+1, vi(w+1));

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (j < weights[i]) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weights[i]] + values[i]);
            }
        }
    }

    return dp[n][w];
}

/*
    Main
    Lee cantidad de objetos, pesos, valores y capacidad
    LLama knapsack e imprime el resultado
*/
int main() { 
    int n,a,w;
    cin >> n;
    vi weights(n+1,0);
    vi values(n+1,0);

    for (int i = 1; i <= n; i++) {
        cin >> a;
        values[i] = a;
    }

    for (int i = 1; i <= n; i++) {
        cin >> a;
        weights[i] = a;
    }

    cin >> w;


    cout << knapsack(n,w,weights,values) << endl;
    return 0;
}