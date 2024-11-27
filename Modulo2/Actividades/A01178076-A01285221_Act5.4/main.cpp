// Oscar Arreola (A01178076) y Alejandra Coeto (A01285221)
// Última modificación: Martes 26 de noviembre
// Programa para resolver el problema Meet in the middle usando backtracking 

#include "libs.h"
#define pb push_back 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll ans = 0;
/*
    Función de backtracking para probar todas las combinaciones donde 
    la suma sea menor a s
    Complejidad: O(2^n)
*/
void bt(vll & nums, ll & s, ll & current, int index) {
    if (index == nums.size()) {
        ans = max(ans, current);
        return;
    }

    for (int i = index; i < nums.size(); i++) {
        if (current + nums[i] <= s) {
            current = current + nums[i];
            bt(nums, s, current, i+1);
            current = current - nums[i];
        } else {
            ans = max(ans, current);
        }
    }
}

/*
    Función main para recibir input e imprimir la respuesta
*/
int main() {
    int n;
    ll s,a;
    cin >> n >> s;
    
    vll input;
    while (n--) {
        cin >> a;
        input.pb(a);
    }

    ll c = 0;
    bt(input, s, c, 0);

    cout << ans;

    return 0;
}