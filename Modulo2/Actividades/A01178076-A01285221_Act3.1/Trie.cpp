// Oscar Arreola (A01178076) y Alejandra Coeto (A01285221)
// Última modificación: Domingo 6 de Octubre
// Programa para hacer pruebas de la implementación de un Trie

// Las complejidades temporales de las funciones se encuentran en la implementación de la clase.

#include <iostream>
#include <vector>
#include "Trie.h"

using namespace std;
typedef vector<int> vi;
#define pb push_back

int main()
{
    // Leer las entradas
    int n, m;
    vector<string> words, queries;

    cin >> n;
    Trie trie;

    while (n--)
    {
        string word;
        cin >> word;
        trie.insert(word);
    }

    cin >> m;

    while (m--)
    {
        string word;
        cin >> word;
        queries.push_back(word);
    }

    // Imprimir todas las palabras insertadas en el trie
    vector<string> insertedWords = trie.getInsertedWords();

    for (auto word : insertedWords)
    {
        cout << word << endl;
    }

    cout << endl;

    // Buscar las palabras en el trie
    for (auto query : queries)
    {
        if (trie.search(query))
        {
            cout << "1" << endl;
        }
        else
        {
            cout << "0" << endl;
        }
    }

    return 0;
}