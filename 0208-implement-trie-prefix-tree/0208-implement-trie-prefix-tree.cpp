class Trie {
public:
    const static int ROOT = 0;
    int last = 1;
    vector<bool> mark;
    vector<vector<int>> tree;
    Trie() {
        mark.push_back(false);
        tree.push_back(vector<int>(26, -1));
    }
    
    void insert(string word) {
        int n = ROOT;
        for (auto c : word)
        {
            if (tree[n][c2i(c)] == -1)
            {
                mark.push_back(false);
                tree.push_back(vector<int>(26, -1));
                tree[n][c2i(c)] = last++;
            }
            n = tree[n][c2i(c)];
        }
        mark[n] = true;
    }
    
    bool search(string word) {
        int n = ROOT;
        for (auto c : word)
        {
            if (tree[n][c2i(c)] == -1)
                return false;
            n = tree[n][c2i(c)];
        }
        return mark[n];
    }
    
    bool startsWith(string prefix) {
        int n = ROOT;
        for (auto c : prefix)
        {
            if (tree[n][c2i(c)] == -1)
                return false;
            n = tree[n][c2i(c)];
        }
        return true;
    }
    
    int c2i(char c)
    {
        return c - 'a';
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */