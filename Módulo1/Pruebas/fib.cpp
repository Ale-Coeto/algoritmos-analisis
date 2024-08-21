#include <iostream>
#include <vector>
 
using namespace std;
#define pb push_back
typedef vector<int> vi;

int fib(int n) {
    vector<int> dp(n);
    dp[1] = 1;
    dp[2] = 1;

    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int main() { 
    int n;
    cin >> n;

    for (int i = 1; i < 10; i++) {
        cout << fib(i) << " ";
    }
    cout << fib(n);
    return 0;
}