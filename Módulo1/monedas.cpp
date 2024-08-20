#include <iostream>
#include <vector>
 
using namespace std;
typedef vector<int> vi;
#define pb push_back

int main() { 
    int n,a;
    vector<int> monedas;
    cout << "Ingrese el número de denominaciones de monedas: ";
    cin >> n;
    cout << "Ingrese las denominaciones de las monedas, una por línea: \n";
    for (int i = 0; i < n; i++) {
        cin >> a;
        monedas.pb(a);
    }
    cout << "Ingrese el precio del producto: ";
    cin >> p;
    cout << "Ingrese la cantidad pagada: 500";
    return 0;
}