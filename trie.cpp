#include <iostream>
#include <unordered_map>
using namespace std;

// Trie node structure
class TrieNode {
public:
    unordered_map<char, TrieNode*> children; // Children of each node
    bool isEndOfWord; // True if the node represents the end of a word
    
    // Constructor to initialize a Trie node
    TrieNode() {
        isEndOfWord = false;
    }
};

// Trie class
class Trie {
private:
    TrieNode* root; // Root of the Trie
    
public:
    // Constructor to initialize the Trie
    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the Trie
    void insert(string word) {
        TrieNode* current = root;
        for (char ch : word) {
            // If the character is not present, add a new node
            if (current->children.find(ch) == current->children.end()) {
                current->children[ch] = new TrieNode();
            }
            current = current->children[ch];
        }
        current->isEndOfWord = true;
    }

    // Search for a word in the Trie
    bool search(string word) {
        TrieNode* current = root;
        for (char ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                return false; // Character not found
            }
            current = current->children[ch];
        }
        return current->isEndOfWord; // Check if it's the end of a valid word
    }

    // Check if any word in the Trie starts with the given prefix
    bool startsWith(string prefix) {
        TrieNode* current = root;
        for (char ch : prefix) {
            if (current->children.find(ch) == current->children.end()) {
                return false;
            }
            current = current->children[ch];
        }
        return true; // Prefix found
    }
};

// Driver code to test the Trie
int main() {
    Trie trie;
    trie.insert("apple");
    cout << trie.search("apple") << endl;    // Returns true
    cout << trie.search("app") << endl;      // Returns false
    cout << trie.startsWith("app") << endl;  // Returns true
    trie.insert("app");
    cout << trie.search("app") << endl;      // Returns true
    return 0;
}
