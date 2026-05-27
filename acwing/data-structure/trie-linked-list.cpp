// class Trie {
//     int son[300000][26] = {0}, cnt[300000] = {0}, idx = 0;
// public:
//     Trie() {}
    
//     void insert(string word) {
//         int p = 0;
//         for (int i = 0; i < word.size(); i++)
//         {
//             int u = word[i] - 'a';
//             if (!son[p][u]) son[p][u] = ++idx;
//             p = son[p][u];
//         }
//         cnt[p]++;
//     }
    
//     bool search(string word) {
//         int p = 0;
//         for (int i = 0; i < word.size(); i++)
//         {
//             int u = word[i] - 'a';
//             if (!son[p][u]) return false;
//             p = son[p][u];
//         }
//         return cnt[p] > 0;
//     }
    
//     bool startsWith(string prefix) {
//         int p = 0;
//         for (int i = 0; i < prefix.size(); i++)
//         {
//             int u = prefix[i] - 'a';
//             if (!son[p][u]) return false;
//             p = son[p][u];
//         }
//         return true;
//     }
// };





// class Trie {
// private:
//     Trie* next[26];
//     bool isEnd;
// public:
//     Trie() {
//         memset(next, 0, sizeof(next));
//         isEnd = false;        
//     }
    
//     void insert(string word) {
//         Trie* node = this;
//         for (char c : word)
//         {
//             if (node->next[c-'a'] == NULL) node->next[c-'a'] = new Trie();           
//             node = node->next[c-'a'];
//         }
//         node->isEnd = true;
//     }
    
//     bool search(string word) {
//         Trie* node = this;
//         for (char c : word)
//         {
//             node = node->next[c - 'a'];
//             if (node == NULL) return false;           
//         }
//         return node->isEnd;
//     }
    
//     bool startsWith(string prefix) {
//         Trie* node = this;
//         for (char c : prefix)
//         {
//             node = node->next[c-'a'];
//             if (node == NULL) return false;
//         }
//         return true;
//     }
// };





// class Trie {
// private:
//     vector<Trie*> children;
//     bool isEnd;

//     Trie* searchPrefix(string prefix)
//     {
//         Trie* node = this;
//         for (char p : prefix)
//         {
//             p -= 'a';
//             if (node->children[p] == nullptr) return nullptr;
//             node = node->children[p];
//         }
//         return node;
//     }
// public:
//     Trie() : children(26), isEnd(false) {}
//     // Trie() {
//     //     children.resize(26);
//     //     // children = vector<Trie*>(26, nullptr);
//     //     isEnd = false;
//     // }

//     ~Trie() {for (Trie* child : children) delete child;}

//     void insert(string word) {
//         Trie* node = this;
//         for (char w : word)
//         {
//             w -= 'a';
//             if (node->children[w] == nullptr) node->children[w] = new Trie();
//             node = node->children[w];
//         }
//         node->isEnd = true;
//     }
    
//     bool search(string word) {
//         Trie* node = this->searchPrefix(word);
//         return node != nullptr && node->isEnd;
//     }
    
//     bool startsWith(string prefix) {
//         return this->searchPrefix(prefix) != nullptr;
//     }
// };





// struct Node {
//     Node* son[26]{};
//     bool end = false;
// };

// class Trie {
//     Node* root = new Node();

//     int find(string word) {
//         Node* cur = root;
//         for (char c : word) {
//             c -= 'a';
//             if (cur->son[c] == nullptr) { // 道不同，不相为谋
//                 return 0;
//             }
//             cur = cur->son[c];
//         }
//         // 走过同样的路（2=完全匹配，1=前缀匹配）
//         return cur->end ? 2 : 1;
//     }

//     void destroy(Node* node) {
//         if (node == nullptr) {
//             return;
//         }
//         for (Node* son : node->son) {
//             destroy(son);
//         }
//         delete node;
//     }

// public:
//     ~Trie() {
//         destroy(root);
//     }

//     void insert(string word) {
//         Node* cur = root;
//         for (char c : word) {
//             c -= 'a';
//             if (cur->son[c] == nullptr) { // 无路可走？
//                 cur->son[c] = new Node(); // new 出来！
//             }
//             cur = cur->son[c];
//         }
//         cur->end = true;
//     }

//     bool search(string word) {
//         return find(word) == 2;
//     }

//     bool startsWith(string prefix) {
//         return find(prefix) != 0;
//     }
// };
