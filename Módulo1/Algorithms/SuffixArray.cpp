// Oscar Arreola (A01178076) y Alejandra Coeto (A01285221)
// Última modificación: Jueves 15 de Agosto
// Programa para probar la implementación del algoritmo MergeSort

#include <iostream>
#include <vector>
#include <stdio.h>
 
using namespace std;
typedef vector<int> vi;
#define pb push_back

// Función para obtener el suffix array de un string
// Recibe un string
// Retorna el suffix array (vector<int>)
vector<int> suffixArrayNaive(string s) {
    int n = s.length() + 1;
    vector<string> sa;
    vector<int> A(n);
    s += "$";

    for (int i = 0; i < n; i++) {
        sa.pb(s.substr(n-i-1, i+1));
    }

    sort(sa.begin(), sa.end());

    for (int i = 0; i < n; i++) {
        A[i] = n - sa[i].size() + 1;
    }

    return A;
}

// Función main para recibir input y llamar suffixArrayNaive
int main() { 
    string input;
    getline(cin, input);

    vi result = suffixArrayNaive(input);
    
    for (int x : result) {
        cout << x << endl;
    }

    return 0;
}