/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
*/

/////////////////////////////////////////////////////////////////////////////////////


struct mylist
{
    int key;
    int value;
    mylist * next;
    mylist * prior;
    mylist(){
        key = 0;
        value = 0;
        next = NULL;
        prior = NULL;
    }
};

class LRUCache{
private:
    int cap;
    int size;
    mylist * cache;
    mylist * tail;
    map< int, mylist* > keymap;
    
public:
    LRUCache(int capacity) {
        cap = capacity;
        cache = new mylist();
        tail = new mylist();
        cache->next = tail;
        tail->prior = cache;
        size = 0;
    }
    
    int get(int key) {
        map< int, mylist* >::iterator itr = keymap.find( key );
        if ( itr != keymap.end() ) {
            mylist * tmp = itr->second;
            tmp->prior->next = tmp->next;
            tmp->next->prior = tmp->prior;
            cache->next->prior = tmp;
            tmp->next = cache->next;
            tmp->prior = cache;
            cache->next = tmp;
            return itr->second->value;
        }
        return -1;
    }
    
    void set(int key, int value) {
        map< int, mylist* >::iterator itr = keymap.find( key );
        if ( itr != keymap.end() ) {
            mylist * tmp = itr->second;
            tmp->value = value;
            tmp->prior->next = tmp->next;
            tmp->next->prior = tmp->prior;
            cache->next->prior = tmp;
            tmp->next = cache->next;
            tmp->prior = cache;
            cache->next = tmp;
        } else {
            if ( size >= cap ) {
                mylist * tmp = tail->prior;
                itr = keymap.find( tmp->key );
                keymap.erase( itr );
                keymap.insert( make_pair( key, tmp ) );
                tmp->key = key;
                tmp->value = value;
                tmp->prior->next = tmp->next;
                tmp->next->prior = tmp->prior;
                cache->next->prior = tmp;
                tmp->next = cache->next;
                tmp->prior = cache;
                cache->next = tmp;
            } else {
                mylist * tmp = new mylist();
                tmp->key = key;
                tmp->value = value;
                keymap.insert( make_pair( key, tmp ) );
                cache->next->prior = tmp;
                tmp->next = cache->next;
                tmp->prior = cache;
                cache->next = tmp;
                ++ size;
            }
        }
    }
};
