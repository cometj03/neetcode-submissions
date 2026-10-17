class Node {
public:
    Node *children[26];
    bool endOfWord;

    Node() {
        for (int i = 0; i < 26; i++) children[i] = nullptr;
        endOfWord = false;
    }
};

class PrefixTree {
private:
    Node *root;
public:
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *node = root;
        for (char c : word) {
            int i = c - 'a';
            if (node->children[i] == nullptr) {
                node->children[i] = new Node();
            }
            node = node->children[i];
        }
        node->endOfWord = true;
    }
    
    bool search(string word) {
        Node *node = root;
        for (char c : word) {
            int i = c - 'a';
            if (node->children[i] == nullptr) return false;
            node = node->children[i];
        }
        return node->endOfWord;
    }
    
    bool startsWith(string prefix) {
        Node *node = root;
        for (char c : prefix) {
            int i = c - 'a';
            if (node->children[i] == nullptr) return false;
            node = node->children[i];
        }
        return true;
    }
};
