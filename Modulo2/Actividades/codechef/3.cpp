#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <utility>
#include <vector>
#include <unordered_set>
#include <unordered_map>
 
#define PI 3.141592653589793
#define EPS 0.000000001
#define INF 1000000000
 
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define RFOR(i, a, b) for(int i=int(a)-1; i>=int(b); i--)
#define FORC(cont, it) for(typeof((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define RFORC(cont, it) for(typeof((cont).rbegin()) it = (cont).rbegin(); it != (cont).rend(); it++)
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
 
#define MAXN 10
#define MOD 1000000007
 
int main() { _
    int n;
    vi asteroids;

    while (cin >> n) {
        asteroids.pb(n);
    }

    stack<int> s;
    s.push(asteroids[0]);

    for (int i = 1; i < asteroids.size(); i++) {
        bool flag = false;


        while (!s.empty() && (asteroids[i] < 0 && s.top() > 0) || (asteroids[i] > 0 && s.top() < 0)) {
            if (abs(asteroids[i]) > abs(s.top())) {
                s.pop();
            } else if (abs(asteroids[i]) == abs(s.top())) {
                s.pop();
                flag = true;
                break;
               } else {
                break;
            }
        }

        if ((s.empty() && !flag) || (!s.empty() && asteroids[i] > 0 && s.top() > 0) || (!s.empty() && asteroids[i] < 0 && s.top() < 0)) {
            s.push(asteroids[i]);
        }
    }

    vi ans;
    while (!s.empty()) {
        ans.pb(s.top());
        s.pop();
    }


    for (auto x : ans) {
        cout << x << " ";
    }

  

    

    

    return 0;
}