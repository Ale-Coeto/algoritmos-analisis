#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

 
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define pb push_back
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
 
 
vi solve(vector<vi> & matrix) {
    int left = 0, right = matrix[0].size()-1, bottom = matrix.size()-1, top = 0;
    int size = matrix.size()*matrix[0].size();
    int done = 0;
    vi ans;

    while (left <= right && top <= bottom) {
        for (int i = left; i <= right && done < size; i++) {
            ans.pb(matrix[top][i]);
            done++;
        }
        top++;

        for (int j = top; j <= bottom && done < size; j++) {
            ans.pb(matrix[j][right]);
            done++;
        }
        right--;

        for (int i = right; i >= left && done < size; i--) {
            ans.pb(matrix[bottom][i]);
            done++;
        }
        bottom--;

        for (int j = bottom; j >= top && done < size; j--) {
            ans.pb(matrix[j][left]);
            done++;
        }
        left++;
    }
    cout << endl;
    return ans;


}

int main() { _
    int n,m,a;
    cin >> n >> m;
    vector<vi> matrix(n,vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a;
            matrix[i][j] = a;
        }
    }

    vi ans = solve(matrix);

    for (int x : ans) {
        cout << x << " ";
    }

    cout << endl;
    
    return 0;
}