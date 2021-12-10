#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class CQueue {
public:
    stack<int> t1;
    stack<int> t2;
    CQueue() {

    }
    
    void appendTail(int value) {
        t1.push(value);
    }
    
    int deleteHead() {

        
        if (t2.empty())
        {
            while (!t1.empty())
            {
                t2.push(t1.top());
                t1.pop();
            }
        }

        if (t2.empty()) return -1;
        

        int res = t2.top();
        t2.pop();

    
        return res;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */