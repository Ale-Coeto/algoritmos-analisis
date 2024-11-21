// Oscar Arreola (A01178076) y Alejandra Coeto (A01285221)
// Última modificación: Jueves 21 de noviembre
// Programa para resolver el problema: Tipos de gorras en un conjunto de personas.

#include "libs.h"
#define pb push_back 
using namespace std;
typedef vector<int> vi;
typedef uint64_t int64;

// Función para agregar un elemento a la máscara
int64_t add(int64_t mask, int pos) {
    return (mask | (1LL << pos));
}

// Función para eliminar un elemento a la máscara
int64_t remove(int64_t mask, int pos) {
    return (mask & ~(1LL << pos));
}

// Función para checar si existe un elemento en la máscara
bool exists(int64_t mask, int pos) {
    return ((mask & (1LL << pos)) != 0); 
}

/*
    Backtracking algorithm to test each cap for each person and use a 
    bitmask to keep track of used caps
    Complejidad: O(m^n) donde m = cantidad de gorras por persona y n = número de personas
*/
void bt(vector<vi> & hats, int & n, int curr, int & ans, int64 & mask) {
    if (curr == n) {
        ans++;
        return;
    }

    for (int j = 0; j < hats[curr].size(); j++) {
        if (!exists(mask, hats[curr][j])) {
            mask = add(mask, hats[curr][j]);
            bt(hats, n, curr+1, ans, mask);
            mask = remove(mask, hats[curr][j]);
        }
    }
    
}

/*
    Función main para leer el input e imprimir el numero total de 
    arreglos en las que las personas pueden usar gorras sin repetir
*/
int main() {
    int n,a;
    string line;

    getline(cin, line);
    n = stoi(line);
    vector<vi> hats(n+1);

    for (int i = 0; i < n; i++) {
        getline(cin, line);
        istringstream iss(line);
        while (iss >> a) {
            hats[i].pb(a);
        }
    }

    int ans = 0;
    int64 mask = 0;
    bt(hats, n, 0, ans, mask);
    cout << ans;

    return 0;
}