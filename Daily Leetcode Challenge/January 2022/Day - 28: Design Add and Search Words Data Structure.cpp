// Time Complexity: O(N + 26^N)

class WordDictionary {
    struct node {
        char c;
        int end = 0;
        node* child[26];
    };
    
    node* getNode(char c) {
        node* newNode = new node;
        newNode->c = c;
        newNode->end = 0;
        for (int i = 0; i < 26; i++)
            newNode->child[i] = NULL;
        return newNode;
    }
    node* root = getNode('/');
    
    void Trie_insert(string s) {
        int index, i = 0;
        node* cur = root;
        
        while (s[i]) {
            index = s[i] - 'a';
            if (!cur->child[index])
                cur->child[index] = getNode(s[i]);
            cur = cur->child[index];
            i++;
        }
        cur->end += 1;
    }
    
    
    bool Trie_search(string s, node* curr, int pos, int n) {
        if (s[pos] == '.') {
            bool res = false;
            node* current = curr;
            for (int i = 0; i < 26; i++) {
                if (pos == n - 1 && curr->child[i]) {
                    current = curr->child[i];
                    res |= current->end > 0 ? true : false;
                } else if (curr->child[i] && Trie_search(s, curr->child[i], pos + 1, n))
                    return true;
            }
            
            return res;
        } else if (curr->child[s[pos] - 'a']) {
            if (pos == n - 1) {
                curr = curr->child[s[pos] - 'a'];
                return curr->end > 0 ? true : false;
            }
            return Trie_search(s, curr->child[s[pos] - 'a'], pos + 1, n);
        }
        return false;
    }
    
    
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        Trie_insert(word);
    }
    
    bool search(string word) {
        return Trie_search(word, root, 0, word.size());
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */




