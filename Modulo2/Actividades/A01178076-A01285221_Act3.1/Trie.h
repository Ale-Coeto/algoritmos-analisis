// Oscar Arreola (A01178076) y Alejandra Coeto (A01285221)
// Última modificación: Domingo 6 de Octubre
// Programa para implementar un Trie y buscar palabras en él.

// La implementación cuenta con dos clases, TrieNode y Trie. La primera es una clase que representa un nodo del Trie, y la segunda es una clase que representa el Trie en sí.

#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

#define pb push_back

// Clase TrieNode, representa un nodo del Trie.
class TrieNode
{
public:

    // Complejidad temporal: O(1), ya que se inicializa un vector de 26 elementos.
    TrieNode(char c, TrieNode *p = nullptr)
    {
        parent = p;
        letter = c;
        end = false;
        // La clase soporta el abecedario en letras minúsculas, por lo que se inicializa un vector de 26 elementos, cada uno representando una letra del abecedario.
        // Otra implementación podría ser un unordered_map<char, TrieNode*> child, para soportar cualquier tipo de letra.
        // Sin embargo, el vector es más eficiente en términos de memoria y tiempo de ejecución,
        // por lo que se eligió esta implementación ya que se sabe que solo se usarán letras minúsculas.
        child.resize(26, nullptr);
    }

    // Función para obtener un hijo del nodo actual.
    // Complejidad temporal: O(1), ya que se accede a un elemento de un vector.
    TrieNode *getChild(char c)
    {
        return child[c - 'a'];
    }

    // Función para agregar un hijo al nodo actual.
    // Complejidad temporal: O(1), ya que se accede a un elemento de un vector.
    void addChild(TrieNode *node)
    {
        child[node->letter - 'a'] = node;
    }

    // Getter para saber si el nodo actual es el final de una palabra.
    // Complejidad temporal: O(1), ya que solo se accede a una variable miembro.
    bool isEnd() { return end; }

    // Setter para marcar el nodo actual como final de una palabra.
    // Complejidad temporal: O(1), ya que solo se modifica una variable miembro.
    void setEnd(bool val) { end = val; }

private:
    char letter;
    bool end;
    TrieNode *parent;
    vector<TrieNode *> child;
};

// Clase Trie, representa el Trie en sí.
class Trie
{
public:
    Trie()
    {
        // Se inicializa el Trie con un nodo raíz que no contiene ninguna letra.
        root = new TrieNode('\0');
    }

    // Función para insertar una palabra en el Trie/
    // Complejidad temporal: O(n), donde n es la longitud de la palabra a insertar.
    void insert(string word)
    {
        TrieNode *current = root;
        for (char c : word)
        {
            // Si el nodo actual no tiene un hijo con la letra c, se agrega un nuevo nodo con la letra c.
            if (current->getChild(c) == nullptr)
            {
                current->addChild(new TrieNode(c, current));
            }
            current = current->getChild(c);
        }
        // Al finalizar de insertar la palabra, se marca el nodo actual como final de una palabra.
        current->setEnd(true);
    }

    // Retorna verdadero si la palabra fue insertada en el trie.
    // Complejidad temporal: O(n), donde n es la longitud de la palabra a buscar.
    bool search(string word)
    {
        TrieNode *current = root;
        for (char c : word)
        {
            current = current->getChild(c);
            if (current == nullptr)
            {
                return false;
            }
        }
        return current->isEnd();
    }

    // Retorna todas las palabras insertadas en el trie. Se retornan en orden lexicográfico (ya que se recorre el trie en orden).
    // Complejidad temporal: O(n), donde n es número de nodos en el trie.
    vector<string> getInsertedWords()
    {
        vector<string> words;
        vector<char> current;
        searchAllWords(words, current, root);

        return words;
    }

private:
    TrieNode *root;

    // Método auxiliar para buscar todas las palabras en el trie.
    // Complejidad temporal: O(n), donde n es número de nodos en el trie.
    void searchAllWords(vector<string> &words, vector<char> &current, TrieNode *node)
    {
        // Agregar palabra actual a vector de palabras
        if (node->isEnd())
        {
            string word(current.begin(), current.end());
            words.push_back(word);
        }

        // Recorrer todos los hijos del nodo actual
        for (auto c = 'a'; c <= 'z'; c++)
        {
            if (node->getChild(c) != nullptr)
            {
                current.push_back(c); // Insertar letra en palabra actual
                searchAllWords(words, current, node->getChild(c));
                current.pop_back(); // Remover última letra de la palabra actual

            }
        }
    }
};