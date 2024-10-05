#include <iostream>
#include <vector>
 
using namespace std;
typedef vector<int> vi;
#define pb push_back

class TrieNode {
public:
    TrieNode(char c, TrieNode* p = nullptr) {
        parent = p;
        letter = c;
        end = false;
        child.resize(26, nullptr);  
    }

    TrieNode* getChild(char c) { 
        return child[c - 'a']; 
    }

    void addChild(TrieNode* node) { 
        child[node->letter - 'a'] = node; 
    }

    bool isEnd() { return end; }
    void setEnd(bool val) { end = val; }

private:
    char letter;
    bool end;
    TrieNode* parent;
    vector<TrieNode*> child;  
};

class Trie {
public:
    Trie() {
        root = new TrieNode('\0'); 
    }

    void insert(string word) {
        TrieNode* current = root;
        for (char c : word) {
            if (current->getChild(c) == nullptr) {
                current->addChild(new TrieNode(c, current));
            }
            current = current->getChild(c);
        }
        current->setEnd(true);
    }

    bool search(string word) {
        TrieNode* current = root;
        for (char c : word) {
            current = current->getChild(c);
            if (current == nullptr) {
                return false;
            }
        }
        return current->isEnd();
    }

private:
    TrieNode* root;
};