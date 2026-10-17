class TrieNode {
public:
    TrieNode *children[26];
    bool endOfWord;

    TrieNode() {
        for (int i = 0; i < 26; i++) children[i] = nullptr;
        endOfWord = false;
    }
};

class WordDictionary {
    TrieNode *root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *cur = root;
        for (char c : word) {
            int i = c - 'a';
            if (cur->children[i] == nullptr) {
                cur->children[i] = new TrieNode();
            }
            cur = cur->children[i];
        }
        cur->endOfWord = true;
    }
    
    bool search(string word) {
        return search2(word, 0, root);
    }

    bool search2(string &word, int i, TrieNode *cur) {
        for (; i < word.length(); i++) {
            if (word[i] == '.') {
                for (int k = 0; k < 26; k++) {
                    if (cur->children[k] != nullptr && search2(word, i + 1, cur->children[k])) {
                        return true;
                    }
                }
                return false;
            }
            int j = word[i] - 'a';
            if (cur->children[j] == nullptr) return false;
            cur = cur->children[j];
        }
        return cur->endOfWord;
    }
};
