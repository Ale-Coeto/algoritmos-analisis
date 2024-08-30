#include <iostream>
#include <vector>
 
using namespace std;
typedef vector<int> vi;
#define pb push_back
#define MAX 10000000000

vector<long long> dp1(MAX, -1);
long long done = 1;

int combination(int n, int r) {
    // Create a 2D table to store results of subproblems
    vector<vector<int> > dp(n + 1, vector<int>(r + 1, 0));
    
    // Base case: C(n, 0) = 1 for all n
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 1;
    }
    
    // Build the table in bottom-up manner
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= std::min(i, r); ++j) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
    
    return dp[n][r];
}

long long factorial(long long n) {
    if (dp1[n] != -1) {
        return dp1[n];
    }

    for (int i = done+1; i <= n; i++) {
        dp1[i] = dp1[i-1] * i;
    }

    done = n;
    return dp1[n];
}

int combinaciones(int n, int k) {
    return (factorial(n) / (factorial(n-k) * factorial(k)));
}

int main() { 
    dp1[1] = 1;
    cout << combination(35,3);

    return 0;
}
