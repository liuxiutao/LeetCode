#include<iostream>
#include<vector>
#include<string>

using namespace std;

class WordDictionary {
    struct node
    {
        bool isExist;
        vector<node> * next;
        node(){isExist = false; next = nullptr;}
        node(bool isExist): isExist(isExist){next = new vector<node>(27, node());}
    };
    vector<node> * root;

    bool func_s(string &word, int i, vector<node> * cur)
    {
        if( i == word.length())
        {
            return cur->rbegin()->isExist;
        }

        if(word[i] == '.')
        {
            bool res = false;
            auto it = cur->begin();
            for(; it != cur->end(); it++)
            {
                if(it->isExist && it->next != nullptr)
                    res = res || func_s(word, i + 1, it->next);
            }
            return res;
        }
        
        return (*cur)[word[i] - 'a'].isExist && func_s(word, i+1, (*cur)[word[i] - 'a'].next);
    }
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new vector<node>(27, node());
        (*root)[26].isExist = true;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        vector<node> * cur = root;
        for(int i = 0; i < word.length(); i++)
        {
            if((*cur)[word[i] - 'a'].isExist)
                cur = (*cur)[word[i] - 'a'].next;
            else{
                for(int j = i; j < word.length(); j++)
                {
                    (*cur)[word[j] - 'a'].isExist = true;
                    (*cur)[word[j] - 'a'].next = new vector<node>(27, node());
                    cur = (*cur)[word[j] - 'a'].next;
                }   
                break;
            }
        }

        cur->back().isExist = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return func_s(word, 0, root);
    }
};

int main()
{
    WordDictionary* obj = new WordDictionary();
    obj->addWord("bad");
    obj->addWord("dad");
    obj->addWord("mad");
    cout << obj->search("pad") << endl;
    cout << obj->search("bad") << endl;
    cout << obj->search(".ad") << endl;
    cout << obj->search("b..") << endl;
    return 0;
}