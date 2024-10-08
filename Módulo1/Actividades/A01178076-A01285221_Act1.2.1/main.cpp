// Oscar Arreola (A01178076) y Alejandra Coeto (A01285221)
// Última modificación: Martes 20 de Agosto
// Programa para calcular la cantidad de monedas que se deben dar como cambio

#include "libs.h"

#include <iostream>
#include <vector>
#include <map>
 
using namespace std;

// Complejidad temporal: O(A * C * C), donde A es el cambio a dar y C la cantidad de monedas.
// Complejidad espacial: O(A * C), donde A es el cambio a dar, y C es la cantidad de monedas.
// Función para obtener la cantidad mínima de monedas que se necesitan dar de cambio
// Recibe las monedas, el precio y la cantidad pagada
// Imprime la cantidad de cada moneda
void coinChange(vector<int>& coins, int amount) {
    vector<map<int,int> > used(amount+1, map<int,int>());
    vector<int> dp(amount+1, INT_MAX);

    // O(NlogN) -> complejidad usando algoritmo de ordenamiento estándar
    sort(coins.rbegin(), coins.rend());

    // O(A), donde A es el dinero por regresar como cambio
    for (int i = 1; i <= amount; i++) {

        // O(C), donde C es la cantidad de monedas disponibles
        for (auto coin : coins) {
            int check = i - coin;
            if (check == 0) {
                dp[i] = 1;
                used[i].clear(); // O(C)
                used[i][coin]++; // O(log(C))
                break;
            }
            else if (check >= 1 && dp[check] != INT_MAX) {
                if (dp[check] + 1 < dp[i]) {
                    dp[i] = dp[check] + 1;
                    used[i] = used[check]; // O(C)
                    used[i][coin]++; // O(log(C))
                }
            }
        }
    }

    cout << endl;

    // O(C), donde C es la cantidad de monedas disponibles
    if (dp[amount] != INT_MAX) {
        for (int coin : coins) {
            cout << used[amount][coin] << " moneda(s) de " << coin << ".\n";
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
        cout << "No hay cambio por dar." << endl;
    } else if (q < p) {
        cout << "Falta dinero para pagar este producto." << endl;
    } else {
        coinChange(coins, q-p);
    }

    return 0;
}