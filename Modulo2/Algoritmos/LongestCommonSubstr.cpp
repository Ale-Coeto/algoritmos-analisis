#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
 
#define MAXN 10
#define MOD 1000000007
 
void lcs(string & first, string & second) {
    vector<vi> common(first.length()+1, vi(second.length()+1, 0));
    int longest = 0;

    for (int i = 0; i < first.length(); i++) {
        for (int j = 0; j < second.length(); j++) {
            if (first[i] == second[j]) {
                common[i+1][j+1] = common[i][j]+1;
            } else {
                common[i+1][j+1] = max(common[i+1][j], common[i][j+1]);
            }
        }
    }

    string substr = "";
    int i = first.length()-1, j = second.length()-1;
    int index = common[first.length()][second.length()];
    
    while (i >= 0 && j >= 0) {
      if (first[i] == second[j]) {
        substr += first[i];
         i--;
         j--;
      } else if (common[i][j+1] > common[i+1][j])
         i--;
      else
         j--;
   }

   reverse(substr.begin(), substr.end());
   cout << "Length: " << common[first.length()][second.length()] << endl;
   cout << "Longest common substring: " << substr;

}

int main() { 
    string first, second;
    cin >> first >> second;

    lcs(first, second);
    return 0;
}
