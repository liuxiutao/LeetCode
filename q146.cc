#include<iostream>
#include<unordered_map>

using namespace std;

class LRUCache {
    int capacity;
    
    struct Node{
        int key;
        int val;
        Node * next;
        Node * pre;
        Node(int k = -1, int v = -1):key(k), val(v), next(nullptr), pre(nullptr){}
    };
    Node * head;
    Node * tail;
    
    unordered_map<int, Node *> mp;
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = tail = new Node;
    }
    
    int get(int key) {
        if(mp.count(key) == 0)
            return -1;
        else
        {
            Node * tmp = mp[key];
            if(tmp == head->next)
            {
                return tmp->val;
            }
            else if(tmp == tail)
            {
                tail = tmp->pre;
                tail->next = nullptr;
                
                tmp->next = head->next;
                tmp->pre = head;
                head->next->pre = tmp;
                head->next = tmp;
                return tmp->val;
            }
            else
            {
                tmp->next->pre = tmp->pre;
                tmp->pre->next = tmp->next;
                
                tmp->next = head->next;
                tmp->pre = head;
                head->next->pre = tmp;
                head->next = tmp;
                return tmp->val;
            }
        }
    }
    
    void put(int key, int value) {
        if(get(key) == -1)
        {
            if(mp.size() == capacity)
            {
                Node * tmp = tail;
                tail = tail->pre;
                tail->next = nullptr;
                tmp->pre = nullptr;
                mp.erase(tmp->key);
                delete tmp;
            }
            Node * tmp = new Node(key, value);
            mp[key] = tmp;

            tmp->next = head->next;
            tmp->pre = head;
            if(tail == head)
            {
                tail = tmp;
            }
            else
            {                
                head->next->pre = tmp;
            }
            head->next = tmp;
        }
        else
        {
            head->next->val = value;
        }
    }
};

int main()
{
    LRUCache cache( 2 );

    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;       // returns 1
    cache.put(3, 3);    // evicts key 2
    cout << cache.get(2) << endl;       // returns -1 (not found)
    cache.put(4, 4);    // evicts key 1
    cout << cache.get(1) << endl;       // returns -1 (not found)
    cout << cache.get(3) << endl;       // returns 3
    cout << cache.get(4) << endl;       // returns 4
    return 0;
}