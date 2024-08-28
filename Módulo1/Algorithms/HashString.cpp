// Oscar Arreola (A01178076) y Alejandra Coeto (A01285221)
// Última modificación: Martes 27 de Agosto
// Programa para probar la implementación del algoritmo HashString

#include "libs.h"
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
#define pb push_back

// Función para obtener el valor hash de un string
// Recibe un string
// Retorna el valor hash (long long)
ll hashString(string s) {
    int n = s.length();
    int p = 31;
    int m = 1e9+9;
    ll hashValue = 0;
    ll power = 1;

    for (int i = 0; i < n; i++) {
        hashValue = (hashValue + (s[i] - 'a' + 1) * power) % m;
        power = (power * p) % m;
    } 

    return hashValue;
}

// Función main para recibir input y llamar hashString
int main() { 
    string input;
    getline(cin, input);
    cout << hashString(input) << endl;
    return 0;
}