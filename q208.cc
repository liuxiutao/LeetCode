#include<iostream>

using namespace std;

class Trie {
    struct TrieNode{
        char c;
        TrieNode * parent;
        TrieNode * child;
        TrieNode * brother;
        TrieNode(): parent(nullptr), child(nullptr), brother(nullptr){}
        TrieNode(char cc, TrieNode * par = nullptr, TrieNode * bro = nullptr): c(cc), parent(par), child(nullptr), brother(bro){}
    };
    
    TrieNode * root;
    
    TrieNode * levelSearch(TrieNode * lp, char c)
    {
        while(lp != nullptr)
        {
            if(lp->c == c)
                break;
            lp = lp->brother;
        }
        return lp;
    }
    
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();     
        root->child = new TrieNode('\n', root);
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode * cur = root->child;
        TrieNode * par = root;
        int len = word.size();
        for(int i = 0; i < len; i++)
        {
            TrieNode * res = nullptr;
            if((res = levelSearch(cur, word[i])) == nullptr)//没找到，插在头部
            {
                TrieNode * tmp = new TrieNode(word[i], par);
                if(cur != nullptr)
                {
                    tmp->brother = cur->brother;
                    cur->brother = tmp;
                }
                else
                {
                    par->child = tmp;
                }
                par = tmp;
                cur = tmp->child;
            }
            else
            {
                par = res;
                cur = res->child;
            }
        }
        if(levelSearch(cur, '\n') == nullptr)
        {
            par->child = new TrieNode('\n', par, cur);
        }
             
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int len = word.size();
        TrieNode * cur = root->child;
        for(int i = 0; i < len; i++)
        {
            if((cur = levelSearch(cur, word[i])) == nullptr)
                return false;
            cur = cur->child;
        }
        if((cur = levelSearch(cur, '\n')) == nullptr)
                return false;
        return true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int len = prefix.size();
        TrieNode * cur = root->child;
        for(int i = 0; i < len; i++)
        {
            if((cur = levelSearch(cur, prefix[i])) == nullptr)
                return false;
            cur = cur->child;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Trie trie;
    trie.insert("apple");
    cout << trie.search("apple") << endl; // returns true
    cout << trie.search("app") << endl;     // returns false
    cout << trie.startsWith("app") << endl; // returns true
    trie.insert("app");   
    cout << trie.search("app") << endl;     // returns true
    return 0;
}
