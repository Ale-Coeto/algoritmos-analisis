#include <iostream>
#include <vector>
#include "Trie.h"
 
using namespace std;
typedef vector<int> vi;
#define pb push_back

int main() { 
    int n,m;
    string word;
    vector<string> words;
    cin >> n;
    Trie trie;

    while (n--) {
        cin >> word;
        trie.insert(word);
    }

    cin >> m;

    while (m--) {
        cin >> word;
        cout << trie.search(word) << endl;
    }

    return 0;
}