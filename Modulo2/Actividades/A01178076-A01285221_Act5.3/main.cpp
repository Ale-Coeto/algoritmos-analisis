// Oscar Arreola (A01178076) y Alejandra Coeto (A01285221)
// Última modificación: Jueves 24 de noviembre
// Programa para resolver el problema N Queens usando backtracking con poda pesada

#include "libs.h"
#define pb push_back 
using namespace std;
typedef vector<int> vi;

vector<vector<int>> solution;
bool flag = false;

/*
    Función para checar si el tablero actual es válido
    Complejidad: O(n)
*/

bool possible(vector<vector<int>> &curr, int ib, int jb) {
    int count = 0;
    for (int i = 0; i < curr.size(); i++) {
        if (curr[i][jb] == 1)
            count++;
    }

    if (count != 1) return false;

    count = -1;

    int index = jb;
    for (int i = ib; i >= 0; i--) {
        if (jb >= 0 && curr[i][jb] == 1) 
            count++;
        jb--;

        if (index < curr.size() && curr[i][index++] == 1)
            count++;
    }

    if (count != 1) return false;

    return true;
}  

/*
    Función para realizar el backtracking (agregar una reina y checar si esa posición es posible)
    Complejidad: O(n!)
*/
void bt(int n, int queens, vector<vector<int>> &curr, int ib, int jb) {
    if (flag) return;
    if (queens == n) {
        solution = curr;
        flag = true;
        return;
    }
    
    if (ib >= n) return;

    for (int j = 0; j < n; j++) {
        curr[ib][j] = 1;

        if (possible(curr, ib, j)) {   
            bt(n, queens+1, curr, ib+1, j);
        }
        
        curr[ib][j] = 0;
    }

}
 
/*
    Función principal para recibir input e imprimir el resultado
*/
int main() {
    int n;
    cin >> n;

    vector<vector<int>> curr(n, vector<int>(n,0));
    bt(n,0,curr,0,0);

    for (auto i : solution) {
        for (auto x : i) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}