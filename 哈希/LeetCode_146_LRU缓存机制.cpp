#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>

using namespace std;

class LRUCache {
public:
    int _capacity;
    int _size;
    list<int> bidirectionList;
    unordered_map<int, pair<int, list<int>::iterator>> hashMap; //key value List::ite
    
    LRUCache(int capacity) 
    :_capacity(capacity)
    {
        //cout << "chushihua" << endl;
        _size = 0;
        //cout << "chu shi hua wan cheng " << endl;
    }
    
    int get(int key) 
    {
        //cout << "get " << endl;
        if (hashMap.find(key) == hashMap.end())
            return -1;
        bidirectionList.erase(hashMap[key].second);
        bidirectionList.push_front(key);
        hashMap[key].second = bidirectionList.begin();
        
        //cout << "get done " << endl;
        return hashMap[key].first;

    }
    
    void put(int key, int value) 
    {
        //cout << "put " << endl;
        if (hashMap.find(key) == hashMap.end())
        {
            if (_size < _capacity)
            {
                bidirectionList.push_front(key);
                hashMap[key] = make_pair(value, bidirectionList.begin());
                _size++;
            }
            else  
            {
                hashMap.erase(bidirectionList.back());
                bidirectionList.pop_back();
                bidirectionList.push_front(key);
                hashMap[key] = make_pair(value, bidirectionList.begin());
            }
        }
        else  
        {
            bidirectionList.erase(hashMap[key].second);
            bidirectionList.push_front(key);
            hashMap[key].second = bidirectionList.begin();
            hashMap[key].first = value;
        }
        //cout << "put done " << endl;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */